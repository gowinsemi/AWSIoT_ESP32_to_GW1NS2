/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2018 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file		gw1ns2k_typec.c
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date		2018-5-1 09:00:00
 * @brief		This file contains all the functions prototypes for the TYPE-C firmware library.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns2k_typec.h"

/** @addtogroup GW1NS2K_StdPeriph_Driver
  * @{
  */

/** @defgroup TYPEC 
  * @brief TYPEC driver modules
  * @{
  */

/** @defgroup TYPC_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup TYPEC_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup TYPEC_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup TYPEC_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup TYPEC_Private_Functions
  * @{
  */

/**
  * @param TYPEC_InitTypeDef Pointer
  * @return none
  * @brief Initials type_c 
  */
void TYPEC_Init(TYPEC_InitTypeDef* TYPEC_InitStruct)
{
  TYPEC->CTRL = 0;
  TYPEC->TX_DATA = 0;
  TYPEC->TX_CTRL = 0;
  TYPEC->TX_STATUS = 0;
  TYPEC->RX_CTRL = 0;
  TYPEC->RX_STATUS = 0;

  /* Set CTRL register mode selection */
  if(TYPEC_InitStruct->TYPEC_Mode == TYPEC_MODE_TX)
  {
    TYPEC->CTRL &= TYPEC_MODE_TX;
	TYPEC->CTRL |= TYPEC_CTRL_RP;
  }
  else if(TYPEC_InitStruct->TYPEC_Mode == TYPEC_MODE_RX)
  {
    TYPEC->CTRL |= TYPEC_MODE_RX;
	TYPEC->CTRL |= TYPEC_CTRL_RD;
  }
  
  /* Set CTRL register power supply selection */
  if(TYPEC_InitStruct->TYPEC_Pwr == TYPEC_PWR_NORM)
  {
    TYPEC->CTRL |= TYPEC_PWR_NORM;
  }
  else if(TYPEC_InitStruct->TYPEC_Pwr == TYPEC_PWR_VCC)
  {
    TYPEC->CTRL &= TYPEC_PWR_VCC;
  }
}

/**
  * @param none
  * @return none
  * @brief Sets Tx begin enable.
  */
