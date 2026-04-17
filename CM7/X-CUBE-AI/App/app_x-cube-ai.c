
/**
  ******************************************************************************
  * @file    app_x-cube-ai.c
  * @author  X-CUBE-AI C code generator
  * @brief   AI program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include <math.h>

#include "app_x-cube-ai.h"
#include "main.h"
#include "ai_datatypes_defines.h"
#include "tinycnnbuow.h"
#include "tinycnnbuow_data.h"

#include "mel_spec_buffer.h"
#include "mel_spectrogram.h"
#include "mel_filterbank.h"

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

/* USER CODE BEGIN 2 */
int acquire_and_process_data(ai_i8* data[], uint16_t* pcm_buffer)
{

  // TODO: move spectrogram conversion to a different place

  // define configuration - match trained model
    MelSpectrogramConfig_t config = {.fft_size = 512,
                                     .hop_length = 256,
                                     .n_mels = 128,
                                     .sample_rate = 16000.0f,
                                     .f_min = 0.0f,
                                     .f_max = 8000.0f};

    mel_spectrogram_init(&config);

    // compute spectrogram directly into the model input buffer (inside pool0)
    float *mel_spec = (float *)data[0];
    memset(mel_spec, 0, AI_TINYCNNBUOW_IN_1_SIZE_BYTES);

    /* --- PCM diagnostics --- */
    int16_t *pcm = (int16_t *)pcm_buffer;
    int16_t pcm_min = pcm[0], pcm_max = pcm[0];
    int64_t pcm_sum = 0;
    uint32_t zero_count = 0;
    for (uint32_t i = 0; i < AI_PCM_BUFFER_SIZE; i++) {
      if (pcm[i] < pcm_min) pcm_min = pcm[i];
      if (pcm[i] > pcm_max) pcm_max = pcm[i];
      pcm_sum += pcm[i];
      if (pcm[i] == 0) zero_count++;
    }
    // printf("PCM: min=%d max=%d mean=%d zeros=%lu/%d\r\n",
    //     pcm_min, pcm_max, (int)(pcm_sum / AI_PCM_BUFFER_SIZE),
    //     (unsigned long)zero_count, AI_PCM_BUFFER_SIZE);

    // call DSP pipeline for PCMBuffer -> mel_spec
    int n_frames = calculate_mel_spectrogram((const int16_t *)pcm_buffer, AI_PCM_BUFFER_SIZE, mel_spec,
                         AI_TINYCNNBUOW_IN_1_CHANNEL);

    /* --- Mel spec diagnostics (before normalization) --- */
    // float mel_min = mel_spec[0], mel_max = mel_spec[0];
    // uint32_t nan_count = 0, inf_count = 0;
    // for (uint32_t i = 0; i < (uint32_t)config.n_mels * n_frames; i++) {
    //   if (isnan(mel_spec[i])) nan_count++;
    //   if (isinf(mel_spec[i])) inf_count++;
    //   if (mel_spec[i] < mel_min) mel_min = mel_spec[i];
    //   if (mel_spec[i] > mel_max) mel_max = mel_spec[i];
    // }
    /* Print as integers since newlib-nano may not support %f */
    // printf("Mel (pre-norm): min=%d.%02d max=%d.%02d frames=%d nan=%lu inf=%lu\r\n",
    //     (int)mel_min, abs((int)(mel_min * 100) % 100),
    //     (int)mel_max, abs((int)(mel_max * 100) % 100),
    //     n_frames, (unsigned long)nan_count, (unsigned long)inf_count);

    normalize_spectrogram(mel_spec, config.n_mels, n_frames);

    /* --- Post-normalization check --- */
    // float norm_min = mel_spec[0], norm_max = mel_spec[0];
    // for (uint32_t i = 1; i < (uint32_t)config.n_mels * n_frames; i++) {
    //   if (mel_spec[i] < norm_min) norm_min = mel_spec[i];
    //   if (mel_spec[i] > norm_max) norm_max = mel_spec[i];
    // }
    // printf("Mel (post-norm): min=%d.%02d max=%d.%02d\r\n",
    //     (int)norm_min, abs((int)(norm_min * 100) % 100),
    //     (int)norm_max, abs((int)(norm_max * 100) % 100));

    return 0;
}


