/**
  ******************************************************************************
  * @file    tinycnnbuowl.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-07-02T10:50:32-0700
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "tinycnnbuowl.h"
#include "tinycnnbuowl_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_tinycnnbuowl
 
#undef AI_TINYCNNBUOWL_MODEL_SIGNATURE
#define AI_TINYCNNBUOWL_MODEL_SIGNATURE     "0x8a2c598bd3a777908b7a16db1ca4fb77"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "2025-07-02T10:50:32-0700"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_TINYCNNBUOWL_N_BATCHES
#define AI_TINYCNNBUOWL_N_BATCHES         (1)

static ai_ptr g_tinycnnbuowl_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_tinycnnbuowl_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_input0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 16512, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  in_pad_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16512, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  pad_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 17160, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  out_pad_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 17160, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 33024, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  in_pad_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 33024, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  pad_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 35632, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  transpose_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 35632, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  in_pad_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  pad_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19008, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  transpose_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19008, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  nl_12_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  transpose_13_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  reduce_14_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  reduce_14_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  gemm_16_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 6, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 72, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4608, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  reduce_14_Mul_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  reduce_14_Mul_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  gemm_16_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  gemm_16_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 9, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch1_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4128, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 72, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch1_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4128, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_bias, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_12_bias_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 64, 16), AI_STRIDE_INIT(4, 4, 4, 128, 8192),
  1, &conv2d_12_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_scratch0, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 3, 3), AI_STRIDE_INIT(4, 4, 4, 64, 192),
  1, &conv2d_12_scratch0_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_weights, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 16, 3, 3, 32), AI_STRIDE_INIT(4, 4, 64, 2048, 6144),
  1, &conv2d_12_weights_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_2_bias_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 129, 32), AI_STRIDE_INIT(4, 4, 4, 32, 4128),
  1, &conv2d_2_output_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 3, 3), AI_STRIDE_INIT(4, 4, 4, 4, 12),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch1, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 258, 2), AI_STRIDE_INIT(4, 4, 4, 32, 8256),
  1, &conv2d_2_scratch1_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 8), AI_STRIDE_INIT(4, 4, 4, 32, 96),
  1, &conv2d_2_weights_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_7_bias_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 64, 16), AI_STRIDE_INIT(4, 4, 4, 64, 4096),
  1, &conv2d_7_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 3, 3), AI_STRIDE_INIT(4, 4, 4, 32, 96),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch1, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 129, 2), AI_STRIDE_INIT(4, 4, 4, 64, 8256),
  1, &conv2d_7_scratch1_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 8, 3, 3, 16), AI_STRIDE_INIT(4, 4, 32, 512, 1536),
  1, &conv2d_7_weights_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  gemm_16_bias, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 4, 4, 24, 24),
  1, &gemm_16_bias_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  gemm_16_output, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 4, 4, 24, 24),
  1, &gemm_16_output_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  gemm_16_weights, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 32, 6, 1, 1), AI_STRIDE_INIT(4, 4, 128, 768, 768),
  1, &gemm_16_weights_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  in_pad_0_output, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 64, 258), AI_STRIDE_INIT(4, 4, 4, 4, 256),
  1, &in_pad_0_output_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  in_pad_10_output, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 64), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &in_pad_10_output_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  in_pad_5_output, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 32, 129), AI_STRIDE_INIT(4, 4, 4, 32, 1024),
  1, &in_pad_5_output_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  nl_12_nl_output, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 64, 16), AI_STRIDE_INIT(4, 4, 4, 128, 8192),
  1, &nl_12_nl_output_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  out_pad_0_output, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 1, 260, 66, 1), AI_STRIDE_INIT(4, 4, 4, 1040, 68640),
  1, &out_pad_0_output_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  out_pad_0_output0, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 260, 66), AI_STRIDE_INIT(4, 4, 4, 4, 1040),
  1, &out_pad_0_output_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  pad_0_output, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 66, 260), AI_STRIDE_INIT(4, 4, 4, 4, 264),
  1, &pad_0_output_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  pad_10_output, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 18, 66), AI_STRIDE_INIT(4, 4, 4, 64, 1152),
  1, &pad_10_output_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  pad_5_output, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 34, 131), AI_STRIDE_INIT(4, 4, 4, 32, 1088),
  1, &pad_5_output_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  reduce_14_Mul_bias, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_14_Mul_bias_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  reduce_14_Mul_output, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 32), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_14_Mul_output_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  reduce_14_Mul_output0, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &reduce_14_Mul_output_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  reduce_14_Mul_scale, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_14_Mul_scale_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  reduce_14_output, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 32), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_14_output_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_input0_output, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 1, 258, 64, 1), AI_STRIDE_INIT(4, 4, 4, 1032, 66048),
  1, &serving_default_input0_output_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  transpose_11_output, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 66, 18), AI_STRIDE_INIT(4, 4, 4, 64, 4224),
  1, &transpose_11_output_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  transpose_13_output, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 32), AI_STRIDE_INIT(4, 4, 4, 256, 4096),
  1, &transpose_13_output_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  transpose_6_output, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 131, 34), AI_STRIDE_INIT(4, 4, 4, 32, 4192),
  1, &transpose_6_output_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_14_Mul_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_16_weights, &gemm_16_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  gemm_16_layer, 16,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &gemm_16_chain,
  NULL, &gemm_16_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_14_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_14_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_14_Mul_scale, &reduce_14_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_14_Mul_layer, 14,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_14_Mul_chain,
  NULL, &gemm_16_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_14_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_14_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_14_neutral_value_data, reduce_14_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_14_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_14_layer, 14,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_14_chain,
  NULL, &reduce_14_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_14_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  transpose_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_12_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_13_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  transpose_13_layer, 13,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &transpose_13_chain,
  NULL, &reduce_14_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_WIDTH, AI_SHAPE_HEIGHT, AI_SHAPE_CHANNEL, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_12_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_12_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_12_nl_layer, 12,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_12_nl_chain,
  NULL, &transpose_13_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_12_weights, &conv2d_12_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_12_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_12_layer, 12,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_12_chain,
  NULL, &nl_12_nl_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  transpose_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_11_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  transpose_11_layer, 11,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &transpose_11_chain,
  NULL, &conv2d_12_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_CHANNEL, AI_SHAPE_HEIGHT, AI_SHAPE_WIDTH, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)


AI_STATIC_CONST ai_float pad_10_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_10_value, AI_ARRAY_FORMAT_FLOAT,
    pad_10_value_data, pad_10_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &in_pad_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_10_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_10_layer, 10,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_10_chain,
  NULL, &transpose_11_layer, AI_STATIC, 
  .value = &pad_10_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  in_pad_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &in_pad_10_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  in_pad_10_layer, 10,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &in_pad_10_chain,
  NULL, &pad_10_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_CHANNEL, AI_SHAPE_HEIGHT, AI_SHAPE_WIDTH, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_7_scratch0, &conv2d_7_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 8,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_if32of32wf32_nl_pool,
  &conv2d_7_chain,
  NULL, &in_pad_10_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = AI_HANDLE_PTR(forward_lite_nl_relu_if32of32), 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = AI_HANDLE_PTR(pool_func_mp_array_f32), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  transpose_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_6_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  transpose_6_layer, 6,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &transpose_6_chain,
  NULL, &conv2d_7_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_CHANNEL, AI_SHAPE_HEIGHT, AI_SHAPE_WIDTH, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)


AI_STATIC_CONST ai_float pad_5_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_5_value, AI_ARRAY_FORMAT_FLOAT,
    pad_5_value_data, pad_5_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &in_pad_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_5_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_5_layer, 5,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_5_chain,
  NULL, &transpose_6_layer, AI_STATIC, 
  .value = &pad_5_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  in_pad_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &in_pad_5_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  in_pad_5_layer, 5,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &in_pad_5_chain,
  NULL, &pad_5_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_CHANNEL, AI_SHAPE_HEIGHT, AI_SHAPE_WIDTH, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &out_pad_0_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_scratch0, &conv2d_2_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 3,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_if32of32wf32_nl_pool,
  &conv2d_2_chain,
  NULL, &in_pad_5_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = AI_HANDLE_PTR(forward_lite_nl_relu_if32of32), 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = AI_HANDLE_PTR(pool_func_mp_array_f32), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  out_pad_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &out_pad_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  out_pad_0_layer, 0,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &out_pad_0_chain,
  NULL, &conv2d_2_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_HEIGHT, AI_SHAPE_WIDTH, AI_SHAPE_CHANNEL, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)


AI_STATIC_CONST ai_float pad_0_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_0_value, AI_ARRAY_FORMAT_FLOAT,
    pad_0_value_data, pad_0_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &in_pad_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_0_layer, 0,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_0_chain,
  NULL, &out_pad_0_layer, AI_STATIC, 
  .value = &pad_0_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  in_pad_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_input0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &in_pad_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  in_pad_0_layer, 0,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &in_pad_0_chain,
  NULL, &pad_0_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_HEIGHT, AI_SHAPE_WIDTH, AI_SHAPE_CHANNEL, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 24352, 1, 1),
    24352, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 285056, 1, 1),
    285056, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_TINYCNNBUOWL_IN_NUM, &serving_default_input0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_TINYCNNBUOWL_OUT_NUM, &gemm_16_output),
  &in_pad_0_layer, 0x16751416, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 24352, 1, 1),
      24352, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 285056, 1, 1),
      285056, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_TINYCNNBUOWL_IN_NUM, &serving_default_input0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_TINYCNNBUOWL_OUT_NUM, &gemm_16_output),
  &in_pad_0_layer, 0x16751416, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool tinycnnbuowl_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_tinycnnbuowl_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    serving_default_input0_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 98800);
    serving_default_input0_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 98800);
    in_pad_0_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 164848);
    in_pad_0_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 164848);
    pad_0_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 162256);
    pad_0_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 162256);
    out_pad_0_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 93616);
    out_pad_0_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 93616);
    conv2d_2_scratch0_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 162256);
    conv2d_2_scratch0_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 162256);
    conv2d_2_scratch1_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 162292);
    conv2d_2_scratch1_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 162292);
    conv2d_2_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 20864);
    conv2d_2_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 20864);
    in_pad_5_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 152960);
    in_pad_5_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 152960);
    pad_5_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 142528);
    pad_5_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 142528);
    transpose_6_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 0);
    transpose_6_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 0);
    conv2d_7_scratch0_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 142528);
    conv2d_7_scratch0_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 142528);
    conv2d_7_scratch1_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 142816);
    conv2d_7_scratch1_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 142816);
    conv2d_7_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 159328);
    conv2d_7_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 159328);
    in_pad_10_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 0);
    in_pad_10_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 0);
    pad_10_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 65536);
    pad_10_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 65536);
    transpose_11_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 141568);
    transpose_11_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 141568);
    conv2d_12_scratch0_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 0);
    conv2d_12_scratch0_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 0);
    conv2d_12_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 576);
    conv2d_12_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 576);
    nl_12_nl_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 131648);
    nl_12_nl_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 131648);
    transpose_13_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 0);
    transpose_13_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 0);
    reduce_14_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 131072);
    reduce_14_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 131072);
    reduce_14_Mul_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 0);
    reduce_14_Mul_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 0);
    gemm_16_output_array.data = AI_PTR(g_tinycnnbuowl_activations_map[0] + 128);
    gemm_16_output_array.data_start = AI_PTR(g_tinycnnbuowl_activations_map[0] + 128);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}




/******************************************************************************/
AI_DECLARE_STATIC
ai_bool tinycnnbuowl_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_tinycnnbuowl_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(g_tinycnnbuowl_weights_map[0] + 0);
    conv2d_2_weights_array.data_start = AI_PTR(g_tinycnnbuowl_weights_map[0] + 0);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(g_tinycnnbuowl_weights_map[0] + 288);
    conv2d_2_bias_array.data_start = AI_PTR(g_tinycnnbuowl_weights_map[0] + 288);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(g_tinycnnbuowl_weights_map[0] + 320);
    conv2d_7_weights_array.data_start = AI_PTR(g_tinycnnbuowl_weights_map[0] + 320);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(g_tinycnnbuowl_weights_map[0] + 4928);
    conv2d_7_bias_array.data_start = AI_PTR(g_tinycnnbuowl_weights_map[0] + 4928);
    conv2d_12_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_weights_array.data = AI_PTR(g_tinycnnbuowl_weights_map[0] + 4992);
    conv2d_12_weights_array.data_start = AI_PTR(g_tinycnnbuowl_weights_map[0] + 4992);
    conv2d_12_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_bias_array.data = AI_PTR(g_tinycnnbuowl_weights_map[0] + 23424);
    conv2d_12_bias_array.data_start = AI_PTR(g_tinycnnbuowl_weights_map[0] + 23424);
    reduce_14_Mul_scale_array.format |= AI_FMT_FLAG_CONST;
    reduce_14_Mul_scale_array.data = AI_PTR(g_tinycnnbuowl_weights_map[0] + 23552);
    reduce_14_Mul_scale_array.data_start = AI_PTR(g_tinycnnbuowl_weights_map[0] + 23552);
    reduce_14_Mul_bias_array.format |= AI_FMT_FLAG_CONST;
    reduce_14_Mul_bias_array.data = AI_PTR(g_tinycnnbuowl_weights_map[0] + 23556);
    reduce_14_Mul_bias_array.data_start = AI_PTR(g_tinycnnbuowl_weights_map[0] + 23556);
    gemm_16_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_16_weights_array.data = AI_PTR(g_tinycnnbuowl_weights_map[0] + 23560);
    gemm_16_weights_array.data_start = AI_PTR(g_tinycnnbuowl_weights_map[0] + 23560);
    gemm_16_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_16_bias_array.data = AI_PTR(g_tinycnnbuowl_weights_map[0] + 24328);
    gemm_16_bias_array.data_start = AI_PTR(g_tinycnnbuowl_weights_map[0] + 24328);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/



AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_tinycnnbuowl_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_TINYCNNBUOWL_MODEL_NAME,
      .model_signature   = AI_TINYCNNBUOWL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 11209786,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x16751416,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}



AI_API_ENTRY
ai_bool ai_tinycnnbuowl_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_TINYCNNBUOWL_MODEL_NAME,
      .model_signature   = AI_TINYCNNBUOWL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 11209786,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x16751416,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_error ai_tinycnnbuowl_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}


AI_API_ENTRY
ai_error ai_tinycnnbuowl_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    AI_CONTEXT_OBJ(&AI_NET_OBJ_INSTANCE),
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}


AI_API_ENTRY
ai_error ai_tinycnnbuowl_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
  ai_error err;
  ai_network_params params;

  err = ai_tinycnnbuowl_create(network, AI_TINYCNNBUOWL_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    return err;
  }
  
  if (ai_tinycnnbuowl_data_params_get(&params) != true) {
    err = ai_tinycnnbuowl_get_error(*network);
    return err;
  }
#if defined(AI_TINYCNNBUOWL_DATA_ACTIVATIONS_COUNT)
  /* set the addresses of the activations buffers */
  for (ai_u16 idx=0; activations && idx<params.map_activations.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
  }
#endif
#if defined(AI_TINYCNNBUOWL_DATA_WEIGHTS_COUNT)
  /* set the addresses of the weight buffers */
  for (ai_u16 idx=0; weights && idx<params.map_weights.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
  }
#endif
  if (ai_tinycnnbuowl_init(*network, &params) != true) {
    err = ai_tinycnnbuowl_get_error(*network);
  }
  return err;
}


AI_API_ENTRY
ai_buffer* ai_tinycnnbuowl_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_buffer* ai_tinycnnbuowl_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_handle ai_tinycnnbuowl_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}


AI_API_ENTRY
ai_bool ai_tinycnnbuowl_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = AI_NETWORK_OBJ(ai_platform_network_init(network, params));
  ai_bool ok = true;

  if (!net_ctx) return false;
  ok &= tinycnnbuowl_configure_weights(net_ctx, params);
  ok &= tinycnnbuowl_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_tinycnnbuowl_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}


AI_API_ENTRY
ai_i32 ai_tinycnnbuowl_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_TINYCNNBUOWL_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

