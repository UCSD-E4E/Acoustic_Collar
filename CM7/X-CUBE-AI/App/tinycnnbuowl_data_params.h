/**
  ******************************************************************************
  * @file    tinycnnbuowl_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-07-02T10:50:32-0700
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#ifndef TINYCNNBUOWL_DATA_PARAMS_H
#define TINYCNNBUOWL_DATA_PARAMS_H

#include "ai_platform.h"

/*
#define AI_TINYCNNBUOWL_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_tinycnnbuowl_data_weights_params[1]))
*/

#define AI_TINYCNNBUOWL_DATA_CONFIG               (NULL)


#define AI_TINYCNNBUOWL_DATA_ACTIVATIONS_SIZES \
  { 285056, }
#define AI_TINYCNNBUOWL_DATA_ACTIVATIONS_SIZE     (285056)
#define AI_TINYCNNBUOWL_DATA_ACTIVATIONS_COUNT    (1)
#define AI_TINYCNNBUOWL_DATA_ACTIVATION_1_SIZE    (285056)



#define AI_TINYCNNBUOWL_DATA_WEIGHTS_SIZES \
  { 24352, }
#define AI_TINYCNNBUOWL_DATA_WEIGHTS_SIZE         (24352)
#define AI_TINYCNNBUOWL_DATA_WEIGHTS_COUNT        (1)
#define AI_TINYCNNBUOWL_DATA_WEIGHT_1_SIZE        (24352)



#define AI_TINYCNNBUOWL_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_tinycnnbuowl_activations_table[1])

extern ai_handle g_tinycnnbuowl_activations_table[1 + 2];



#define AI_TINYCNNBUOWL_DATA_WEIGHTS_TABLE_GET() \
  (&g_tinycnnbuowl_weights_table[1])

extern ai_handle g_tinycnnbuowl_weights_table[1 + 2];


#endif    /* TINYCNNBUOWL_DATA_PARAMS_H */
