/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2018 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file		gw1ns2k_it.h
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date		2018-5-1 09:00:00
 * @brief		This file contains the headers of the interrupt handlers.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GW1NS2K_IT_H
#define __GW1NS2K_IT_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gw1ns2k.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

/* Core Exceptions Handler */
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

/* StdPeriph Interrupts Handler */
void USER_INT0_Handler(void);
void USER_INT1_Handler(void);
void UART0_Handler(void);
void UART1_Handler(void);
void TIMER0_Handler(void);
void TIMER1_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __GW1NS2K_IT_H */

/*************************GowinSemiconductor*****END OF FILE*********************/

