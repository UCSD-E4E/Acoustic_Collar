/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


/* USER CODE END Includes */

#include "stdio.h"
//#include "stm32_lcd.h"
#include "stm32h747i_discovery.h"
#include "stm32h747i_discovery_audio.h"
#include "stm32h747i_discovery_camera.h"
#include "stm32h747i_discovery_conf.h"
#include "stm32h747i_discovery_lcd.h"
#include "stm32h747i_discovery_qspi.h"
#include "stm32h747i_discovery_sd.h"
#include "stm32h747i_discovery_sdram.h"
#include "stm32h747i_discovery_ts.h"
#include "stm32h7xx_hal.h"
#include "string.h"
#include <stdint.h>

/* Exported types ------------------------------------------------------------*/

typedef struct
{
    void (*DemoFunc)(void);
    uint8_t DemoName[50];
    uint32_t DemoIndex;
} BSP_DemoTypedef;

typedef enum
{
    AUDIO_ERROR_NONE = 0,
    AUDIO_ERROR_NOTREADY,
    AUDIO_ERROR_IO,
    AUDIO_ERROR_EOF,
} AUDIO_ErrorTypeDef;
#define SD_DMA_MODE 0U
#define SD_IT_MODE 1U
#define SD_POLLING_MODE 2U
/* Exported variables --------------------------------------------------------*/
extern const unsigned char stlogo[];
extern __IO uint32_t SRAMTest;
#ifndef USE_FULL_ASSERT
extern uint32_t ErrorCounter;
#endif
extern uint32_t JoyStickDemo;
extern __IO uint32_t ButtonState;
extern __IO uint32_t JoystickStates;
extern __IO uint32_t CameraTest;
extern __IO uint32_t SdramTest;
extern __IO uint32_t SdmmcTest;

#define RECORD_BUFFER_SIZE        4096

/* Exported constants --------------------------------------------------------*/
/**
 * @brief  SDRAM Write read buffer start address after CAM Frame buffer
 * Assuming Camera frame buffer is of size 800x480 and format ARGB8888 (32 bits per pixel).
 */
#define SDRAM_WRITE_READ_ADDR_OFFSET ((uint32_t)0x0800)

/* Defines for the Audio playing process */
#define PAUSE_STATUS ((uint32_t)0x00)  /* Audio Player in Pause Status */
#define RESUME_STATUS ((uint32_t)0x01) /* Audio Player in Resume Status */
#define IDLE_STATUS ((uint32_t)0x02)   /* Audio Player in Idle Status */

#define LED_GREEN LED1
#define LED_ORANGE LED2
#define LED_RED LED3
#define LED_BLUE LED4
#define CAMERA_FRAME_TMP 0xD020D000
/* SDRAM write address */
#define SDRAM_WRITE_READ_ADDR 0xD0177000
#define AUDIO_REC_START_ADDR SDRAM_WRITE_READ_ADDR
#define AUDIO_REC_TOTAL_SIZE ((uint32_t)0x0000E000)
#define AUDIO_RECPDM_START_ADDR (AUDIO_REC_START_ADDR + AUDIO_REC_TOTAL_SIZE)

/* The Audio file is flashed with ST-Link Utility @ flash address =  AUDIO_SRC_FILE_ADDRESS */
#define AUDIO_SRC_FILE_ADDRESS 0x08080000 /* Audio file address in flash */
#define AUDIO_FILE_SIZE 524288

#define AUDIO_PLAY_SAMPLE 0
#define AUDIO_PLAY_RECORDED 1

/* Exported macro ------------------------------------------------------------*/
#define COUNT_OF_EXAMPLE(x) (sizeof(x) / sizeof(BSP_DemoTypedef))

#ifdef USE_FULL_ASSERT
/* Assert activated */
#define ASSERT(__condition__)                                                                      \
    do                                                                                             \
    {                                                                                              \
        if (__condition__)                                                                         \
        {                                                                                          \
            assert_failed(__FILE__, __LINE__);                                                     \
            while (1)                                                                              \
                ;                                                                                  \
        }                                                                                          \
    } while (0)
#else
/* Assert not activated : macro has no effect */
#define ASSERT(__condition__)                                                                      \
    do                                                                                             \
    {                                                                                              \
        if (__condition__)                                                                         \
        {                                                                                          \
            ErrorCounter++;                                                                        \
        }                                                                                          \
    } while (0)
#endif /* USE_FULL_ASSERT */

/* Exported functions ------------------------------------------------------- */
void Touchscreen_demo1(void);
void Touchscreen_demo2(void);
void LCD_demo(void);
void Camera_demo(void);
void Joystick_demo(void);
void SD_DMA_demo(void);
void SD_IT_demo(void);
void SD_POLLING_demo(void);
void Error_Handler(void);
void SDRAM_demo(void);
void SDRAM_DMA_demo(void);
void AudioPlay_demo(void);
void AudioRecord_demo(void);
void AnalogAudioRecord_demo(void);
uint8_t AUDIO_Process(void);
void QSPI_demo(void);
uint8_t CheckForUserInput(void);
uint8_t TouchScreen_GetTouchPosition(void);
void Touchscreen_DrawBackground_Circles(uint8_t state);

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OSC32_OUT_Pin GPIO_PIN_15
#define OSC32_OUT_GPIO_Port GPIOC
#define OSC32_IN_Pin GPIO_PIN_14
#define OSC32_IN_GPIO_Port GPIOC
#define STLINK_TX_Pin GPIO_PIN_10
#define STLINK_TX_GPIO_Port GPIOA
#define STLINK_RX_Pin GPIO_PIN_9
#define STLINK_RX_GPIO_Port GPIOA
#define CEC_CK_MCO1_Pin GPIO_PIN_8
#define CEC_CK_MCO1_GPIO_Port GPIOA
#define OSC_OUT_Pin GPIO_PIN_1
#define OSC_OUT_GPIO_Port GPIOH
#define OSC_IN_Pin GPIO_PIN_0
#define OSC_IN_GPIO_Port GPIOH

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
