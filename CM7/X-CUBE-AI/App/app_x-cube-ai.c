
/**
  ******************************************************************************
  * @file    app_x-cube-ai.c
  * @author  X-CUBE-AI C code generator
  * @brief   AI program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

 /*
  * Description
  *   v1.0 - Minimum template to show how to use the Embedded Client API
  *          model. Only one input and one output is supported. All
  *          memory resources are allocated statically (AI_NETWORK_XX, defines
  *          are used).
  *          Re-target of the printf function is out-of-scope.
  *   v2.0 - add multiple IO and/or multiple heap support
  *
  *   For more information, see the embeded documentation:
  *
  *       [1] %X_CUBE_AI_DIR%/Documentation/index.html
  *
  *   X_CUBE_AI_DIR indicates the location where the X-CUBE-AI pack is installed
  *   typical : C:\Users\[user_name]\STM32Cube\Repository\STMicroelectronics\X-CUBE-AI\7.1.0
  */

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#if defined ( __ICCARM__ )
#elif defined ( __CC_ARM ) || ( __GNUC__ )
#endif

/* System headers */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "app_x-cube-ai.h"
#include "main.h"
#include "ai_datatypes_defines.h"
#include "tinycnnbuow.h"
#include "tinycnnbuow_data.h"
#include "mel_spec_buffer.h"
#include "main.h"
#include "mel_spectrogram.h"
#include "mel_filterbank.h"

int _write(int file, char *ptr, int len)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)ptr, len, HAL_MAX_DELAY);
    return len;
}

// extern float mel_spec_buffer[64 * 258];

/* USER CODE BEGIN includes */
/* USER CODE END includes */

/* IO buffers ----------------------------------------------------------------*/

#if !defined(AI_TINYCNNBUOW_INPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_in_1[AI_TINYCNNBUOW_IN_1_SIZE_BYTES];
ai_i8* data_ins[AI_TINYCNNBUOW_IN_NUM] = {
data_in_1
};
#else
ai_i8* data_ins[AI_TINYCNNBUOW_IN_NUM] = {
NULL
};
#endif

#if !defined(AI_TINYCNNBUOW_OUTPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_out_1[AI_TINYCNNBUOW_OUT_1_SIZE_BYTES];
ai_i8* data_outs[AI_TINYCNNBUOW_OUT_NUM] = {
data_out_1
};
#else
ai_i8* data_outs[AI_TINYCNNBUOW_OUT_NUM] = {
NULL
};
#endif

/* Activations buffers -------------------------------------------------------*/

AI_ALIGNED(32)
static uint8_t pool0[AI_TINYCNNBUOW_DATA_ACTIVATION_1_SIZE];

ai_handle data_activations0[] = {pool0};

/* AI objects ----------------------------------------------------------------*/

static ai_handle tinycnnbuow = AI_HANDLE_NULL;

static ai_buffer* ai_input;
static ai_buffer* ai_output;

// simulated spectrogram 64 mel bands × 258 time frames = 16512 float values
// float dummy_mel_spectrogram[64 * 258];

static void ai_log_err(const ai_error err, const char *fct)
{
  /* USER CODE BEGIN log */
  if (fct)
    printf("TEMPLATE - Error (%s) - type=0x%02x code=0x%02x\r\n", fct,
        err.type, err.code);
  else
    printf("TEMPLATE - Error - type=0x%02x code=0x%02x\r\n", err.type, err.code);

  do {} while (1);
  /* USER CODE END log */
}

static int ai_boostrap(ai_handle *act_addr)
{
  ai_error err;

  /* Create and initialize an instance of the model */
  err = ai_tinycnnbuow_create_and_init(&tinycnnbuow, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    ai_log_err(err, "ai_tinycnnbuow_create_and_init");
    return -1;
  }

  ai_input = ai_tinycnnbuow_inputs_get(tinycnnbuow, NULL);
  ai_output = ai_tinycnnbuow_outputs_get(tinycnnbuow, NULL);

#if defined(AI_TINYCNNBUOW_INPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-inputs" option is used, memory buffer can be
   *  used from the activations buffer. This is not mandatory.
   */
  for (int idx=0; idx < AI_TINYCNNBUOW_IN_NUM; idx++) {
	data_ins[idx] = ai_input[idx].data;
  }
#else
  for (int idx=0; idx < AI_TINYCNNBUOW_IN_NUM; idx++) {
	  ai_input[idx].data = data_ins[idx];
  }
#endif

#if defined(AI_TINYCNNBUOW_OUTPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-outputs" option is used, memory buffer can be
   *  used from the activations buffer. This is no mandatory.
   */
  for (int idx=0; idx < AI_TINYCNNBUOW_OUT_NUM; idx++) {
	data_outs[idx] = ai_output[idx].data;
  }
#else
  for (int idx=0; idx < AI_TINYCNNBUOW_OUT_NUM; idx++) {
	ai_output[idx].data = data_outs[idx];
  }
#endif

  return 0;
}

