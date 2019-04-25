/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2018 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file		gw1ns2k_typec.h
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date		2018-5-1 09:00:00
 * @brief		This file contains all the functions prototypes for the USB Type-C firmware library.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GW1NS2K_TYPEC_H
#define __GW1NS2K_TYPEC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gw1ns2k.h"

/** @addtogroup GW1NS2K_StdPeriph_Driver
  * @{
  */

/** @addtogroup TYPEC
  * @{
  */

/** @defgroup TYPEC_Exported_Types
  * @{
  */

/* Type-C Initialization TypeDef */
typedef struct
{
  uint32_t TYPEC_Mode;    /* Type-C  transmission mode */
  
  uint32_t TYPEC_Pwr;      /* Type-C power supply mode */
  
}TYPEC_InitTypeDef;

/**
  * @}
  */

/** @defgroup GPIO_Exported_Macros
  * @{
  */

/* Type-C Mode Selection */
#define  TYPEC_MODE_TX            ((uint32_t) 0xFFFFFFFE)     /* Tx mode */
#define  TYPEC_MODE_RX            ((uint32_t) 0x00000001)     /* Rx mode */

/* Type-C Power Supply Selection */
#define TYPEC_PWR_VCC             ((uint32_t) 0xFFFFFFFD)    /* VCC supply    */
#define TYPEC_PWR_NORM            ((uint32_t) 0x00000002)    /* Normal supply */

/* TYPEC Register Bit Position */
#define TYPEC_CTRL_MODE_Pos        0  /* TYPEC CTRL mode selected bit position*/
#define TYPEC_CTRL_PWR_Pos         1  /* TYPEC CTRL power supply selected bit position */
#define TYPEC_CTRL_RD_Pos          2  /* TYPEC CTRL rd bit position */
#define TYPEC_CTRL_RP_Pos          3  /* TYPEC CTRL rp bit position */
#define TYPEC_CTRL_TX_INT_Pos      4  /* Reserved : TYPEC CTRL Tx Interrupt enable bit position */
#define TYPEC_CTRL_RX_INT_Pos      5  /* Reserved : TYPEC CTRL Rx Interrupt enable bit position */
#define TYPEC_TX_CTRL_BEGIN_Pos    0  /* TYPEC TX CTRL begin bit position */
#define TYPEC_TX_CTRL_END_Pos      1  /* TYPEC TX CTRL end bit position */
#define TYPEC_TX_STATUS_TACK_Pos   0  /* TYPEC TX STATUS tack bit position */
#define TYPEC_TX_STATUS_READY_Pos  1  /* TYPEC TX STATUS ready bit position */
#define TYPEC_TX_STATUS_TOE_Pos    2  /* TYPEC TX STATUS toe bit position */
#define TYPEC_TX_STATUS_BUSY_Pos   3  /* TYPEC TX STATUS busy bit position */
#define TYPEC_RX_STATUS_READY_Pos  0  /* TYPEC RX STATUS ready bit position */
#define TYPEC_RX_STATUS_REND_Pos   1  /* TYPEC RX STATUS rend bit position */
#define TYPEC_RX_STATUS_ROE_Pos    2  /* TYPEC RX STATUS roe bit position */
#define TYPEC_RX_STATUS_BUSY_Pos   3  /* TYPEC RX STATUS busy bit position */
#define TYPEC_INTSTATUS_TX_Pos     0  /* Reserved : TYPEC TX interrupt status */
#define TYPEC_INTSTATUS_RX_Pos     1  /* Reserved : TYPEC RX interrupt status */
#define TYPEC_INTCLEAR_TX_Pos      0  /* Reserved : TYPEC TX interrupt clear */
#define TYPEC_INTCLEAR_RX_Pos      1  /* Reserved : TYPEC RX interrupt clear */

/**
  * @}
  */

/** @defgroup GPIO_Exported_Functions
  * @{
  */

/**
  * @brief Type-C initialization.
  */
extern void TYPEC_Init(TYPEC_InitTypeDef* TYPEC_InitStruct);

/**
  * @brief Sets Tx begin enable.
  */
extern void TYPEC_SetTxBeginEnable(void);

/**
  * @brief Gets Tx begin status.
  */
extern FlagStatus TYPEC_GetTxBeginStatus(void);

/**
  * @brief Sets Tx end enable.
  */
extern void TYPEC_SetTxEndEnable(void);

/**
  * @brief Clears Tx end enable.
  */
extern void TYPEC_ClrTxEnd(void);

/**
  * @brief Gets Tx end status.
  */
extern FlagStatus TYPEC_GetTxEndStatus(void);

/**
  * @brief Sets Tx tack enable.
  */
extern void TYPEC_SetTxTackEnable(void);

