#ifndef MEL_FILTERBANK_H
#define MEL_FILTERBANK_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /// @brief startup populate a (n_mels × (n_fft/2 + 1)) filterbank matrix
    /// @param filterbank output filterbank matrix
    /// @param n_mels
    /// @param n_fft
    /// @param sample_rate
    /// @param f_min
    /// @param f_max
    void create_mel_filterbank(float *filterbank, uint16_t n_mels, uint16_t n_fft,
                               float sample_rate, float f_min, float f_max);

#ifdef __cplusplus
}
#endif

#endif // MEL_FILTERBANK_H