void TYPEC_SetTxBeginEnable(void)
{
  TYPEC->TX_CTRL |= TYPEC_TX_CTRL_BEGIN;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Gets Tx begin status.
  */
FlagStatus TYPEC_GetTxBeginStatus(void)
{
  return (FlagStatus)((TYPEC->TX_CTRL & TYPEC_TX_CTRL_BEGIN) >> TYPEC_TX_CTRL_BEGIN_Pos);
}

/**
  * @param none
  * @return none
  * @brief Sets Tx end enable.
  */
void TYPEC_SetTxEndEnable(void)
{
  TYPEC->TX_CTRL |= TYPEC_TX_CTRL_END;
}

/**
  * @param none
  * @return none
  * @brief Clears Tx end enable.
  */
void TYPEC_ClrTxEnd(void)
{
  TYPEC->TX_CTRL &= ~TYPEC_TX_CTRL_END;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Gets Tx end status.
  */
FlagStatus TYPEC_GetTxEndStatus(void)
{
  return (FlagStatus)((TYPEC->TX_CTRL & TYPEC_TX_CTRL_END) >> TYPEC_TX_CTRL_END_Pos);
}


/**
  * @param none
  * @return none
  * @brief Sets Tx tack enable.
  */
void TYPEC_SetTxTackEnable(void)
{
  TYPEC->TX_STATUS |= TYPEC_TX_STATUS_TACK;
}

/**
  * @param none
  * @return none
  * @brief Clears Tx tack enable.
  */
void TYPEC_ClrTxTackEnable(void)
{
  TYPEC->TX_STATUS &= ~TYPEC_TX_STATUS_TACK;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Gets Tx tack status.
  */
FlagStatus TYPEC_GetTxTackStatus(void)
{
  return (FlagStatus)((TYPEC->TX_STATUS & TYPEC_TX_STATUS_TACK) >> TYPEC_TX_STATUS_TACK_Pos);
}

/**
  * @param none
  * @return none
  * @brief Sets Tx ready enable.
  */
void TYPEC_SetTxReadyEnable(void)
{
  TYPEC->TX_STATUS |= TYPEC_TX_STATUS_READY;
}

/**
  * @param none
  * @return none
  * @brief Clears Tx ready enable.
  */
void TYPEC_ClrTxReadyEnable(void)
{
  TYPEC->TX_STATUS &= ~TYPEC_TX_STATUS_READY;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Gets Tx ready status.
  */
FlagStatus TYPEC_GetTxReadyStatus(void)
{
  return (FlagStatus)((TYPEC->TX_STATUS & TYPEC_TX_STATUS_READY) >> TYPEC_TX_STATUS_READY_Pos);
}

/**
  * @param none
  * @return none
  * @brief Sets Tx toe enable.
  */
void TYPEC_SetTxToeEnable(void)
{
  TYPEC->TX_STATUS |= TYPEC_TX_STATUS_TOE;
}

/**
  * @param none
  * @return none
  * @brief Clears Tx toe enable.
  */
void TYPEC_ClrTxToeEnable(void)
{
  TYPEC->TX_STATUS &= ~TYPEC_TX_STATUS_TOE;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Gets Tx toe status.
  */
FlagStatus TYPEC_GetTxToeStatus(void)
{
  return (FlagStatus)((TYPEC->TX_STATUS & TYPEC_TX_STATUS_TOE) >> TYPEC_TX_STATUS_TOE_Pos);
}

/**
  * @param none
  * @return none
  * @brief Sets Tx busy enable.
  */
void TYPEC_SetTxBusyEnable(void)
{
  TYPEC->TX_STATUS |= TYPEC_TX_STATUS_BUSY;
}

/**
  * @param none
  * @return none
  * @brief Clears Tx busy enable.
  */
void TYPEC_ClrTxBusyEnable(void)
{
  TYPEC->TX_STATUS &= ~TYPEC_TX_STATUS_BUSY;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Gets Tx busy status.
  */
FlagStatus TYPEC_GetTxBusyStatus(void)
{
  return (FlagStatus)((TYPEC->TX_STATUS & TYPEC_TX_STATUS_BUSY) >> TYPEC_TX_STATUS_BUSY_Pos);
}

/**
  * @param none
  * @return none
  * @brief Sets Rx ready enable.
  */
void TYPEC_SetRxReadyEnable(void)
{
  TYPEC->RX_STATUS |= TYPEC_RX_STATUS_READY;
}

/**
  * @param none
  * @return none
  * @brief Clears Rx ready enable.
  */
void TYPEC_ClrRxReadyEnable(void)
{
  TYPEC->RX_STATUS &= ~TYPEC_RX_STATUS_READY;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Gets Rx ready status.
  */
FlagStatus TYPEC_GetRxReadyStatus(void)
{
  return (FlagStatus)((TYPEC->RX_STATUS & TYPEC_RX_STATUS_READY) >> TYPEC_RX_STATUS_READY_Pos);
}

/**
  * @param none
  * @return none
  * @brief Sets Rx rend enable.
  */
void TYPEC_SetRxRendEnable(void)
{
  TYPEC->RX_STATUS |= TYPEC_RX_STATUS_REND;
}

/**
  * @param none
  * @return none
  * @brief Clears Rx rend enable.
  */
void TYPEC_ClrRxRendEnable(void)
{
  TYPEC->RX_STATUS &= ~TYPEC_RX_STATUS_REND;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Gets Rx rend status.
  */
FlagStatus TYPEC_GetRxRendStatus(void)
{
  return (FlagStatus)((TYPEC->RX_STATUS & TYPEC_RX_STATUS_REND) >> TYPEC_RX_STATUS_REND_Pos);
}

/**
  * @param none
  * @return none
  * @brief Sets Rx roe enable.
  */
void TYPEC_SetRxRoeEnable(void)
{
  TYPEC->RX_STATUS |= TYPEC_RX_STATUS_ROE;
}

/**
  * @param none
  * @return none
  * @brief Clears Rx roe enable.
  */
void TYPEC_ClrRxRoeEnable(void)
{
  TYPEC->RX_STATUS &= ~TYPEC_RX_STATUS_ROE;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Gets Rx roe status.
  */
FlagStatus TYPEC_GetRxRoeStatus(void)
{
  return (FlagStatus)((TYPEC->RX_STATUS & TYPEC_RX_STATUS_ROE) >> TYPEC_RX_STATUS_ROE_Pos);
}

/**
  * @param none
  * @return none
  * @brief Sets Rx busy enable.
  */
void TYPEC_SetRxBusyEnable(void)
{
  TYPEC->RX_STATUS |= TYPEC_RX_STATUS_BUSY;
}

/**
  * @param none
  * @return none
  * @brief Clears Rx busy enable.
  */
void TYPEC_ClrRxBusyEnable(void)
{
  TYPEC->RX_STATUS &= ~TYPEC_RX_STATUS_BUSY;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Gets Rx busy status.
  */
FlagStatus TYPEC_GetRxBusyStatus(void)
{
  return (FlagStatus)((TYPEC->RX_STATUS & TYPEC_RX_STATUS_BUSY) >> TYPEC_RX_STATUS_BUSY_Pos);
}

/**
  * @param uint32_t TYPEC Mode
  *       @arg TYPEC_MODE_TX
  *       @arg TYPEC_MODE_RX
  * @return none
  * @brief Sets Type-C transmission mode.
  */
void TYPEC_SetTransMode(uint32_t TYPEC_Mode)
{
  if(TYPEC_Mode == TYPEC_MODE_TX)
  {
    TYPEC->CTRL &= TYPEC_MODE_TX;
	TYPEC->CTRL |= TYPEC_CTRL_RP;
  }
  else if(TYPEC_Mode == TYPEC_MODE_RX)
  {
    TYPEC->CTRL |= TYPEC_MODE_RX;
	TYPEC->CTRL |= TYPEC_CTRL_RD;
  }  
}

/**
  * @param none
  * @return uint32_t TYPEC Mode
  *         @arg TYPEC_MODE_TX
  *         @arg TYPEC_MODE_RX
  * @brief Gets Type-C transmission mode.
  */
uint32_t TYPEC_GetTransMode(void)
{
  if((TYPEC->CTRL&TYPEC_CTRL_MODE)==TYPEC_CTRL_MODE)
  {
    return TYPEC_MODE_RX;
  }
  else
  {
    return TYPEC_MODE_TX;
  }
}

/**
  * @parm uint32_t TYPEC Power Supply
  *       @arg TYPEC_PWR_VCC
  *       @arg TYPEC_PWR_NORM
  * @return none
  * @brief Sets Type-C transmission mode.
  */
void TYPEC_SetPwrSupply(uint32_t TYPEC_Pwr)
{
  if(TYPEC_Pwr == TYPEC_PWR_NORM)
  {
    TYPEC->CTRL |= TYPEC_PWR_NORM;
  }
  else if(TYPEC_Pwr == TYPEC_PWR_VCC)
  {
    TYPEC->CTRL &= TYPEC_PWR_VCC;
  } 
}

/**
  * @param none
  * @return uint32_t TYPEC Power Supply
  *         @arg TYPEC_PWR_VCC
  *         @arg TYPEC_PWR_NORM
  * @brief Gets Type-C power supply.
  */
uint32_t TYPEC_GetPwrSupply(void)
{
  if((TYPEC->CTRL&TYPEC_CTRL_PWR)==TYPEC_CTRL_PWR)
  {
    return TYPEC_PWR_NORM;  
  }
  else
  {
    return TYPEC_PWR_VCC;
  }
}

/**
  * @param none
  * @param uint32_t value
  * @return ErrorStatus
  *         @arg ERROR
  *         @arg SUCCESS
  * @brief Sets Type-C Tx Data.
  */
ErrorStatus TYPEC_SetTxData(uint32_t value)
{
  /* Waits until the processor is ready */
  while(TYPEC_GetTxReadyStatus()==RESET);
  
  /* Sends data if no transmission error */
  if(TYPEC_GetTxToeStatus()==RESET)
  {
	/* Transmitting data */
    TYPEC->TX_DATA = value;
  }
  
  if(TYPEC_GetTxToeStatus()==RESET)
  {
	return SUCCESS;
  }
  
  return ERROR;
}

/**
  * @param uint32_t* sends a site of data
  * @param uint32_t data size
  * @return ErrorStatus 
  *         @arg ERROR
  *         @arg SUCCESS
  * @brief Sends Type-C data.
  */
ErrorStatus TYPEC_SendData(uint32_t* data,uint32_t size)
{
  uint32_t i = 0;
  
  /* Sets transmission mode */
  TYPEC_SetTransMode(TYPEC_MODE_TX);
  
  /* Waits until the processor is idle */
  while((TYPEC_GetTxBusyStatus()==SET) || (TYPEC_GetRxBusyStatus()==SET));
  
  /* Begin to send data */
  TYPEC_SetTxBeginEnable();
  
  /* Sets Tx status */
  TYPEC_SetTxReadyEnable();  /* Ready */
  TYPEC_SetTxTackEnable();   /* Transmitting */
  TYPEC_SetTxBusyEnable();   /* Busy */
  TYPEC_ClrTxToeEnable();    /* Right */
  
  /* Sends a site of data */
  for(i = 0;i < size;i++)
  {
    if(TYPEC_SetTxData(data[i])==ERROR)
	{
      return ERROR;
	}
	
	TYPEC_SetTxReadyEnable();
  }
  
  /* End to send data */
  TYPEC_SetTxEndEnable();
  
  /* Sets Tx status */
  TYPEC_SetTxReadyEnable();
  TYPEC_ClrTxTackEnable();
  TYPEC_ClrTxBusyEnable();
  
  return SUCCESS;
}

/**
  * @param none
  * @return RX DATA
  * @brief Returns RX DATA.
  */
uint32_t TYPEC_GetRxData(void)
{
  return TYPEC->RX_DATA;
}

/**
  * @param uint32_t* receives a site of data
  * @return int Data index
  * @brief Receives Type-C data.
  */
int TYPEC_ReceiveData(uint32_t* data)
{
  int data_idx = 0;
  FlagStatus ready=SET,end=RESET;
  
  /* Sets transmission mode */
  TYPEC_SetTransMode(TYPEC_MODE_RX);
  
  /* Waits until the processor is idle */
  while((TYPEC_GetTxBusyStatus()==SET) || (TYPEC_GetRxBusyStatus()==SET));
  
  /* Waits until the processor is ready */
  while(TYPEC_GetRxReadyStatus()==RESET);
  
  /* Set Rx status */
  TYPEC_SetRxBusyEnable();
  
  /* Receive data until ending */
  while(ready==SET)
  {
    data[data_idx++] = TYPEC_GetRxData();

    if(TYPEC_GetRxRoeStatus()==SET)
	{
      return -1;
	}
	
	data_idx++;

    if(end==SET)
    {
      return data_idx;
    }

    do
    {
      /* Wait until the processor ready or end */
      ready = TYPEC_GetRxReadyStatus();
      end = TYPEC_GetRxRendStatus();
    }while(((!ready)&&(!end))||((!ready)&&end));
  }
  
  /* Reset Rx status */
  TYPEC_ClrRxBusyEnable();
  
  return 1;
}

/**
  * @param none
  * @return none
  * @brief Enable Tx interrupt.
  */
void TYPEC_SetTxIntEnable(void)
{
  TYPEC->CTRL |= TYPEC_CTRL_TX_INT;
}

/**
  * @param none
  * @return none
  * @brief Enable Rx interrupt.
  */
void TYPEC_SetRxIntEnable(void)
{
  TYPEC->CTRL |= TYPEC_CTRL_RX_INT;
}

/**
  * @param none
  * @return FlagStatus SET or RESET
  * @brief Get Tx interrupt status.
  */
FlagStatus TYPEC_GetTxIntStatus(void)
{
  return (FlagStatus)((TYPEC->INTSTATUS & TYPEC_INTSTATUS_TX) >> TYPEC_INTSTATUS_TX_Pos);
}

/**
  * @param none
  * @return none
  * @brief Get Rx interrupt status.
  */
FlagStatus TYPEC_GetRxIntStatus(void)
{
  return (FlagStatus)((TYPEC->INTSTATUS & TYPEC_INTSTATUS_RX) >> TYPEC_INTSTATUS_RX_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clear Tx interrupt.
  */
void TYPEC_ClrTxIntEnable(void)
{
  TYPEC->INTCLEAR |= TYPEC_INTCLEAR_TX;
}

/**
  * @param none
  * @return none
  * @brief Clear Rx interrupt.
  */
void TYPEC_ClrRxIntEnable(void)
{
  TYPEC->INTCLEAR |= TYPEC_INTCLEAR_RX;
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

