/*
 * audiohandler.c
 *
 *  Created on: Jul 9, 2025
 *      Author: milov
 */
#include "audiohandler.h"

typedef enum {
  BUFFER_OFFSET_NONE = 0,
  BUFFER_OFFSET_HALF,
  BUFFER_OFFSET_FULL,
}BUFFER_StateTypeDef;

/* AUDIO VARIABLES INIT */
extern AUDIO_ErrorTypeDef AUDIO_Start(uint32_t audio_start_address, uint32_t audio_file_size);
#define AUDIO_FREQUENCY            16000U
#define AUDIO_IN_PDM_BUFFER_SIZE  (uint32_t)(128*AUDIO_FREQUENCY/16000*2)
#define AUDIO_NB_BLOCKS    ((uint32_t)4)
#define AUDIO_BLOCK_SIZE   ((uint32_t)0xFFFE)

#if defined ( __CC_ARM )  /* !< ARM Compiler */
  ALIGN_32BYTES (uint16_t recordPDMBuf[AUDIO_IN_PDM_BUFFER_SIZE]) __attribute__((section(".RAM_D3")));

#elif defined ( __ICCARM__ )  /* !< ICCARM Compiler */
  #pragma location=0x38000000
ALIGN_32BYTES (uint16_t recordPDMBuf[AUDIO_IN_PDM_BUFFER_SIZE]);
#elif defined ( __GNUC__ )  /* !< GNU Compiler */
  ALIGN_32BYTES (uint16_t recordPDMBuf[AUDIO_IN_PDM_BUFFER_SIZE]) __attribute__((section(".RAM_D3")));
#endif
static uint32_t AudioFreq[9] = {8000 ,11025, 16000, 22050, 32000, 44100, 48000, 96000, 192000};
uint32_t VolumeLevel = 80;
uint32_t  InState = 0;
uint32_t  OutState = 0;
uint32_t *AudioFreq_ptr;
uint16_t playbackBuf[RECORD_BUFFER_SIZE*2];
BSP_AUDIO_Init_t  AudioInInit;
BSP_AUDIO_Init_t  AudioOutInit;
/* Pointer to record_data */
uint32_t AudioBufferOffset;

void MicrophoneStartProcess()
{
	uint32_t channel_nbr = 2;
	AudioFreq_ptr = AudioFreq+2; /* AUDIO_FREQUENCY_16K; */

	AudioOutInit.Device = AUDIO_OUT_DEVICE_HEADPHONE;
	AudioOutInit.ChannelsNbr = channel_nbr;
	AudioOutInit.SampleRate = *AudioFreq_ptr;
	AudioOutInit.BitsPerSample = AUDIO_RESOLUTION_16B;
	AudioOutInit.Volume = VolumeLevel;

	AudioInInit.Device = AUDIO_IN_DEVICE_DIGITAL_MIC;
	AudioInInit.ChannelsNbr = channel_nbr;
	AudioInInit.SampleRate = *AudioFreq_ptr;
	AudioInInit.BitsPerSample = AUDIO_RESOLUTION_16B;
	AudioInInit.Volume = VolumeLevel;

	/* Initialize Audio Recorder with 2 channels to be used */
	printf("DEBUG: About to call BSP_AUDIO_IN_Init(1, ...)\n");
	int32_t ret = BSP_AUDIO_IN_Init(1, &AudioInInit);
	printf("DEBUG: BSP_AUDIO_IN_Init returned: %ld\n", ret);
	
	ret = BSP_AUDIO_IN_GetState(1, &InState);
	printf("DEBUG: BSP_AUDIO_IN_GetState returned: %ld\n", ret);
	
	printf("DEBUG: About to call BSP_AUDIO_OUT_Init(0, ...)\n");
	ret = BSP_AUDIO_OUT_Init(0, &AudioOutInit);
	printf("DEBUG: BSP_AUDIO_OUT_Init returned: %ld\n", ret);

	printf("DEBUG: About to call BSP_AUDIO_OUT_SetDevice\n");
	ret = BSP_AUDIO_OUT_SetDevice(0, AUDIO_OUT_DEVICE_HEADPHONE);
	printf("DEBUG: BSP_AUDIO_OUT_SetDevice returned: %ld\n", ret);
	
	printf("DEBUG: About to call BSP_AUDIO_IN_RecordPDM - THIS IS WHERE IT HANGS\n");
	// Ensure SAI4 is enabled
	__HAL_SAI_ENABLE(&haudio_in_sai);
	printf("DEBUG: SAI4 enabled\n");
	
	// Diagnostic info
	HAL_SAI_StateTypeDef sai_state = haudio_in_sai.State;
	printf("DEBUG: SAI State before RecordPDM: %d\n", sai_state);
	printf("DEBUG: haudio_in_sai Instance: 0x%lx\n", (uint32_t)haudio_in_sai.Instance);
	printf("DEBUG: haudio_in_sai.hdmarx: 0x%lx\n", (uint32_t)haudio_in_sai.hdmarx);
	
	if(haudio_in_sai.hdmarx != NULL) {
		printf("DEBUG: DMA Instance: 0x%lx\n", (uint32_t)haudio_in_sai.hdmarx->Instance);
		printf("DEBUG: DMA State: %d\n", haudio_in_sai.hdmarx->State);
	} else {
		printf("DEBUG: ERROR - hdmarx is NULL!\n");
	}
	
	// Check Audio_In_Ctx
	printf("DEBUG: Audio_In_Ctx[1].BitsPerSample: %ld\n", Audio_In_Ctx[1].BitsPerSample);
	uint32_t dma_size = (AUDIO_IN_PDM_BUFFER_SIZE / (Audio_In_Ctx[1].BitsPerSample/8U));
	printf("DEBUG: DMA transfer size (half-words): %ld\n", dma_size);
	
	// Check PDM configuration
	SAI_Block_TypeDef* sai_block = (SAI_Block_TypeDef*)haudio_in_sai.Instance;
	printf("DEBUG: SAI CR1: 0x%lx\n", sai_block->CR1);
	printf("DEBUG: SAI FRCR: 0x%lx\n", sai_block->FRCR);
	printf("DEBUG: SAI SLOTR: 0x%lx\n", sai_block->SLOTR);
	
	printf("DEBUG: Calling HAL_SAI_Receive_DMA...\n");
	
	// Try to start DMA with interrupt-based approach instead of blocking
	// Use HAL_SAI_Receive_DMA directly with a timeout
	uint32_t tickstart = HAL_GetTick();
	uint32_t timeout_ms = 1000; // 1 second timeout
	
	// Call the DMA receive with explicit timeout check
	HAL_StatusTypeDef hal_ret = HAL_SAI_Receive_DMA(&haudio_in_sai, (uint8_t*)&recordPDMBuf, AUDIO_IN_PDM_BUFFER_SIZE / 2);
	printf("DEBUG: HAL_SAI_Receive_DMA returned HAL status: %d\n", hal_ret);
	
	if(hal_ret != HAL_OK) {
		printf("DEBUG: ERROR! HAL_SAI_Receive_DMA failed with status: %d\n", hal_ret);
		printf("DEBUG: SAI State after failure: %d\n", haudio_in_sai.State);
		if(haudio_in_sai.ErrorCode != 0) {
			printf("DEBUG: SAI Error Code: 0x%lx\n", haudio_in_sai.ErrorCode);
		}
		ret = BSP_ERROR_PERIPH_FAILURE;
	} else {
		printf("DEBUG: HAL_SAI_Receive_DMA SUCCEEDED!\n");
		ret = BSP_ERROR_NONE;
	}

	// TODO: remove audio playback - just for testing audio recording
	printf("DEBUG: About to call BSP_AUDIO_OUT_Play\n");
	ret = BSP_AUDIO_OUT_Play(0, (uint8_t*)&RecPlayback, RECORD_BUFFER_SIZE);
	printf("DEBUG: BSP_AUDIO_OUT_Play returned: %ld\n", ret);
}

