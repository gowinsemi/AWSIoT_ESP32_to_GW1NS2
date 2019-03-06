/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2018 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			gw1ns2c_imonitor.h
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date			2018-5-1 09:00:00
 * @brief			This file contains all the functions prototypes for the INT_MONITOR firmware library.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GW1NS2C_IMONITOR_H
#define __GW1NS2C_IMONITOR_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gw1ns2c.h"

/** @addtogroup GW1NS2C_StdPeriph_Driver
  * @{
  */

/** @addtogroup IMONITOR
  * @{
  */

/** @defgroup IMONITOR_Exported_Types
  * @{
  */

/**
  * @}
  */

/** @defgroup IMONITOR_Exported_Macros
  * @{
  */

#define IMONITOR_INTSTATUS_GPIO0_0_Pos    0    /* GPIO0_0 Interrupt Status bit position    */
#define IMONITOR_INTSTATUS_GPIO0_1_Pos    1    /* GPIO0_1 Interrupt Status bit position    */
#define IMONITOR_INTSTATUS_GPIO0_2_Pos    2    /* GPIO0_2 Interrupt Status bit position    */
#define IMONITOR_INTSTATUS_GPIO0_3_Pos    3    /* GPIO0_3 Interrupt Status bit position    */
#define IMONITOR_INTSTATUS_GPIO0_4_Pos    4    /* GPIO0_4 Interrupt Status bit position    */
#define IMONITOR_INTSTATUS_GPIO0_5_Pos    5    /* GPIO0_5 Interrupt Status bit position    */
#define IMONITOR_INTSTATUS_GPIO0_6_Pos    6    /* GPIO0_6 Interrupt Status bit position    */
#define IMONITOR_INTSTATUS_GPIO0_7_Pos    7    /* GPIO0_7 Interrupt Status bit position    */
#define IMONITOR_INTSTATUS_GPIO0_8_Pos    8    /* GPIO0_8 Interrupt Status bit position    */
#define IMONITOR_INTSTATUS_GPIO0_9_Pos    9    /* GPIO0_9 Interrupt Status bit position    */
#define IMONITOR_INTSTATUS_GPIO0_10_Pos   10   /* GPIO0_10 Interrupt Status bit position   */
#define IMONITOR_INTSTATUS_GPIO0_11_Pos   11   /* GPIO0_11 Interrupt Status bit position   */
#define IMONITOR_INTSTATUS_GPIO0_12_Pos   12   /* GPIO0_12 Interrupt Status bit position   */
#define IMONITOR_INTSTATUS_GPIO0_13_Pos   13   /* GPIO0_13 Interrupt Status bit position   */
#define IMONITOR_INTSTATUS_GPIO0_14_Pos   14   /* GPIO0_14 Interrupt Status bit position   */
#define IMONITOR_INTSTATUS_GPIO0_15_Pos   15   /* GPIO0_15 Interrupt Status bit position   */
#define IMONITOR_INTSTATUS_TIMER_0_Pos    16   /* Timer0 Interrupt Status bit position     */
#define IMONITOR_INTSTATUS_TIMER_1_Pos    17   /* Timer1 Interrupt Status bit position     */
#define IMONITOR_INTSTATUS_UART_0_Pos     18   /* Uart0 Interrupt Status bit position      */
#define IMONITOR_INTSTATUS_UART_1_Pos     19   /* Uart1 Interrupt Status bit position      */
#define IMONITOR_INTSTATUS_WDOG_Pos       20   /* WatchDog Interrupt Status bit position   */

/**
  * @}
  */

/** @defgroup IMONITOR_Exported_Functions
  * @{
  */

/**
  * @brief Initial Int Monitor
  */
extern void IMONITOR_Init(void);

/**
  * @brief Clears Interrupt Monitor.
  */
extern void IMONITOR_Clr(void);