/**
  * @brief Clears Tx tack enable.
  */
extern void TYPEC_ClrTxTackEnable(void);

/**
  * @brief Gets Tx tack status.
  */
extern FlagStatus TYPEC_GetTxTackStatus(void);

/**
  * @brief Sets Tx ready enable.
  */
extern void TYPEC_SetTxReadyEnable(void);

/**
  * @brief Clears Tx ready enable.
  */
extern void TYPEC_ClrTxReadyEnable(void);

/**
  * @brief Gets Tx ready status.
  */
extern FlagStatus TYPEC_GetTxReadyStatus(void);

/**
  * @brief Sets Tx toe enable.
  */
extern void TYPEC_SetTxToeEnable(void);

/**
  * @brief Clears Tx toe enable.
  */
extern void TYPEC_ClrTxToeEnable(void);

/**
  * @brief Gets Tx toe status.
  */
extern FlagStatus TYPEC_GetTxToeStatus(void);

/**
  * @brief Sets Tx busy enable.
  */
extern void TYPEC_SetTxBusyEnable(void);

/**
  * @brief Clears Tx busy enable.
  */
extern void TYPEC_ClrTxBusyEnable(void);

/**
  * @brief Gets Tx busy status.
  */
extern FlagStatus TYPEC_GetTxBusyStatus(void);

/**
  * @brief Sets Rx ready enable.
  */
extern void TYPEC_SetRxReadyEnable(void);

/**
  * @brief Clears Rx ready enable.
  */
extern void TYPEC_ClrRxReadyEnable(void);

/**
  * @brief Gets Rx ready status.
  */
extern FlagStatus TYPEC_GetRxReadyStatus(void);

/**
  * @brief Sets Rx rend enable.
  */
extern void TYPEC_SetRxRendEnable(void);

/**
  * @brief Clears Rx rend enable.
  */
extern void TYPEC_ClrRxRendEnable(void);

/**
  * @brief Gets Rx rend status.
  */
extern FlagStatus TYPEC_GetRxRendStatus(void);

/**
  * @brief Sets Rx roe enable.
  */
extern void TYPEC_SetRxRoeEnable(void);

/**
  * @brief Clears Rx roe enable.
  */
extern void TYPEC_ClrRxRoeEnable(void);

/**
  * @brief Gets Rx roe status.
  */
extern FlagStatus TYPEC_GetRxRoeStatus(void);

/**
  * @brief Sets Rx busy enable.
  */
extern void TYPEC_SetRxBusyEnable(void);

/**
  * @brief Clears Rx busy enable.
  */
extern void TYPEC_ClrRxBusyEnable(void);

/**
  * @brief Gets Rx busy status.
  */
extern FlagStatus TYPEC_GetRxBusyStatus(void);

/**
  * @brief Sets Type-C transmission mode.
  */
extern void TYPEC_SetTransMode(uint32_t TYPEC_Mode);

/**
  * @brief Gets Type-C transmission mode.
  */
extern uint32_t TYPEC_GetTransMode(void);

/**
  * @brief Sets Type-C transmission mode.
  */
extern void TYPEC_SetPwrSupply(uint32_t TYPEC_Pwr);

/**
  * @brief Gets Type-C power supply.
  */
extern uint32_t TYPEC_GetPwrSupply(void);

/**
  * @brief Sets Type-C Tx Data.
  */
extern ErrorStatus TYPEC_SetTxData(uint32_t value);

/**
  * @brief Sends Type-C data.
  */
extern ErrorStatus TYPEC_SendData(uint32_t* data,uint32_t size);

/**
  * @brief Returns RX DATA.
  */
extern uint32_t TYPEC_GetRxData(void);

/**
  * @brief Receives Type-C data.
  */
extern int TYPEC_ReceiveData(uint32_t* data);

/**
  * @brief Reserved : Enable Tx interrupt.
  */
extern void TYPEC_SetTxIntEnable(void);

/**
  * @brief Reserved : Enable Rx interrupt.
  */
extern void TYPEC_SetRxIntEnable(void);

/**
  * @brief Reserved : Get Tx interrupt status.
  */
extern FlagStatus TYPEC_GetTxIntStatus(void);

/**
  * @brief Reserved : Get Rx interrupt status.
  */
extern FlagStatus TYPEC_GetRxIntStatus(void);

/**
  * @brief Reserved : Clear Tx interrupt.
  */
extern void TYPEC_ClrTxIntEnable(void);

/**
  * @brief Reserved : Clear Rx interrupt.
  */
extern void TYPEC_ClrRxIntEnable(void);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif  /* __GW1NS2K_TYPEC_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************GowinSemiconductor******END OF FILE*******************/

