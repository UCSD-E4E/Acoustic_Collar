// mel_filterbank.c
#include "mel_filterbank.h"
#include "arm_math.h" // CMSIS DSP math functions
#include "mel_spectrogram.h"
#include <stdint.h>
#include <string.h> // for memset

// convert hertz to mel scale
static float hz_to_mel(float hz) { return 2595.0f * log10f(1.0f + hz / 700.0f); }

// convert mel scale to hertz
static float mel_to_hz(float mel)
{
    // could optimize?
    return 700.0f * (powf(10.0f, mel / 2595.0f) - 1.0f);
}
// UNCOMENT IF PROVEN BENEFIT, to do testing
/*
static float hz_to_mel(float hz) {
    float temp;
    arm_log10_f32(1.0f + hz / 700.0f, &temp);
    return 2595.0f * temp;
}

static float mel_to_hz(float mel) {
    float exp;
    arm_pow_f32(10.0f, mel / 2595.0f, &exp);
    return 700.0f * (exp - 1.0f);
}
*/

// main function to create filterbank
void create_mel_filterbank(float *filterbank, uint16_t n_mels, uint16_t n_fft, float sample_rate,
                           float f_min, float f_max)
{
    uint16_t fft_bins = n_fft / 2 + 1;

    // zero out the filterbank output
    memset(filterbank, 0, sizeof(float) * n_mels * fft_bins);

    float mel_min = hz_to_mel(f_min);
    float mel_max = hz_to_mel(f_max);
    float mel_step = (mel_max - mel_min) / (n_mels + 1);

    float mel_points[MAX_MEL_BANDS + 2]; // Fixed size array (e.g., 130 max)
    float bin_points[MAX_MEL_BANDS + 2];

    // calculate mel spaced frequency points
    for (uint16_t i = 0; i < n_mels + 2; ++i)
    {
        mel_points[i] = mel_min + i * mel_step;
        float hz = mel_to_hz(mel_points[i]);
        bin_points[i] = (hz / sample_rate) * n_fft;
    }

    // create triangular filters
    for (uint16_t m = 0; m < n_mels; ++m)
    {
        uint16_t left = (uint16_t)bin_points[m];
        uint16_t center = (uint16_t)bin_points[m + 1];
        uint16_t right = (uint16_t)bin_points[m + 2];

        // denominators prevent division by zero
        float denom_left = center - left + 1e-6f;
        float denom_right = right - center + 1e-6f;

        // fill the filterbank for this mel band
        for (uint16_t k = left; k < center && k < fft_bins; ++k)
        {
            filterbank[m * fft_bins + k] = (k - left) / denom_left;
        }
        for (uint16_t k = center; k < right && k < fft_bins; ++k)
        {
            filterbank[m * fft_bins + k] = (right - k) / denom_right;
        }
    }
}