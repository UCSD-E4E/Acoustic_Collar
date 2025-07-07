// mel_spectrogram.c
#include "mel_spectrogram.h"
#include "arm_math.h"
#include "mel_filterbank.h"
#include <stdint.h>
#include <string.h>

// NEED TO INCLUDE ON STM32 BOARD LATER using installed libraries
// #include "arm_math.h" // CMSIS-DSP library header provided by ARM
// #include "arm_const_structs.h" // CMSIS-DSP library constants

#define LOG10_OFFSET 1e-6f
#define MIN_DB_LEVEL -80.0f // tune?

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

// run STFT + apply Mel filterbank
// converts PCM data to mel spectrogram
int calculate_mel_spectrogram(const int16_t *pcm_data, uint32_t pcm_size, float *spectrogram,
                              uint16_t spec_cols_max)
{
    if (!pcm_data || !spectrogram)
        return -1;

    const uint16_t n_fft = cfg.fft_size;
    const uint16_t hop = cfg.hop_length;
    const uint16_t fft_bins = n_fft / 2 + 1;
    uint16_t n_frames = (pcm_size - n_fft) / hop + 1;

    if (n_frames > spec_cols_max)
        n_frames = spec_cols_max;

    // input to CMSIS FFT
    float fft_buffer[MAX_FFT_SIZE];
    float power_spectrum[MAX_FFT_SIZE / 2 + 1];

    for (uint16_t frame = 0; frame < n_frames; ++frame)
    {
        uint32_t offset = frame * hop;

        // frame with window
        for (uint16_t i = 0; i < n_fft; ++i)
        {
            if (offset + i < pcm_size)
                fft_buffer[i] = (pcm_data[offset + i] / 32768.0f) * window_buffer[i];
            else
                fft_buffer[i] = 0.0f;
        }

        // real FFT using CMSIS-DSP
        arm_rfft_fast_f32(&fft_instance, fft_buffer, fft_buffer, 0);

        // power spectrum from real + imag
        // DC comp
        power_spectrum[0] = fft_buffer[0] * fft_buffer[0];
        for (uint16_t i = 1; i < fft_bins - 1; ++i)
        {
            float re = fft_buffer[2 * i];
            float im = fft_buffer[2 * i + 1];
            power_spectrum[i] = re * re + im * im;
        }
        // nyquist component
        power_spectrum[fft_bins - 1] = fft_buffer[1] * fft_buffer[1]; // Nyquist

        // apply Mel filterbank
        for (uint16_t m = 0; m < cfg.n_mels; ++m)
        {
            float mel_energy = 0.0f;
            for (uint16_t k = 0; k < fft_bins; ++k)
            {
                mel_energy += power_spectrum[k] * mel_filters[m * fft_bins + k];
            }

            float log_energy = 10.0f * log10f(mel_energy + LOG10_OFFSET);
            if (log_energy < MIN_DB_LEVEL)
                log_energy = MIN_DB_LEVEL;
            spectrogram[m * n_frames + frame] = log_energy;
        }
    }

    return n_frames;
}

// Finds min and max in mel matrix and scales to [0, 1]
void normalize_spectrogram(float *spectrogram, uint16_t n_mels, uint16_t n_frames)
{
    float min = spectrogram[0], max = spectrogram[0];

    for (uint32_t i = 0; i < n_mels * n_frames; ++i)
    {
        if (spectrogram[i] < min)
            min = spectrogram[i];
        if (spectrogram[i] > max)
            max = spectrogram[i];
    }

    float range = max - min;
    if (range == 0.0f)
    {
        memset(spectrogram, 0, n_mels * n_frames * sizeof(float));
        return;
    }

    for (uint32_t i = 0; i < n_mels * n_frames; ++i)
    {
        spectrogram[i] = (spectrogram[i] - min) / range;
    }
}