/**
  * @brief Sets GPIO0_0 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin0IntStatus(void);

/**
  * @brief Returns GPIO0_0 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin0IntStatus(void);

/**
  * @brief Clears GPIO0_0 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin0IntStatus(void);

/**
  * @brief Sets GPIO0_1 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin1IntStatus(void);

/**
  * @brief Returns GPIO0_1 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin1IntStatus(void);

/**
  * @brief Clears GPIO0_1 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin1IntStatus(void);

/**
  * @brief Sets GPIO0_2 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin2IntStatus(void);

/**
  * @brief Returns GPIO0_2 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin2IntStatus(void);

/**
  * @brief Clears GPIO0_2 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin2IntStatus(void);

/**
  * @brief Sets GPIO0_3 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin3IntStatus(void);

/**
  * @brief Returns GPIO0_3 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin3IntStatus(void);

/**
  * @brief Clears GPIO0_3 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin3IntStatus(void);

/**
  * @brief Sets GPIO0_4 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin4IntStatus(void);

/**
  * @brief Returns GPIO0_4 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin4IntStatus(void);

/**
  * @brief Clears GPIO0_4 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin4IntStatus(void);

/**
  * @brief Sets GPIO0_5 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin5IntStatus(void);

/**
  * @brief Returns GPIO0_5 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin5IntStatus(void);

/**
  * @brief Clears GPIO0_5 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin5IntStatus(void);

/**
  * @brief Sets GPIO0_6 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin6IntStatus(void);

/**
  * @brief Returns GPIO0_6 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin6IntStatus(void);

/**
  * @brief Clears GPIO0_6 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin6IntStatus(void);

/**
  * @brief Sets GPIO0_7 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin7IntStatus(void);

/**
  * @brief Returns GPIO0_7 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin7IntStatus(void);

/**
  * @brief Clears GPIO0_7 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin7IntStatus(void);

/**
  * @brief Sets GPIO0_8 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin8IntStatus(void);

/**
  * @brief Returns GPIO0_8 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin8IntStatus(void);

/**
  * @brief Clears GPIO0_8 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin8IntStatus(void);

/**
  * @brief Sets GPIO0_9 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin9IntStatus(void);

/**
  * @brief Returns GPIO0_9 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin9IntStatus(void);

/**
  * @brief Clears GPIO0_9 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin9IntStatus(void);

/**
  * @brief Sets GPIO0_10 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin10IntStatus(void);

/**
  * @brief Returns GPIO0_10 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin10IntStatus(void);

/**
  * @brief Clears GPIO0_10 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin10IntStatus(void);

/**
  * @brief Sets GPIO0_11 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin11IntStatus(void);

/**
  * @brief Returns GPIO0_11 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin11IntStatus(void);

/**
  * @brief Clears GPIO0_11 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin11IntStatus(void);

/**
  * @brief Sets GPIO0_12 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin12IntStatus(void);

/**
  * @brief Returns GPIO0_12 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin12IntStatus(void);

/**
  * @brief Clears GPIO0_12 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin12IntStatus(void);

/**
  * @brief Sets GPIO0_13 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin13IntStatus(void);

/**
  * @brief Returns GPIO0_13 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin13IntStatus(void);

/**
  * @brief Clears GPIO0_13 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin13IntStatus(void);

/**
  * @brief Sets GPIO0_14 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin14IntStatus(void);

/**
  * @brief Returns GPIO0_14 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin14IntStatus(void);

/**
  * @brief Clears GPIO0_14 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin14IntStatus(void);

/**
  * @brief Sets GPIO0_15 interrupt status
  */
extern void IMONITOR_SetGPIO0Pin15IntStatus(void);

/**
  * @brief Returns GPIO0_15 interrupt status
  */
extern FlagStatus IMONITOR_GetGPIO0Pin15IntStatus(void);

/**
  * @brief Clears GPIO0_15 interrupt status
  */
extern void IMONITOR_ClrGPIO0Pin15IntStatus(void);

/**
  * @brief Sets TIMER_0 interrupt status
  */
extern void IMONITOR_SetTIMER0IntStatus(void);

/**
  * @brief Returns TIMER_0 interrupt status
  */
extern FlagStatus IMONITOR_GetTIMER0IntStatus(void);

/**
  * @brief Clears TIMER_0 interrupt status
  */
extern void IMONITOR_ClrTIMER0IntStatus(void);

/**
  * @brief Sets TIMER_1 interrupt status
  */
extern void IMONITOR_SetTIMER1IntStatus(void);

/**
  * @brief Returns TIMER_1 interrupt status
  */
extern FlagStatus IMONITOR_GetTIMER1IntStatus(void);

/**
  * @brief Clears TIMER_1 interrupt status
  */
extern void IMONITOR_ClrTIMER1IntStatus(void);

/**
  * @brief Sets UART_0 interrupt status
  */
extern void IMONITOR_SetUART0IntStatus(void);

/**
  * @brief Returns UART_0 interrupt status
  */
extern FlagStatus IMONITOR_GetUART0IntStatus(void);

/**
  * @brief Clears UART_0 interrupt status
  */
extern void IMONITOR_ClrUART0IntStatus(void);

/**
  * @brief Sets UART_1 interrupt status
  */
extern void IMONITOR_SetUART1IntStatus(void);

/**
  * @brief Returns UART_1 interrupt status
  */
extern FlagStatus IMONITOR_GetUART1IntStatus(void);

/**
  * @brief Clears UART_1 interrupt status
  */
extern void IMONITOR_ClrUART1IntStatus(void);

/**
  * @brief Sets WatchDog interrupt status
  */
extern void IMONITOR_SetWDOGIntStatus(void);

/**
  * @brief Returns WatchDog interrupt status
  */
extern FlagStatus IMONITOR_GetWDOGIntStatus(void);

/**
  * @brief Clears WatchDog interrupt status
  */
extern void IMONITOR_ClrWDOGIntStatus(void);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __GW1NS2C_IMONITOR_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************GowinSemiconductor******END OF FILE*******************/

