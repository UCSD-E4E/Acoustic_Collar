/*
 * audiohandler.h
 *
 *  Created on: Jul 9, 2025
 *      Author: milov
 */

#ifndef INC_AUDIOHANDLER_H_
#define INC_AUDIOHANDLER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32h7xx_hal.h"
#include "stm32h747i_discovery_audio.h"
#include "main.h"
#include "app_x-cube-ai.h"

void MicrophoneStartProcess();

#ifdef __cplusplus
}
#endif

#endif /* INC_AUDIOHANDLER_H_ */
