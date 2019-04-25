/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2018 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file		gw1ns2k_i2c.h
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date		2018-5-1 09:00:00
 * @brief		This file contains all the functions prototypes for the I2C firmware library.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GW1NS2K_I2C_H
#define __GW1NS2K_I2C_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gw1ns2k.h"

/** @addtogroup GW1NS2K_StdPeriph_Driver
  * @{
  */

/** @addtogroup I2C
  * @{
  */

/** @defgroup I2C_Exported_Types
  * @{
  */

/**
  * @}
  */

/** @defgroup I2C_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions
  * @{
  */

/**
  * @brief Initial I2C
  */ 
extern void I2C_Init(void);

/**
  * @brief Sends 8-bits data to the serial bus
  */
extern void I2C_SendByte(uint8_t c);

/**
  * @brief Receives 8-bits data from the serial bus
  */
extern uint8_t I2C_ReceiveByte(void);

/**
  * @brief Receives the acknowledge bit
  */
extern uint32_t I2C_ReceiveAck(void);

/**
  * @brief  Sends the acknowledge bit
  */
extern void I2C_SendAck(void);

/**
  * @brief Write data stream and read one byte
  */
extern uint8_t I2C_Read(uint8_t reg_addr,uint8_t s_addr);

/**
  * @brief Write data stream and write one byte
  */
extern void I2C_Write(uint8_t reg_addr,uint8_t data_byte,uint8_t s_addr);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* __GW1NS2K_I2C_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************GowinSemiconductor******END OF FILE*******************/

