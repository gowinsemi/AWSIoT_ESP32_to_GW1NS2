/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2018 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file		gw1ns2k_lcd1602.h
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date		2018-5-1 09:00:00
 * @brief		This file contains all the functions prototypes for the LCD1602 Driver.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GW1NS2K_LCD1602_H
#define __GW1NS2K_LCD1602_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gw1ns2k.h"

#define LCD_RS 5
#define LCD_EN 7
#define LCD_RW 6

//The declaration  of function 
//config the LCD_PIN
extern void Lcd_Pin_Config(void);

//init the lcd
extern void Lcd_Init(void);

//write string to led
extern void Lcd_Write_String(char *string,int y);

#ifdef __cplusplus
}
#endif

#endif  /* __GW1NS2K_LCD1602_H */

