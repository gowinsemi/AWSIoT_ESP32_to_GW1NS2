/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2018 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			gw1ns2c_adc.c
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date			2018-5-1 09:00:00
 * @brief			This file contains all the functions prototypes for the ADC firmware library.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns2c_adc.h"

/** @addtogroup GW1NS2C_StdPeriph_Driver
  * @{
  */

/** @defgroup ADC
  * @brief ADC driver modules
  * @{
  */

/** @defgroup ADC_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup ADC_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup ADC_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup ADC_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup ADC_Private_Functions
  * @{
  */

/**
  * @param ADC_InitTypeDef Pointer
  * @return none
  * @brief Initial ADC
  */
void ADC_Init(ADC_InitTypeDef* ADC_InitStruct)
{
  /* Initial register to zero */
  ADC->STATUS = 0;
  ADC->CTRL = 0;
  
  /* Sets ADC mode */
  if(ADC_InitStruct->ADC_Mode==ADC_MODE_CONT)
  {
    ADC->CTRL |= ADC_MODE_CONT;
  }
  else if(ADC_InitStruct->ADC_Mode==ADC_MODE_SINGLE)
  {
    ADC->CTRL &= ADC_MODE_SINGLE;
  }

  /* Sets ADC Power on */
  if(ADC_InitStruct->ADC_Status==ADC_STATUS_ON)
  {
    ADC->CTRL |= ADC_STATUS_ON;
  }
  else if(ADC_InitStruct->ADC_Status==ADC_STATUS_OFF)
  {
    ADC->CTRL &= ADC_STATUS_OFF;
  }

  /* Sets ADC Channel */
  ADC->CTRL |= ADC_InitStruct->ADC_Chsel;
}

/**
  * @param uint32_t ADC mode
           @arg ADC_MODE_CONT
           @arg ADC_MODE_SINGLE
  * @return none
  * @brief Sets ADC conversion mode.
  */
void ADC_SetMode(uint32_t ADC_Mode)
{
  if(ADC_Mode==ADC_MODE_CONT)
  {
    ADC->CTRL |= ADC_MODE_CONT;
  }
  else if(ADC_Mode==ADC_MODE_SINGLE)
  {
    ADC->CTRL &= ADC_MODE_SINGLE;
  }
}

/**
  * @param none
  * @return uint32_t ADC mode
            @arg ADC_MODE_CONT
            @arg ADC_MODE_SINGLE
  * @brief Returns ADC conversion mode.
  */
uint32_t ADC_GetMode(void)
{
  if((ADC->CTRL&ADC_CTRL_CONT)==ADC_CTRL_CONT)
  {
    return ADC_MODE_CONT;
  }
  else
  {
    return ADC_MODE_SINGLE;
  }
}

/**
  * @param uint32_t ADC status
           @arg ADC_STATUS_ON
           @arg ADC_STATUS_OFF
  * @return none
  * @brief Sets ADC conversion begin or end.
  */
void ADC_SetPowerStatus(uint32_t ADC_Status)
{
  if(ADC_Status==ADC_STATUS_ON)
  {
    ADC->CTRL |= ADC_STATUS_ON;
	ADC->STATUS |= ADC_STATUS_SOC;
	ADC->STATUS &= ~ADC_STATUS_EOC;
  }
  else if(ADC_Status==ADC_STATUS_OFF)
  {
    ADC->CTRL &= ADC_STATUS_OFF;
	ADC->STATUS |= ADC_STATUS_EOC;
	ADC->STATUS &= ~ADC_STATUS_SOC;
  }
}

/**
  * @param none
  * @return uint32_t ADC Status
            @arg ADC_STATUS_ON
            @arg ADC_STATUS_OFF
  * @brief Returns ADC conversion begin or end.
  */
uint32_t ADC_GetPowerStatus(void)
{
  if((ADC->CTRL&ADC_CTRL_ADON)==ADC_CTRL_ADON)
  {
    return ADC_STATUS_ON;
  }
  else
  {
    return ADC_STATUS_OFF;
  }
}

/**
  * @param uint32_t ADC channel
           @arg ADC_CHSEL_0
           @arg ADC_CHSEL_1
           @arg ADC_CHSEL_2
           @arg ADC_CHSEL_3
           @arg ADC_CHSEL_4
           @arg ADC_CHSEL_5
           @arg ADC_CHSEL_6
           @arg ADC_CHSEL_7
  * @return none
  * @brief Sets ADC conversion channel.
  */
void ADC_SetChannel(uint32_t channel)
{
  ADC->CTRL &= ~ADC_CTRL_CHSEL;
  ADC->CTRL |= channel;
}

/**
  * @param none
  * @return unint32_t ADC channel
            @arg ADC_CHSEL_0
            @arg ADC_CHSEL_1
            @arg ADC_CHSEL_2
            @arg ADC_CHSEL_3
            @arg ADC_CHSEL_4
            @arg ADC_CHSEL_5
            @arg ADC_CHSEL_6
            @arg ADC_CHSEL_7
  * @brief Returns ADC channel.
  */
uint32_t ADC_GetChannel(void)
{
  return ADC->CTRL & ADC_CTRL_CHSEL;
}

/**
  * @param none
  * @return FlagStatus
            @arg RET
            @arg RESET
  * @brief Returns ADC End Flag.
  */
FlagStatus ADC_GetEocStatus(void)
{
  return (FlagStatus)((ADC->STATUS&ADC_STATUS_EOC)>>ADC_STATUS_EOC_Pos);
}

/**
  * @param none
  * @return FlagStatus
            @arg RET
            @arg RESET
  * @brief Returns ADC Begin Flag.
  */
FlagStatus ADC_GetSocStatus(void)
{
  return (FlagStatus)((ADC->STATUS&ADC_STATUS_SOC)>>ADC_STATUS_SOC_Pos);
}

/**
  * @param none
  * @return uin32_t ADC Data
  * @brief Returns ADC data.
  */
uint32_t ADC_ReadData(void)
{
  return ADC->DATA;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************GowinSemiconductor******END OF FILE*******************/

