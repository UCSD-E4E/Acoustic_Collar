/**
  ******************************************************************************
  * @file    tinycnnbuow.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2026-02-22T15:22:11-0800
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "tinycnnbuow.h"
#include "tinycnnbuow_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_tinycnnbuow
 
#undef AI_TINYCNNBUOW_MODEL_SIGNATURE
#define AI_TINYCNNBUOW_MODEL_SIGNATURE     "0xe979d1a3f8fdf398911a4cd6869ecff0"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "2026-02-22T15:22:11-0800"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_TINYCNNBUOW_N_BATCHES
#define AI_TINYCNNBUOW_N_BATCHES         (1)

static ai_ptr g_tinycnnbuow_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_tinycnnbuow_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_args_00_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 92544, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 92544, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  slice_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 30848, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  pad_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 31590, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 123392, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 246784, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 246784, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 246784, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  pool_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 61440, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  pad_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64416, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 245760, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 122880, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 122880, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_13_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 122880, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  pool_14_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 30720, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  pad_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 33728, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 122880, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 61440, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 61440, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 61440, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  pool_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  gemm_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conversion_22_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 6, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  model_batch_normalization_2_FusedBatchNormV3_4D_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  model_batch_normalization_2_FusedBatchNormV31_4D_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  model_batch_normalization_5_FusedBatchNormV3_4D_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  model_batch_normalization_5_FusedBatchNormV31_4D_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  model_batch_normalization_8_FusedBatchNormV3_4D_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  model_batch_normalization_8_FusedBatchNormV31_4D_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 4, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  gemm_21_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 192, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  gemm_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 6, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 164, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 96, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5344, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6592, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  gemm_21_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 32, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002172238426283002f, 0.0017415483016520739f, 0.0012822163989767432f, 0.001231536502018571f, 0.0023951255716383457f, 0.001916074543260038f, 0.0020797906909137964f, 0.0023278489243239164f, 0.0017364242812618613f, 0.0013033871073275805f, 0.0022112284786999226f, 0.001759556122124195f, 0.002205784199759364f, 0.0016784663312137127f, 0.001839665463194251f, 0.0024735291954129934f, 0.0012769665336236358f, 0.002127495827153325f, 0.002753246808424592f, 0.002100636251270771f, 0.003392947604879737f, 0.002978249453008175f, 0.0022859417367726564f, 0.0018152156844735146f, 0.0019785952754318714f, 0.002047502202913165f, 0.0013306193286553025f, 0.004169606138020754f, 0.0012524689082056284f, 0.00203032698482275f, 0.0016639255918562412f, 0.002075230237096548f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.19995659589767456f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0069118523970246315f, 0.006651399191468954f, 0.0029470797162503004f, 0.004118687938898802f, 0.004248857498168945f, 0.005115826148539782f, 0.0028739639092236757f, 0.003503920743241906f, 0.003697535488754511f, 0.005277089308947325f, 0.0038689749781042337f, 0.005946774501353502f, 0.003729928284883499f, 0.001914779655635357f, 0.005348232574760914f, 0.0035043652169406414f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008429957670159638f, 0.0010608253069221973f, 0.0010011701378971338f, 0.0008359532221220434f, 0.0007193286437541246f, 0.0009693218162283301f, 0.0007764844340272248f, 0.0012475348776206374f, 0.000851794087793678f, 0.0006253514438867569f, 0.0008503983845002949f, 0.0010642800480127335f, 0.0006759638199582696f, 0.0011131385108456016f, 0.000836393388453871f, 0.0008721385966055095f, 0.0011281868210062385f, 0.0007069386774674058f, 0.001017762697301805f, 0.0007101123919710517f, 0.0005117125692777336f, 0.0014416621997952461f, 0.0008027637377381325f, 0.0008380734361708164f, 0.00043631502194330096f, 0.000969510932918638f, 0.0016997064230963588f, 0.0010897606844082475f, 0.0009910488734021783f, 0.001092605059966445f, 0.0009800890693441033f, 0.0007956555928103626f, 0.0010780487209558487f, 0.001308545470237732f, 0.0010076030157506466f, 0.0012872976949438453f, 0.0009868525667116046f, 0.0005530622438527644f, 0.0010193242924287915f, 0.0010484856320545077f, 0.0012823687866330147f, 0.0012615583837032318f, 0.0007263357401825488f, 0.0007795033161528409f, 0.0013381895842030644f, 0.0013532680459320545f, 0.001199082238599658f, 0.0005243305931799114f, 0.0021298457868397236f, 0.0016623054398223758f, 0.0008703891071490943f, 0.0006722509860992432f, 0.0011431816965341568f, 0.0008927182061597705f, 0.0005491009796969593f, 0.001327232108451426f, 0.0013019153848290443f, 0.001655577914789319f, 0.000960918958298862f, 0.001268568797968328f, 0.000753602187614888f, 0.0011985213495790958f, 0.0010884411167353392f, 0.000556953891646117f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.38698631525039673f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0018562858458608389f, 0.002058283658698201f, 0.004676490556448698f, 0.0013023156207054853f, 0.005772226955741644f, 0.0020340655464679003f, 0.0034826237242668867f, 0.002424965612590313f, 0.0022583643440157175f, 0.0014272213447839022f, 0.0044846804812550545f, 0.0028296788223087788f, 0.0027802938129752874f, 0.004981151781976223f, 0.00323236221447587f, 0.0033926607575267553f, 0.0033177149016410112f, 0.0026932712644338608f, 0.001852584071457386f, 0.002234378131106496f, 0.003798877587541938f, 0.004486528225243092f, 0.0022569382563233376f, 0.003838932840153575f, 0.003218406578525901f, 0.00342765636742115f, 0.0028799620922654867f, 0.00244054663926363f, 0.003476144280284643f, 0.0055765327997505665f, 0.003947016317397356f, 0.002857688581570983f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 4,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003105682088062167f, 0.0035079549998044968f, 0.0038083887193351984f, 0.004602120723575354f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04232097417116165f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015467388555407524f, 0.0062683639116585255f, 0.00859502051025629f, 0.014273536391556263f, 0.01065606065094471f, 0.009565073996782303f, 0.00635859090834856f, 0.005801682826131582f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.036143407225608826f),
    AI_PACK_INTQ_ZP(7)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_12_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.19995659589767456f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_13_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.19822753965854645f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_18_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.38707974553108215f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_19_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.38707974553108215f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_6_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04232097417116165f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_7_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04069497063755989f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_21_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10823925584554672f),
    AI_PACK_INTQ_ZP(28)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_21_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009389277547597885f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(model_batch_normalization_2_FusedBatchNormV31_4D_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005732369143515825f),
    AI_PACK_INTQ_ZP(127)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(model_batch_normalization_2_FusedBatchNormV3_4D_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017568564042448997f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(model_batch_normalization_5_FusedBatchNormV31_4D_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003786191577091813f),
    AI_PACK_INTQ_ZP(127)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(model_batch_normalization_5_FusedBatchNormV3_4D_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06027384474873543f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(model_batch_normalization_8_FusedBatchNormV31_4D_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003497098106890917f),
    AI_PACK_INTQ_ZP(86)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(model_batch_normalization_8_FusedBatchNormV3_4D_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.35370007157325745f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pad_15_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.19822753965854645f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pad_3_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.036143407225608826f),
    AI_PACK_INTQ_ZP(7)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pad_9_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04069497063755989f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pool_14_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.19822753965854645f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pool_20_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013567951507866383f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pool_8_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04069497063755989f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_1_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.036143407225608826f),
    AI_PACK_INTQ_ZP(7)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_10_bias_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 120, 64), AI_STRIDE_INIT(4, 1, 1, 32, 3840),
  1, &conv2d_10_output_array, &conv2d_10_output_array_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 5344, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5344, 5344),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 8, 3, 3, 32), AI_STRIDE_INIT(4, 1, 8, 256, 768),
  1, &conv2d_10_weights_array, &conv2d_10_weights_array_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_bias, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_11_bias_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 120, 64), AI_STRIDE_INIT(4, 1, 1, 16, 1920),
  1, &conv2d_11_output_array, &conv2d_11_output_array_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch0, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 288, 1, 1), AI_STRIDE_INIT(4, 1, 1, 288, 288),
  1, &conv2d_11_scratch0_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_weights, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 16), AI_STRIDE_INIT(4, 1, 32, 512, 512),
  1, &conv2d_11_weights_array, &conv2d_11_weights_array_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_16_bias_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 60, 32), AI_STRIDE_INIT(4, 1, 1, 64, 3840),
  1, &conv2d_16_output_array, &conv2d_16_output_array_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 6592, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6592, 6592),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 64), AI_STRIDE_INIT(4, 1, 16, 1024, 3072),
  1, &conv2d_16_weights_array, &conv2d_16_weights_array_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_17_bias_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 60, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1920),
  1, &conv2d_17_output_array, &conv2d_17_output_array_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 576, 1, 1), AI_STRIDE_INIT(4, 1, 1, 576, 576),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 32), AI_STRIDE_INIT(4, 1, 64, 2048, 2048),
  1, &conv2d_17_weights_array, &conv2d_17_weights_array_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &conv2d_4_bias_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 4, 241, 128), AI_STRIDE_INIT(4, 1, 1, 4, 964),
  1, &conv2d_4_output_array, &conv2d_4_output_array_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 164, 1, 1), AI_STRIDE_INIT(4, 1, 1, 164, 164),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 3, 4), AI_STRIDE_INIT(4, 1, 1, 4, 12),
  1, &conv2d_4_weights_array, &conv2d_4_weights_array_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_5_bias_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 241, 128), AI_STRIDE_INIT(4, 1, 1, 8, 1928),
  1, &conv2d_5_output_array, &conv2d_5_output_array_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 1, 1, 96, 96),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 4, 1, 1, 8), AI_STRIDE_INIT(4, 1, 4, 32, 32),
  1, &conv2d_5_weights_array, &conv2d_5_weights_array_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 1, 241, 128, 3), AI_STRIDE_INIT(4, 1, 1, 241, 30848),
  1, &conversion_0_output_array, &conversion_0_output_array_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conversion_22_output, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 4, 4, 24, 24),
  1, &conversion_22_output_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_12_output, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 120, 64), AI_STRIDE_INIT(4, 1, 1, 16, 1920),
  1, &eltwise_12_output_array, &eltwise_12_output_array_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_13_output, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 120, 64), AI_STRIDE_INIT(4, 1, 1, 16, 1920),
  1, &eltwise_13_output_array, &eltwise_13_output_array_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_18_output, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 60, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1920),
  1, &eltwise_18_output_array, &eltwise_18_output_array_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_19_output, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 60, 32), AI_STRIDE_INIT(4, 1, 1, 32, 1920),
  1, &eltwise_19_output_array, &eltwise_19_output_array_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_6_output, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 241, 128), AI_STRIDE_INIT(4, 1, 1, 8, 1928),
  1, &eltwise_6_output_array, &eltwise_6_output_array_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_7_output, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 241, 128), AI_STRIDE_INIT(4, 1, 1, 8, 1928),
  1, &eltwise_7_output_array, &eltwise_7_output_array_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  gemm_21_bias, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 4, 4, 24, 24),
  1, &gemm_21_bias_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  gemm_21_output, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6, 6),
  1, &gemm_21_output_array, &gemm_21_output_array_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  gemm_21_scratch0, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 2, 2, 64, 64),
  1, &gemm_21_scratch0_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  gemm_21_weights, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 32, 6, 1, 1), AI_STRIDE_INIT(4, 1, 32, 192, 192),
  1, &gemm_21_weights_array, &gemm_21_weights_array_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  model_batch_normalization_2_FusedBatchNormV31_4D, AI_STATIC,
  36, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 1, 1, 8, 8),
  1, &model_batch_normalization_2_FusedBatchNormV31_4D_array, &model_batch_normalization_2_FusedBatchNormV31_4D_array_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  model_batch_normalization_2_FusedBatchNormV3_4D, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 1, 1, 8, 8),
  1, &model_batch_normalization_2_FusedBatchNormV3_4D_array, &model_batch_normalization_2_FusedBatchNormV3_4D_array_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  model_batch_normalization_5_FusedBatchNormV31_4D, AI_STATIC,
  38, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &model_batch_normalization_5_FusedBatchNormV31_4D_array, &model_batch_normalization_5_FusedBatchNormV31_4D_array_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  model_batch_normalization_5_FusedBatchNormV3_4D, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &model_batch_normalization_5_FusedBatchNormV3_4D_array, &model_batch_normalization_5_FusedBatchNormV3_4D_array_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  model_batch_normalization_8_FusedBatchNormV31_4D, AI_STATIC,
  40, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &model_batch_normalization_8_FusedBatchNormV31_4D_array, &model_batch_normalization_8_FusedBatchNormV31_4D_array_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  model_batch_normalization_8_FusedBatchNormV3_4D, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &model_batch_normalization_8_FusedBatchNormV3_4D_array, &model_batch_normalization_8_FusedBatchNormV3_4D_array_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  pad_15_output, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 62, 34), AI_STRIDE_INIT(4, 1, 1, 16, 992),
  1, &pad_15_output_array, &pad_15_output_array_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  pad_3_output, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 243, 130), AI_STRIDE_INIT(4, 1, 1, 1, 243),
  1, &pad_3_output_array, &pad_3_output_array_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  pad_9_output, AI_STATIC,
  44, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 122, 66), AI_STRIDE_INIT(4, 1, 1, 8, 976),
  1, &pad_9_output_array, &pad_9_output_array_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  pool_14_output, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 60, 32), AI_STRIDE_INIT(4, 1, 1, 16, 960),
  1, &pool_14_output_array, &pool_14_output_array_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  pool_20_output, AI_STATIC,
  46, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &pool_20_output_array, &pool_20_output_array_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  pool_8_output, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 120, 64), AI_STRIDE_INIT(4, 1, 1, 8, 960),
  1, &pool_8_output_array, &pool_8_output_array_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_args_00_output, AI_STATIC,
  48, 0x0,
  AI_SHAPE_INIT(4, 1, 241, 128, 3), AI_STRIDE_INIT(4, 4, 4, 964, 123392),
  1, &serving_default_args_00_output_array, NULL)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  slice_1_output, AI_STATIC,
  49, 0x1,
  AI_SHAPE_INIT(4, 1, 241, 128, 1), AI_STRIDE_INIT(4, 1, 1, 241, 30848),
  1, &slice_1_output_array, &slice_1_output_array_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  slice_1_output0, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 241, 128), AI_STRIDE_INIT(4, 1, 1, 1, 241),
  1, &slice_1_output_array, &slice_1_output_array_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_22_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_22_layer, 22,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conversion_22_chain,
  NULL, &conversion_22_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_21_weights, &gemm_21_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_21_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_21_layer, 21,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &gemm_21_chain,
  NULL, &conversion_22_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  pool_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_20_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pool_20_layer, 20,
  POOL_TYPE, 0x0, NULL,
  pool, forward_ap_integer_INT8,
  &pool_20_chain,
  NULL, &gemm_21_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(60, 32), 
  .pool_stride = AI_SHAPE_2D_INIT(60, 32), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_18_output, &model_batch_normalization_8_FusedBatchNormV31_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_19_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_19_layer, 19,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_19_chain,
  NULL, &pool_20_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_17_output, &model_batch_normalization_8_FusedBatchNormV3_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_18_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_18_layer, 18,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_18_chain,
  NULL, &eltwise_19_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_17_chain,
  NULL, &eltwise_18_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_deep_3x3_sssa8_ch,
  &conv2d_16_chain,
  NULL, &conv2d_17_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 pad_15_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    pad_15_value, AI_ARRAY_FORMAT_S8,
    pad_15_value_data, pad_15_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_15_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_15_layer, 15,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_15_chain,
  NULL, &conv2d_16_layer, AI_STATIC, 
  .value = &pad_15_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  pool_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_14_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pool_14_layer, 14,
  POOL_TYPE, 0x0, NULL,
  pool, forward_mp_integer_INT8,
  &pool_14_chain,
  NULL, &pad_15_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_output, &model_batch_normalization_5_FusedBatchNormV31_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_13_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_13_layer, 13,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_13_chain,
  NULL, &pool_14_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_11_output, &model_batch_normalization_5_FusedBatchNormV3_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_12_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_12_layer, 12,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_12_chain,
  NULL, &eltwise_13_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_11_weights, &conv2d_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_11_layer, 11,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_11_chain,
  NULL, &eltwise_12_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_sssa8_ch,
  &conv2d_10_chain,
  NULL, &conv2d_11_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 pad_9_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    pad_9_value, AI_ARRAY_FORMAT_S8,
    pad_9_value_data, pad_9_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_9_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_9_layer, 9,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_9_chain,
  NULL, &conv2d_10_layer, AI_STATIC, 
  .value = &pad_9_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  pool_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_8_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pool_8_layer, 8,
  POOL_TYPE, 0x0, NULL,
  pool, forward_mp_integer_INT8,
  &pool_8_chain,
  NULL, &pad_9_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_6_output, &model_batch_normalization_2_FusedBatchNormV31_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_7_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_7_layer, 7,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_7_chain,
  NULL, &pool_8_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_5_output, &model_batch_normalization_2_FusedBatchNormV3_4D),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_6_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_6_layer, 6,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_6_chain,
  NULL, &eltwise_7_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_weights, &conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 5,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_5_chain,
  NULL, &eltwise_6_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 4,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_sssa8_ch,
  &conv2d_4_chain,
  NULL, &conv2d_5_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 pad_3_value_data[] = { 7 };
AI_ARRAY_OBJ_DECLARE(
    pad_3_value, AI_ARRAY_FORMAT_S8,
    pad_3_value_data, pad_3_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_1_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_3_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_3_layer, 3,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_3_chain,
  NULL, &conv2d_4_layer, AI_STATIC, 
  .value = &pad_3_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_u8 slice_1_axes_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_1_axes, AI_ARRAY_FORMAT_U8,
    slice_1_axes_data, slice_1_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_1_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_1_starts, AI_ARRAY_FORMAT_S16,
    slice_1_starts_data, slice_1_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_1_ends_data[] = { 1 };
AI_ARRAY_OBJ_DECLARE(
    slice_1_ends, AI_ARRAY_FORMAT_S16,
    slice_1_ends_data, slice_1_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_1_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_1_layer, 1,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_1_chain,
  NULL, &pad_3_layer, AI_STATIC, 
  .axes = &slice_1_axes, 
  .starts = &slice_1_starts, 
  .ends = &slice_1_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_args_00_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_0_layer, 0,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conversion_0_chain,
  NULL, &slice_1_layer, AI_STATIC, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 15100, 1, 1),
    15100, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 370176, 1, 1),
    370176, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_TINYCNNBUOW_IN_NUM, &serving_default_args_00_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_TINYCNNBUOW_OUT_NUM, &conversion_22_output),
  &conversion_0_layer, 0x7e64cd49, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 15100, 1, 1),
      15100, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 370176, 1, 1),
      370176, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_TINYCNNBUOW_IN_NUM, &serving_default_args_00_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_TINYCNNBUOW_OUT_NUM, &conversion_22_output),
  &conversion_0_layer, 0x7e64cd49, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool tinycnnbuow_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_tinycnnbuow_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    serving_default_args_00_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    serving_default_args_00_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    conversion_0_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    conversion_0_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    slice_1_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 92544);
    slice_1_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 92544);
    pad_3_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    pad_3_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    conv2d_4_scratch0_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 31592);
    conv2d_4_scratch0_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 31592);
    conv2d_4_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 246784);
    conv2d_4_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 246784);
    conv2d_5_scratch0_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    conv2d_5_scratch0_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    conv2d_5_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 121464);
    conv2d_5_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 121464);
    eltwise_6_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 121464);
    eltwise_6_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 121464);
    eltwise_7_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 121464);
    eltwise_7_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 121464);
    pool_8_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    pool_8_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    pad_9_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 305760);
    pad_9_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 305760);
    conv2d_10_scratch0_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    conv2d_10_scratch0_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    conv2d_10_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 5344);
    conv2d_10_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 5344);
    conv2d_11_scratch0_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    conv2d_11_scratch0_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    conv2d_11_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 3424);
    conv2d_11_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 3424);
    eltwise_12_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 126304);
    eltwise_12_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 126304);
    eltwise_13_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    eltwise_13_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    pool_14_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 122880);
    pool_14_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 122880);
    pad_15_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    pad_15_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    conv2d_16_scratch0_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 33728);
    conv2d_16_scratch0_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 33728);
    conv2d_16_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 40320);
    conv2d_16_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 40320);
    conv2d_17_scratch0_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    conv2d_17_scratch0_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    conv2d_17_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 163200);
    conv2d_17_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 163200);
    eltwise_18_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    eltwise_18_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    eltwise_19_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 61440);
    eltwise_19_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 61440);
    pool_20_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    pool_20_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    gemm_21_scratch0_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 32);
    gemm_21_scratch0_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 32);
    gemm_21_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 96);
    gemm_21_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 96);
    conversion_22_output_array.data = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    conversion_22_output_array.data_start = AI_PTR(g_tinycnnbuow_activations_map[0] + 0);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}




/******************************************************************************/
AI_DECLARE_STATIC
ai_bool tinycnnbuow_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_tinycnnbuow_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    model_batch_normalization_2_FusedBatchNormV3_4D_array.format |= AI_FMT_FLAG_CONST;
    model_batch_normalization_2_FusedBatchNormV3_4D_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 0);
    model_batch_normalization_2_FusedBatchNormV3_4D_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 0);
    model_batch_normalization_2_FusedBatchNormV31_4D_array.format |= AI_FMT_FLAG_CONST;
    model_batch_normalization_2_FusedBatchNormV31_4D_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 8);
    model_batch_normalization_2_FusedBatchNormV31_4D_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 8);
    model_batch_normalization_5_FusedBatchNormV3_4D_array.format |= AI_FMT_FLAG_CONST;
    model_batch_normalization_5_FusedBatchNormV3_4D_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 16);
    model_batch_normalization_5_FusedBatchNormV3_4D_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 16);
    model_batch_normalization_5_FusedBatchNormV31_4D_array.format |= AI_FMT_FLAG_CONST;
    model_batch_normalization_5_FusedBatchNormV31_4D_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 32);
    model_batch_normalization_5_FusedBatchNormV31_4D_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 32);
    model_batch_normalization_8_FusedBatchNormV3_4D_array.format |= AI_FMT_FLAG_CONST;
    model_batch_normalization_8_FusedBatchNormV3_4D_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 48);
    model_batch_normalization_8_FusedBatchNormV3_4D_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 48);
    model_batch_normalization_8_FusedBatchNormV31_4D_array.format |= AI_FMT_FLAG_CONST;
    model_batch_normalization_8_FusedBatchNormV31_4D_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 80);
    model_batch_normalization_8_FusedBatchNormV31_4D_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 80);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 112);
    conv2d_4_weights_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 112);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 148);
    conv2d_4_bias_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 148);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 164);
    conv2d_5_weights_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 164);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 196);
    conv2d_5_bias_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 196);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 228);
    conv2d_10_weights_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 228);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 2532);
    conv2d_10_bias_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 2532);
    conv2d_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_weights_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 2660);
    conv2d_11_weights_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 2660);
    conv2d_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_bias_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 3172);
    conv2d_11_bias_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 3172);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 3236);
    conv2d_16_weights_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 3236);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 12452);
    conv2d_16_bias_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 12452);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 12708);
    conv2d_17_weights_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 12708);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 14756);
    conv2d_17_bias_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 14756);
    gemm_21_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_21_weights_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 14884);
    gemm_21_weights_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 14884);
    gemm_21_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_21_bias_array.data = AI_PTR(g_tinycnnbuow_weights_map[0] + 15076);
    gemm_21_bias_array.data_start = AI_PTR(g_tinycnnbuow_weights_map[0] + 15076);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/



AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_tinycnnbuow_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_TINYCNNBUOW_MODEL_NAME,
      .model_signature   = AI_TINYCNNBUOW_MODEL_SIGNATURE,
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
      
      .n_macc            = 46829166,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x7e64cd49,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}



AI_API_ENTRY
ai_bool ai_tinycnnbuow_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_TINYCNNBUOW_MODEL_NAME,
      .model_signature   = AI_TINYCNNBUOW_MODEL_SIGNATURE,
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
      
      .n_macc            = 46829166,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x7e64cd49,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_error ai_tinycnnbuow_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}


AI_API_ENTRY
ai_error ai_tinycnnbuow_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    AI_CONTEXT_OBJ(&AI_NET_OBJ_INSTANCE),
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}


AI_API_ENTRY
ai_error ai_tinycnnbuow_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
  ai_error err;
  ai_network_params params;

  err = ai_tinycnnbuow_create(network, AI_TINYCNNBUOW_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    return err;
  }
  
  if (ai_tinycnnbuow_data_params_get(&params) != true) {
    err = ai_tinycnnbuow_get_error(*network);
    return err;
  }
#if defined(AI_TINYCNNBUOW_DATA_ACTIVATIONS_COUNT)
  /* set the addresses of the activations buffers */
  for (ai_u16 idx=0; activations && idx<params.map_activations.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
  }
#endif
#if defined(AI_TINYCNNBUOW_DATA_WEIGHTS_COUNT)
  /* set the addresses of the weight buffers */
  for (ai_u16 idx=0; weights && idx<params.map_weights.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
  }
#endif
  if (ai_tinycnnbuow_init(*network, &params) != true) {
    err = ai_tinycnnbuow_get_error(*network);
  }
  return err;
}


AI_API_ENTRY
ai_buffer* ai_tinycnnbuow_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_buffer* ai_tinycnnbuow_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_handle ai_tinycnnbuow_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}


AI_API_ENTRY
ai_bool ai_tinycnnbuow_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = AI_NETWORK_OBJ(ai_platform_network_init(network, params));
  ai_bool ok = true;

  if (!net_ctx) return false;
  ok &= tinycnnbuow_configure_weights(net_ctx, params);
  ok &= tinycnnbuow_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_tinycnnbuow_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}


AI_API_ENTRY
ai_i32 ai_tinycnnbuow_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_TINYCNNBUOW_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

