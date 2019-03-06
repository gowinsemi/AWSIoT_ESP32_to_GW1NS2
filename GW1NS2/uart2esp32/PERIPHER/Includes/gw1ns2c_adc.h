/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2018 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			gw1ns2c_adc.h
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date			2018-5-1 09:00:00
 * @brief			This file contains all the functions prototypes for the ADC firmware library.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GW1NS2C_ADC_H
#define __GW1NS2C_ADC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gw1ns2c.h"

/** @addtogroup GW1NS2C_StdPeriph_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */

/** @defgroup ADC_Exported_Types
  * @{
  */

/* ADC Initialization TypeDef */
typedef struct
{
  uint32_t ADC_Mode;     /* Mode selected: 1:Continuous;0:Single; */
  
  uint32_t ADC_Status;   /* Conversion status: 1:Begin;0:End; */
  
  uint32_t ADC_Chsel;    /* Channel selected: 0~7:Channel0~7 */
  
}ADC_InitTypeDef;

/**
  * @}
  */

/** @defgroup ADC_Exported_Macros
  * @{
  */

/* ADC Status register bit position */
#define ADC_STATUS_EOC_Pos   0            /* ADC STATUS register EOC bit position */
#define ADC_STATUS_SOC_Pos   1            /* ADC STATUS register SOC bit position */

/* ADC mode selection */
#define ADC_MODE_CONT       ((uint32_t) 0x00000020)       /* ADC continuous conversion mode */
#define ADC_MODE_SINGLE     ((uint32_t) 0xFFFFFFDF)       /* ADC single conversion mode */

/* ADC begin and end flag */
#define ADC_STATUS_ON       ((uint32_t) 0x00000010)       /* ADC conversion begin */
#define ADC_STATUS_OFF      ((uint32_t) 0xFFFFFFEF)       /* ADC conversiong end  */

/* ADC channel selection */
#define ADC_CHSEL_0         ((uint32_t) 0x00000000)       /* ADC Channel 0 */
#define ADC_CHSEL_1         ((uint32_t) 0x00000001)       /* ADC Channel 1 */
#define ADC_CHSEL_2         ((uint32_t) 0x00000002)       /* ADC Channel 2 */
#define ADC_CHSEL_3         ((uint32_t) 0x00000003)       /* ADC Channel 3 */
#define ADC_CHSEL_4         ((uint32_t) 0x00000004)       /* ADC Channel 4 */
#define ADC_CHSEL_5         ((uint32_t) 0x00000005)       /* ADC Channel 5 */
#define ADC_CHSEL_6         ((uint32_t) 0x00000006)       /* ADC Channel 6 */
#define ADC_CHSEL_7         ((uint32_t) 0x00000007)       /* ADC Channel 7 */

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions
  * @{
  */

/**
  * @brief Initial ADC
  */
extern void ADC_Init(ADC_InitTypeDef* ADC_InitStruct);

/**
  * @brief Sets ADC conversion mode.
  */
extern void ADC_SetMode(uint32_t ADC_Mode);

/**
  * @brief Returns ADC conversion mode.
  */
extern uint32_t ADC_GetMode(void);

/**
  * @brief Sets ADC conversion begin or end.
  */
extern void ADC_SetPowerStatus(uint32_t ADC_Status);

/**
  * @brief Returns ADC conversion begin or end.
  */
extern uint32_t ADC_GetPowerStatus(void);

/**
  * @brief Sets ADC conversion channel.
  */
extern void ADC_SetChannel(uint32_t channel);

/**
  * @brief Returns ADC channel.
  */
extern uint32_t ADC_GetChannel(void);

/**
  * @brief Returns ADC End Flag.
  */
extern FlagStatus ADC_GetEocStatus(void);

/**
  * @brief Returns ADC Begin Flag.
  */
extern FlagStatus ADC_GetSocStatus(void);

/**
  * @brief Returns ADC data.
  */
extern uint32_t ADC_ReadData(void);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* __GW1NS2C_ADC_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************GowinSemiconductor******END OF FILE*******************/
