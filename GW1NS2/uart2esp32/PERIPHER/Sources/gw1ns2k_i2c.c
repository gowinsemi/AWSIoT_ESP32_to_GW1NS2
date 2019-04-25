/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2018 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file		gw1ns2k_i2c.c
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date		2018-5-1 09:00:00
 * @brief		This file contains all the functions prototypes for the I2C firmware library.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns2k_i2c.h"

/** @addtogroup GW1NS2K_StdPeriph_Driver
  * @{
  */

/** @defgroup I2C
  * @brief I2C driver modules
  * @{
  */

/** @defgroup I2C_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup I2C_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup I2C_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup I2C_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup I2C_Private_Functions
  * @{
  */

/**
  * @param none
  * @return none
  * @brief Initials I2C.
  */ 
void I2C_Init(void)
{
  I2C->CONTROL = 0;
  I2C->CONTROLC = 0;
}

/**
  * @param uint8_t sends character
  * @return none
  * @brief Sends 8-bits data to the serial bus.
  */
void I2C_SendByte(uint8_t c)
{
  int loop;
  
  for(loop=0;loop<8;loop++)
  {
    I2C->CONTROLC = I2C_CR_SCL;
	
	if(c & (1<<(7-loop)))
	{
	  I2C->CONTROL = I2C_CR_SDA;
	}
	else
	{
	  I2C->CONTROLC = I2C_CR_SDA;
	}
	
	I2C->CONTROL = I2C_CR_SCL;
	I2C->CONTROLC = I2C_CR_SCL;
  }
  
  I2C->CONTROL = I2C_CR_SDA;
}

/**
  * @param none
  * @return uint8_t receives character
  * @brief Receives 8-bits data from the serial bus.
  */
uint8_t I2C_ReceiveByte(void)
{
  int data=0,loop;
  
  I2C->CONTROL = I2C_CR_SDA;
  
  for(loop=0;loop<8;loop++)
  {
    I2C->CONTROLC = I2C_CR_SCL;
	I2C->CONTROL = I2C_CR_SCL | I2C_CR_SDA;
	
	if(I2C->CONTROL & I2C_CR_SDA)
	{
      data += (1<<(7-loop));
	}
	
	I2C->CONTROLC = I2C_CR_SCL;
  }
  
  I2C->CONTROLC = I2C_CR_SDA;
  
  return data;
}

/**
  * @param none
  * @return uint32_t acknowledge bits
  * @brief Receives the acknowledge bit.
  */
uint32_t I2C_ReceiveAck(void)
{
  uint32_t nack;
  
  I2C->CONTROL = I2C_CR_SDA;
  I2C->CONTROLC = I2C_CR_SCL;
  I2C->CONTROL = I2C_CR_SCL;
  nack = I2C->CONTROL & I2C_CR_SDA;
  I2C->CONTROLC = I2C_CR_SCL;
  I2C->CONTROL = I2C_CR_SDA;
  
  if(nack == 0)
  {
    return 1;
  }
  
  return 0;
}

/**
  * @param none
  * @return none
  * @brief  Sends the acknowledge bit.
  */
void I2C_SendAck(void)
{
  I2C->CONTROLC = I2C_CR_SCL;
  I2C->CONTROL = I2C_CR_SDA;
  I2C->CONTROL = I2C_CR_SCL;
  I2C->CONTROLC = I2C_CR_SCL;
  I2C->CONTROLC = I2C_CR_SDA;
}
 
/**
  * @param uint8_t register address
  * @param uint8_t serial address
  * @return uint8_t read one byte
  * @brief Write data stream and read one byte.
  */
uint8_t I2C_Read(uint8_t reg_addr,uint8_t s_addr)
{
  uint8_t rx_data;
  
  /* Start bit */
  I2C->CONTROL = I2C_CR_SDA | I2C_CR_SCL;
  I2C->CONTROLC = I2C_CR_SDA;
  
  /* Set serial and register address */
  I2C_SendByte(s_addr);
  I2C_ReceiveAck();
  I2C_SendByte(reg_addr);
  I2C_ReceiveAck();
  
  /* Start bit */
  I2C->CONTROL = I2C_CR_SDA | I2C_CR_SCL;
  I2C->CONTROLC = I2C_CR_SDA;
  
  /* Read from serial address */
  I2C_SendByte(s_addr | 0x01);
  I2C_ReceiveAck();
  rx_data = I2C_ReceiveByte();
  I2C_SendAck();
  
  /* Stop bit, clock the ack */
  I2C->CONTROL = I2C_CR_SCL;
  I2C->CONTROLC = I2C_CR_SCL;
  
  /* Actual stop bit */
  I2C->CONTROLC = I2C_CR_SDA;
  I2C->CONTROL = I2C_CR_SCL;
  I2C->CONTROL = I2C_CR_SDA;
  
  return rx_data;
}

/**
  * @param uint8_t register address
  * @param uint8_t data
  * @param uint8_t serial address
  * @return none
  * @brief Write data stream and write one byte.
  */
void I2C_Write(uint8_t reg_addr,uint8_t data_byte,uint8_t s_addr)
{
  /* Start bit */
  I2C->CONTROL = I2C_CR_SDA | I2C_CR_SCL;
  I2C->CONTROLC = I2C_CR_SDA;
  
  /* Set serial and register address */
  I2C_SendByte(s_addr);
  I2C_ReceiveAck();
  I2C_SendByte(reg_addr);
  I2C_ReceiveAck();
  I2C_SendByte(data_byte);
  
  /* Stop bit,clock the ack */
  I2C->CONTROL = I2C_CR_SCL;
  I2C->CONTROLC = I2C_CR_SCL;
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