int post_process(ai_i8* data[])
{
    float *predictions = (float *)data[0];

    const char *class_names[] = {
        "Cluck",
        "Coocoo",
        "Twitter",
        "Alarm",
        "Chick Begging",
        "no_buow"
    };

    /* Find predicted class index */
    int max_index = 0;
    for (int i = 1; i < AI_TINYCNNBUOW_OUT_1_SIZE; i++) {
        if (predictions[i] > predictions[max_index])
            max_index = i;
    }

    /* Emit comma-separated scores (value * 100, integer, signed) */
    printf("SCORES:");
    for (int i = 0; i < AI_TINYCNNBUOW_OUT_1_SIZE; i++) {
        int score = (int)(predictions[i] * 100);
        if (i < AI_TINYCNNBUOW_OUT_1_SIZE - 1)
            printf("%d,", score);
        else
            printf("%d", score);
    }
    printf("\r\n");
    printf("PREDICTION:%s\r\n", class_names[max_index]);

    return 0;
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

    /* USER CODE BEGIN 6 */
void MX_X_CUBE_AI_TestInference(void)
{
  if (!tinycnnbuow) {
    printf("ERROR: model not initialized\r\n");
    return;
  }

  /* Load pre-computed mel spectrogram from FLASH into the model input buffer */
  #include "test_melspec.h"

  float *dst = (float *)data_ins[0];
  memcpy(dst, test_melspec, AI_TINYCNNBUOW_IN_1_SIZE * sizeof(float));

  printf("\r\n--- Test Inference (pre-computed mel spec) ---\r\n");

  if (ai_run() == 0) {
    post_process(data_outs);
  } else {
    printf("ERROR: ai_run failed\r\n");
  }

  printf("--- End Test Inference ---\r\n");
}

void MX_X_CUBE_AI_TestMelSpec(void)
{
  if (!tinycnnbuow) {
    printf("ERROR: model not initialized\r\n");
    return;
  }

  #include "test_pcm.h"

  /* Same config as acquire_and_process_data */
  MelSpectrogramConfig_t config = {
    .fft_size = 512,
    .hop_length = 256,
    .n_mels = 128,
    .sample_rate = 16000.0f,
    .f_min = 0.0f,
    .f_max = 8000.0f
  };
  mel_spectrogram_init(&config);

  /* Compute mel spectrogram into model input buffer (inside pool0) */
  float *mel_spec = (float *)data_ins[0];
  memset(mel_spec, 0, AI_TINYCNNBUOW_IN_1_SIZE_BYTES);

  int n_frames = calculate_mel_spectrogram(
      test_pcm, TEST_PCM_SIZE, mel_spec, AI_TINYCNNBUOW_IN_1_CHANNEL);

  normalize_spectrogram(mel_spec, config.n_mels, n_frames);

  printf("\r\n--- Test Mel Spectrogram ---\r\n");
  printf("PCM samples: %d (%.3fs at 16kHz)\r\n", TEST_PCM_SIZE, TEST_PCM_SIZE / 16000.0f);
  printf("Frames computed: %d\r\n", n_frames);
  printf("First 4 values: %.6f %.6f %.6f %.6f\r\n",
      mel_spec[0], mel_spec[1], mel_spec[2], mel_spec[3]);
  printf("Buffer addr: 0x%08lX  Size: %d floats (%d bytes)\r\n",
      (unsigned long)mel_spec, config.n_mels * n_frames,
      config.n_mels * n_frames * (int)sizeof(float));
  printf("Export via Memory Browser, then resume.\r\n");
  printf("--- Halting (breakpoint) ---\r\n");

  // __BKPT(0);  /* Halts here — export data_ins[0] via Memory Browser */

  /* Run inference on the mel spec we just computed */
  printf("\r\n--- Test Inference (from PCM) ---\r\n");
  if (ai_run() == 0) {
    post_process(data_outs);
  } else {
    printf("ERROR: ai_run failed\r\n");
  }
  printf("--- End Test ---\r\n");
}

void MX_X_CUBE_AI_Process(uint16_t *pcm_buffer)
{

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
}
    /* USER CODE END 6 */

#ifdef __cplusplus

#endif
