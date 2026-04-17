// mel_spectrogram.c
#include "mel_spectrogram.h"
#include "arm_math.h"
#include "mel_filterbank.h"
#include <stdint.h>
#include <string.h>

// NEED TO INCLUDE ON STM32 BOARD LATER using installed libraries
// #include "arm_math.h" // CMSIS-DSP library header provided by ARM
// #include "arm_const_structs.h" // CMSIS-DSP library constants

#define LOG10_OFFSET 1e-10f
#define TOP_DB 80.0f

static MelSpectrogramConfig_t cfg;

// USE FOR STM32
static arm_rfft_fast_instance_f32 fft_instance;
// internal buffers
static float window_buffer[MAX_FFT_SIZE];
// __attribute__((section(".sdram_data")))
static float mel_filters[MAX_MEL_BANDS * (MAX_FFT_SIZE / 2 + 1)];

int mel_spectrogram_init(MelSpectrogramConfig_t *config)
{
    if (!config)
        return -1;
    memcpy(&cfg, config, sizeof(MelSpectrogramConfig_t));

    if (cfg.fft_size > MAX_FFT_SIZE || cfg.n_mels > MAX_MEL_BANDS)
        return -1;

    if (arm_rfft_fast_init_f32(&fft_instance, cfg.fft_size) != ARM_MATH_SUCCESS)
        return -2;

    // STM32 , called in mel_filterbank.c
    // arm_rfft_fast_init_f32(&fft_instance, cfg.fft_size);

    // create Hann window
    for (int i = 0; i < cfg.fft_size; ++i)
    {
        window_buffer[i] = 0.5f * (1.0f - arm_cos_f32(2.0f * PI * i / (cfg.fft_size - 1)));
    }

    // create Mel filterbank
    create_mel_filterbank(mel_filters, cfg.n_mels, cfg.fft_size, cfg.sample_rate, cfg.f_min,
                          cfg.f_max);

    return 0;
}

// Helper: get a PCM sample with reflect padding for center=True behavior.
// The signal is conceptually padded by n_fft/2 on each side using reflect mode.
static inline float get_padded_sample(const int16_t *pcm_data, uint32_t pcm_size,
                                       int32_t idx, uint16_t pad)
{
    int32_t src = idx - pad;  // shift back by pad amount

    // reflect padding (mirrors at boundaries, matching torch "reflect" mode)
    if (src < 0)
        src = -src;
    else if (src >= (int32_t)pcm_size)
        src = 2 * (int32_t)pcm_size - src - 2;

    if (src < 0 || src >= (int32_t)pcm_size)
        return 0.0f;

    return pcm_data[src] / 32768.0f;
}

// run STFT + apply Mel filterbank
// converts PCM data to mel spectrogram
// Matches torchaudio.transforms.MelSpectrogram with center=True, power=2.0
int calculate_mel_spectrogram(const int16_t *pcm_data, uint32_t pcm_size, float *spectrogram,
                              uint16_t spec_cols_max)
{
    if (!pcm_data || !spectrogram)
        return -1;

    const uint16_t n_fft = cfg.fft_size;
    const uint16_t hop = cfg.hop_length;
    const uint16_t fft_bins = n_fft / 2 + 1;
    const uint16_t pad = n_fft / 2;  // center padding amount

    // With center=True, padded length = pcm_size + 2*pad
    uint32_t padded_size = pcm_size + 2 * pad;
    uint16_t n_frames = (padded_size - n_fft) / hop + 1;

    if (n_frames > spec_cols_max)
        n_frames = spec_cols_max;

    // input to CMSIS FFT
    float fft_buffer[MAX_FFT_SIZE];
    float power_spectrum[MAX_FFT_SIZE / 2 + 1];

    for (uint16_t frame = 0; frame < n_frames; ++frame)
    {
        uint32_t offset = frame * hop;

        // frame with window, using reflect-padded samples
        for (uint16_t i = 0; i < n_fft; ++i)
        {
            fft_buffer[i] = get_padded_sample(pcm_data, pcm_size, offset + i, pad)
                            * window_buffer[i];
        }

        // real FFT using CMSIS-DSP
        arm_rfft_fast_f32(&fft_instance, fft_buffer, fft_buffer, 0);

        // power spectrum from real + imag
        // DC component
        power_spectrum[0] = fft_buffer[0] * fft_buffer[0];
        for (uint16_t i = 1; i < fft_bins - 1; ++i)
        {
            float re = fft_buffer[2 * i];
            float im = fft_buffer[2 * i + 1];
            power_spectrum[i] = re * re + im * im;
        }
        // Nyquist component
        power_spectrum[fft_bins - 1] = fft_buffer[1] * fft_buffer[1];

        // apply Mel filterbank + dB conversion
        for (uint16_t m = 0; m < cfg.n_mels; ++m)
        {
            float mel_energy = 0.0f;
            for (uint16_t k = 0; k < fft_bins; ++k)
            {
                mel_energy += power_spectrum[k] * mel_filters[m * fft_bins + k];
            }

            float clamped = mel_energy > 1e-10f ? mel_energy : 1e-10f;
            float log_energy = 10.0f * log10f(clamped);
            spectrogram[m * n_frames + frame] = log_energy;
        }
    }

    // Dynamic dB floor: clamp to (max_value - TOP_DB), matching torchaudio AmplitudeToDB
    float max_db = spectrogram[0];
    for (uint32_t i = 1; i < (uint32_t)cfg.n_mels * n_frames; ++i)
    {
        if (spectrogram[i] > max_db)
            max_db = spectrogram[i];
    }
    float floor_db = max_db - TOP_DB;
    for (uint32_t i = 0; i < (uint32_t)cfg.n_mels * n_frames; ++i)
    {
        if (spectrogram[i] < floor_db)
            spectrogram[i] = floor_db;
    }

    return n_frames;
}

// Z-score normalization: (x - mean) / (std + 1e-6)
// Matches Python: mel_db = (mel_db - mel_db.mean()) / (mel_db.std() + 1e-6)
void normalize_spectrogram(float *spectrogram, uint16_t n_mels, uint16_t n_frames)
{
    uint32_t n = (uint32_t)n_mels * n_frames;

    // compute mean
    float mean = 0.0f;
    for (uint32_t i = 0; i < n; ++i)
        mean += spectrogram[i];
    mean /= n;

    // compute std
    float var = 0.0f;
    for (uint32_t i = 0; i < n; ++i)
    {
        float diff = spectrogram[i] - mean;
        var += diff * diff;
    }
    float std = sqrtf(var / n);

    // normalize
    float inv_std = 1.0f / (std + 1e-6f);
    for (uint32_t i = 0; i < n; ++i)
        spectrogram[i] = (spectrogram[i] - mean) * inv_std;
}