void DMA2_Stream1_IRQHandler(void)
{
   BSP_AUDIO_OUT_IRQHandler(0);
}

/**
  * @brief Calculates the remaining file size and new position of the pointer.
  * @param  None
  * @retval None
  */
void  BSP_AUDIO_IN_TransferComplete_CallBack(uint32_t Instance)
{
    if(Instance == 1U)
  {
    /* Invalidate Data Cache to get the updated content of the SRAM*/
    SCB_InvalidateDCache_by_Addr((uint32_t *)&recordPDMBuf[AUDIO_IN_PDM_BUFFER_SIZE/2], AUDIO_IN_PDM_BUFFER_SIZE*2);

    BSP_AUDIO_IN_PDMToPCM(Instance, (uint16_t*)&recordPDMBuf[AUDIO_IN_PDM_BUFFER_SIZE/2], &RecPlayback[playbackPtr]);

    /* Clean Data Cache to update the content of the SRAM */
    SCB_CleanDCache_by_Addr((uint32_t*)&RecPlayback[playbackPtr], AUDIO_IN_PDM_BUFFER_SIZE/4);

    // TODO: MAKE A FLAG TO AVOID CALLING IN TRANSFER CALLBACK
    printf("processing 2nd half of buffer");
    AI_PROCESS = 1; //signal AI processing
    //MX_X_CUBE_AI_Process(&RecPlayback[playbackPtr]);

    playbackPtr += AUDIO_IN_PDM_BUFFER_SIZE/4/2;
    if(playbackPtr >= RECORD_BUFFER_SIZE)
      playbackPtr = 0;
  }
  else
  {
    AudioBufferOffset = BUFFER_OFFSET_FULL;
  }

}

/**
  * @brief  Manages the DMA Half Transfer complete interrupt.
  * @param  None
  * @retval None
  */
void BSP_AUDIO_IN_HalfTransfer_CallBack(uint32_t Instance)
{
    if(Instance == 1U)
  {
    /* Invalidate Data Cache to get the updated content of the SRAM*/
    SCB_InvalidateDCache_by_Addr((uint32_t *)&recordPDMBuf[0], AUDIO_IN_PDM_BUFFER_SIZE*2);

    BSP_AUDIO_IN_PDMToPCM(Instance, (uint16_t*)&recordPDMBuf[0], &RecPlayback[playbackPtr]);

    /* Clean Data Cache to update the content of the SRAM */
    SCB_CleanDCache_by_Addr((uint32_t*)&RecPlayback[playbackPtr], AUDIO_IN_PDM_BUFFER_SIZE/4);

    // TODO: MAKE A FLAG TO AVOID CALLING IN TRANSFER CALLBACK
    printf("processing 1st half of buffer");
    AI_PROCESS = 1; //signal AI processing
    //MX_X_CUBE_AI_Process(&RecPlayback[playbackPtr]);

    playbackPtr += AUDIO_IN_PDM_BUFFER_SIZE/4/2;
    if(playbackPtr >= RECORD_BUFFER_SIZE)
    {
      playbackPtr = 0;
    }
  }
  else
  {
    AudioBufferOffset = BUFFER_OFFSET_HALF;
  }

}

/**
  * @brief  Audio IN Error callback function
  * @param  None
  * @retval None
  */
void BSP_AUDIO_IN_Error_CallBack(uint32_t Instance)
{
  /* Stop the program with an infinite loop */
  Error_Handler();
}
/**
  * @}
  */

