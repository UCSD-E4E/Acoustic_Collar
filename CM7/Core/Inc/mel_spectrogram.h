// mel_spectrogram.h
#ifndef MEL_SPECTROGRAM_H
#define MEL_SPECTROGRAM_H

#include <stdint.h>

#define MAX_FFT_SIZE 258 //2048
#define MAX_MEL_BANDS 64 //128

typedef struct
{
    uint32_t sample_rate;
    uint16_t fft_size;
    uint16_t hop_length;
    uint16_t n_mels;
    float f_min;
    float f_max;
} MelSpectrogramConfig_t;

/**
 * @brief Initializes FFT, window, and mel filterbank.
 * @param config Pointer to configuration struct
 * @return 0 if successful, -1 on failure
 */
int mel_spectrogram_init(MelSpectrogramConfig_t *config);

/**
 * @brief Computes a mel spectrogram from a PCM buffer.
 * @param pcm_data Input PCM samples (int16_t)
 * @param pcm_size Number of samples
 * @param spectrogram Output buffer (size = config.n_mels × num_frames)
 * @param spec_cols_max Max number of time frames (columns)
 * @return number of time frames calculated, or -1 on error
 */
int calculate_mel_spectrogram(const int16_t *pcm_data, uint32_t pcm_size, float *spectrogram,
                              uint16_t spec_cols_max);

/**
 * @brief Normalizes spectrogram in-place to [0, 1] range
 */
void normalize_spectrogram(float *spec, uint16_t n_mels, uint16_t n_frames);

#endif // MEL_SPECTROGRAM_H