static int ai_run(void)
{
  ai_i32 batch;

  batch = ai_tinycnnbuow_run(tinycnnbuow, ai_input, ai_output);
  if (batch != 1) {
    ai_log_err(ai_tinycnnbuow_get_error(tinycnnbuow),
        "ai_tinycnnbuow_run");
    return -1;
  }

  return 0;
}

// this buffer is used to store the mel-spectrogram data
// n_mels x n_frames = 64 x 258 = 16512

// need to add for later in audio_recording.c
/*
#define MEL_N_MELS 64
#define MEL_N_FRAMES 258
#define MEL_SPEC_SIZE (MEL_N_MELS * MEL_N_FRAMES)
*/

// non dummy integration part
// extern float mel_spec_buffer[64 * 258];

/* USER CODE BEGIN 2 */
int acquire_and_process_data(ai_i8* data[], uint16_t* pcm_buffer)
{

  // TODO: move spectrogram conversion to a different place

  // define configuration - match trained model
    MelSpectrogramConfig_t config = {.fft_size = 512,
                                     .hop_length = 256,
                                     .n_mels = 64,
                                     .sample_rate = 16000.0f,
                                     .f_min = 0.0f,
                                     .f_max = 8000.0f};

    mel_spectrogram_init(&config);

    // output spectrogram buffer
    // n_mels x n_frames
    static float mel_spec[64 * 64];
    // zero out mel spectrogram buffer
    memset(mel_spec, 0, sizeof(mel_spec));

    // call DSP pipeline for PCMBuffer -> mel_spec
    int n_frames = calculate_mel_spectrogram((const int16_t *)pcm_buffer, RECORD_BUFFER_SIZE, mel_spec,
                                             64); // max columns

    // normalize to [0, 1]
    normalize_spectrogram(mel_spec, config.n_mels, n_frames);

    float *dst = (float *)data[0];

    for (int i = 0; i < AI_TINYCNNBUOW_IN_1_SIZE; ++i) {
        dst[i] = mel_spec[i];  // 64 * 258 = 16512
    }

    return 0;
}


int post_process(ai_i8* data[])
{
  /* process the predictions
  */

    // data[0] is a void pointer to a float buffer
    float *predictions = (float *)data[0];

    char *class_names[] = {
        "Cluck",
        "Coocoo",
        "Twitter",
        "Alarm",
        "Chick Begging",
        "no_buow"
    };

    int max_index = 0;
    float max_value = predictions[0];
    for (int i = 0; i < AI_TINYCNNBUOW_OUT_1_SIZE; ++i) {
        if (predictions[i] > max_value) {
            max_value = predictions[i];
            max_index = i;
        }
        int predict = predictions[i] * 100;
        int whole_part = predict / 100;
        if (predict < 0) {
          predict -= 2 * predict; // convert to positive
        }

      printf("Class: %s, Score: %d.%d\n\r", class_names[i], whole_part, predict%100);
      HAL_Delay(2000);
    }
    printf("Predicted Class: %s\n\r", class_names[max_index]);
    HAL_Delay(8000);

    return 0;

    // output tensor is the first element of data array

    // return 0;
}
/* USER CODE END 2 */

/* Entry points --------------------------------------------------------------*/

void MX_X_CUBE_AI_Init(void)
{
    /* USER CODE BEGIN 5 */
  printf("\r\nTEMPLATE - initialization\r\n");

  ai_boostrap(data_activations0);
    /* USER CODE END 5 */
}

void MX_X_CUBE_AI_Process(uint16_t *pcm_buffer)
{
    /* USER CODE BEGIN 6 */
  int res = -1;

  if (tinycnnbuow) {

    do {
      /* 1 - acquire and pre-process input data */
      res = acquire_and_process_data(data_ins, pcm_buffer);
      /* 2 - process the data - call inference engine */
      if (res == 0)
        res = ai_run();
      /* 3- post-process the predictions */
      if (res == 0) {
        res = post_process(data_outs);
        return;
      }
    } while (res==0);
  }

  if (res) {
    ai_error err = {AI_ERROR_INVALID_STATE, AI_ERROR_CODE_NETWORK};
    ai_log_err(err, "Process has FAILED");
  }
    /* USER CODE END 6 */
}
#ifdef __cplusplus
}
#endif
