/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2018 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file		gw1ns2k_imonitor.c
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date		2018-5-1 09:00:00
 * @brief		This file contains all the functions prototypes for the INT_MONITOR firmware library.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns2k_imonitor.h"

/** @addtogroup GW1NS2K_StdPeriph_Driver
  * @{
  */

/** @defgroup IMONITOR
  * @brief IMONITOR driver modules
  * @{
  */

/** @defgroup IMONITOR_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup IMONITOR_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup IMONITOR_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup IMONITOR_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup IMONITOR_Private_Functions
  * @{
  */

/**
  * @param none
  * @return none
  * @brief Initials Interrupt Monitor.
  */
void IMONITOR_Init(void)
{
  IMONITOR->INTSTATUS = 0;
}

/**
  * @param none
  * @return none
  * @brief Clears Interrupt Monitor.
  */
void IMONITOR_Clr(void)
{
  IMONITOR->INTSTATUS = 0;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_0 interrupt status.
  */
void IMONITOR_SetGPIO0Pin0IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_0;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_0 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin0IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_0) >> IMONITOR_INTSTATUS_GPIO0_0_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_0 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin0IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_0;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_1 interrupt status.
  */
void IMONITOR_SetGPIO0Pin1IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_1;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_1 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin1IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_1) >> IMONITOR_INTSTATUS_GPIO0_1_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_1 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin1IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_1;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_2 interrupt status.
  */
void IMONITOR_SetGPIO0Pin2IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_2;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_2 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin2IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_2) >> IMONITOR_INTSTATUS_GPIO0_2_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_2 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin2IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_2;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_3 interrupt status.
  */
void IMONITOR_SetGPIO0Pin3IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_3;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_3 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin3IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_3) >> IMONITOR_INTSTATUS_GPIO0_3_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_3 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin3IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_3;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_4 interrupt status.
  */
void IMONITOR_SetGPIO0Pin4IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_4;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_4 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin4IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_4) >> IMONITOR_INTSTATUS_GPIO0_4_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_4 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin4IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_4;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_5 interrupt status.
  */
void IMONITOR_SetGPIO0Pin5IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_5;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_5 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin5IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_5) >> IMONITOR_INTSTATUS_GPIO0_5_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_5 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin5IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_5;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_6 interrupt status.
  */
void IMONITOR_SetGPIO0Pin6IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_6;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_6 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin6IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_6) >> IMONITOR_INTSTATUS_GPIO0_6_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_6 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin6IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_6;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_7 interrupt status.
  */
void IMONITOR_SetGPIO0Pin7IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_7;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_7 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin7IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_7) >> IMONITOR_INTSTATUS_GPIO0_7_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_7 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin7IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_7;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_8 interrupt status.
  */
void IMONITOR_SetGPIO0Pin8IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_8;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_8 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin8IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_8) >> IMONITOR_INTSTATUS_GPIO0_8_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_8 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin8IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_8;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_9 interrupt status.
  */
void IMONITOR_SetGPIO0Pin9IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_9;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_9 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin9IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_9) >> IMONITOR_INTSTATUS_GPIO0_9_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_9 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin9IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_9;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_10 interrupt status.
  */
void IMONITOR_SetGPIO0Pin10IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_10;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_10 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin10IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_10) >> IMONITOR_INTSTATUS_GPIO0_10_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_10 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin10IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_10;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_11 interrupt status.
  */
void IMONITOR_SetGPIO0Pin11IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_11;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_11 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin11IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_11) >> IMONITOR_INTSTATUS_GPIO0_11_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_11 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin11IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_11;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_12 interrupt status.
  */
void IMONITOR_SetGPIO0Pin12IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_12;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_12 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin12IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_12) >> IMONITOR_INTSTATUS_GPIO0_12_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_12 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin12IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_12;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_13 interrupt status.
  */
void IMONITOR_SetGPIO0Pin13IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_13;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_13 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin13IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_13) >> IMONITOR_INTSTATUS_GPIO0_13_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_13 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin13IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_13;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_14 interrupt status.
  */
void IMONITOR_SetGPIO0Pin14IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_14;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_14 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin14IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_14) >> IMONITOR_INTSTATUS_GPIO0_14_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_14 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin14IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_14;
}

/**
  * @param none
  * @return none
  * @brief Sets GPIO0_15 interrupt status.
  */
void IMONITOR_SetGPIO0Pin15IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_GPIO0_15;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns GPIO0_15 interrupt status.
  */
FlagStatus IMONITOR_GetGPIO0Pin15IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_GPIO0_15) >> IMONITOR_INTSTATUS_GPIO0_15_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears GPIO0_15 interrupt status.
  */
void IMONITOR_ClrGPIO0Pin15IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_GPIO0_15;
}

/**
  * @param none
  * @return none
  * @brief Sets TIMER_0 interrupt status.
  */
void IMONITOR_SetTIMER0IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_TIMER_0;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns TIMER_0 interrupt status.
  */
FlagStatus IMONITOR_GetTIMER0IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_TIMER_0) >> IMONITOR_INTSTATUS_TIMER_0_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears TIMER_0 interrupt status.
  */
void IMONITOR_ClrTIMER0IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_TIMER_0;
}

/**
  * @param none
  * @return none
  * @brief Sets TIMER_1 interrupt status.
  */
void IMONITOR_SetTIMER1IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_TIMER_1;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns TIMER_1 interrupt status.
  */
FlagStatus IMONITOR_GetTIMER1IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_TIMER_1) >> IMONITOR_INTSTATUS_TIMER_1_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears TIMER_1 interrupt status.
  */
void IMONITOR_ClrTIMER1IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_TIMER_1;
}

/**
  * @param none
  * @return none
  * @brief Sets UART_0 interrupt status.
  */
void IMONITOR_SetUART0IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_UART_0;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns UART_0 interrupt status.
  */
FlagStatus IMONITOR_GetUART0IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_UART_0) >> IMONITOR_INTSTATUS_UART_0_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears UART_0 interrupt status.
  */
void IMONITOR_ClrUART0IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_UART_0;
}

/**
  * @param none
  * @return none
  * @brief Sets UART_1 interrupt status.
  */
void IMONITOR_SetUART1IntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_UART_1;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns UART_1 interrupt status.
  */
FlagStatus IMONITOR_GetUART1IntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_UART_1) >> IMONITOR_INTSTATUS_UART_1_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears UART_1 interrupt status.
  */
void IMONITOR_ClrUART1IntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_UART_1;
}

/**
  * @param none
  * @return none
  * @brief Sets WatchDog interrupt status.
  */
void IMONITOR_SetWDOGIntStatus(void)
{
  IMONITOR->INTSTATUS |= IMONITOR_INTSTATUS_WDOG;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns WatchDog interrupt status.
  */
FlagStatus IMONITOR_GetWDOGIntStatus(void)
{
  return (FlagStatus)((IMONITOR->INTSTATUS & IMONITOR_INTSTATUS_WDOG) >> IMONITOR_INTSTATUS_WDOG_Pos);
}

/**
  * @param none
  * @return none
  * @brief Clears WatchDog interrupt status.
  */
void IMONITOR_ClrWDOGIntStatus(void)
{
  IMONITOR->INTSTATUS &= ~IMONITOR_INTSTATUS_WDOG;
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

