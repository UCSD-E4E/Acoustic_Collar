/**
  ******************************************************************************
  * @file    tinycnnbuow_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    2026-02-22T15:22:11-0800
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#ifndef TINYCNNBUOW_DATA_PARAMS_H
#define TINYCNNBUOW_DATA_PARAMS_H

#include "ai_platform.h"

/*
#define AI_TINYCNNBUOW_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_tinycnnbuow_data_weights_params[1]))
*/

#define AI_TINYCNNBUOW_DATA_CONFIG               (NULL)


#define AI_TINYCNNBUOW_DATA_ACTIVATIONS_SIZES \
  { 370176, }
#define AI_TINYCNNBUOW_DATA_ACTIVATIONS_SIZE     (370176)
#define AI_TINYCNNBUOW_DATA_ACTIVATIONS_COUNT    (1)
#define AI_TINYCNNBUOW_DATA_ACTIVATION_1_SIZE    (370176)



#define AI_TINYCNNBUOW_DATA_WEIGHTS_SIZES \
  { 15100, }
#define AI_TINYCNNBUOW_DATA_WEIGHTS_SIZE         (15100)
#define AI_TINYCNNBUOW_DATA_WEIGHTS_COUNT        (1)
#define AI_TINYCNNBUOW_DATA_WEIGHT_1_SIZE        (15100)



#define AI_TINYCNNBUOW_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_tinycnnbuow_activations_table[1])

extern ai_handle g_tinycnnbuow_activations_table[1 + 2];



#define AI_TINYCNNBUOW_DATA_WEIGHTS_TABLE_GET() \
  (&g_tinycnnbuow_weights_table[1])

extern ai_handle g_tinycnnbuow_weights_table[1 + 2];


#endif    /* TINYCNNBUOW_DATA_PARAMS_H */
