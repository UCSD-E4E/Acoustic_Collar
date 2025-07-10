/*
 * audio_record.h
 *
 *  Created on: Jul 9, 2025
 *      Author: firaz
 */

#ifndef INC_AUDIO_RECORD_H_
#define INC_AUDIO_RECORD_H_

//TODO: fix include issues, clean up macros, and add conv_to_mel_spectrogram function prototype

/* Includes ------------------------------------------------------------------*/
#include "app_x-cube-ai.h"
#include "mel_spectrogram.h"
#include "stm32h747i_discovery_audio.h"


/** @addtogroup BSP_Examples
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Audio frequency */
#define AUDIO_FREQUENCY            16000U
#define AUDIO_IN_PDM_BUFFER_SIZE  (uint32_t)(128*AUDIO_FREQUENCY/16000*2)
#define RECORD_BUFFER_SIZE 4096
/* Size of the recorder buffer */
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern uint16_t recordPDMBuf[AUDIO_IN_PDM_BUFFER_SIZE];
extern uint8_t PCM_BUFFER_READY;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* USER CODE BEGIN PFP */
/**
  * @brief Test Audio record.
  *   The main objective of this test is to check the hardware connection of the
  *   Audio peripheral.
  * @param  None
  * @retval None
*/
void AudioRecord_demo(void);

/**
 * @brief Converts PCM buffer to mel spectrogram.
 * @param pcm_buffer Input PCM samples (uint16_t)
 * @param mel_spec_buffer Output mel spectrogram buffer (float)
 * @param n_mels Number of mel bands
 * @param n_frames Number of time frames
 */
void conv_to_mel_spectrogram(uint16_t *pcm_buffer, float *mel_spec_buffer, uint16_t mel_spec_size);

/*USER CODE END PFP */

#endif /* INC_AUDIO_RECORD_H_ */
