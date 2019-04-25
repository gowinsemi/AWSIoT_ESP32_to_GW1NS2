/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2018 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file		gw1ns2k_lcd1602.c
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date		2018-5-1 09:00:00
 * @brief		This file contains all the functions prototypes for LCD1602 Driver.
 ******************************************************************************************
 */

#include "gw1ns2k_lcd1602.h"
#include "gw1ns2k_gpio.h"

//Declaraction
static void Delay_ms(__IO uint32_t delay_s);
static void Set_GPIO(GPIO_TypeDef* GPIOx,uint32_t pinx);
static void Reset_GPIO(GPIO_TypeDef* GPIOx,uint32_t pinx);
static void Lcd_Disp_Char(uint8_t x,uint8_t y,uint8_t dat);
static void Lcd_Write_Dat(uint8_t dat);
static void Lcd_Write_Cmd(uint8_t cmd);
static void Set_Lcd_Data(GPIO_TypeDef* GPIOx,uint32_t data);

//The function of config the GPIO
void Lcd_Pin_Config(void)
{
    GPIO_InitTypeDef GPIO_init_struct;
    //set the using GPIO range of GPIO5-GPIO15
    GPIO_init_struct.GPIO_Pin=0xFFE0;
    //set the GPIO mode is output
    GPIO_init_struct.GPIO_Mode=GPIO_Mode_OUT;
    GPIO_Init(GPIO0,&GPIO_init_struct);
}

//Init the lcd
void Lcd_Init(void)
{
     Lcd_Write_Cmd(0x38);
     Lcd_Write_Cmd(0x0c);
     Lcd_Write_Cmd(0x06);     
     Lcd_Write_Cmd(0x01);
     Delay_ms(1);  
}

//Write string to LCD
void Lcd_Write_String(char *string,int y)
{
    int row;
    //clean the LCD
    y++;
    for(row=0;row<16;row++)
    {
        Lcd_Disp_Char(row,y,0x20);         
    }
    for(row=0;string[row]!='\0' && (row<16);row++)
    {
        Lcd_Disp_Char(row,y,string[row]);         
    }
}

//the delay function used 
//for the the sequential
//Lcd_Pin_Config/25M  8330000
//The max of delay_ms  is 
static void Delay_ms(__IO uint32_t delay_ms)
{
    for(delay_ms=delay_ms*8500; delay_ms != 0; delay_ms--);
}

//set the GPIO state is high level
static void Set_GPIO(GPIO_TypeDef* GPIOx,uint32_t pinx)
{
    GPIOx->DATAOUT |= (1<<pinx);   
}

//set the GPIO state is low level
static void Reset_GPIO(GPIO_TypeDef* GPIOx,uint32_t pinx)
{
    GPIOx->DATAOUT &= ~(1<<pinx) ;     
}

//set the date pin of LCD
static void Set_Lcd_Data(GPIO_TypeDef* GPIOx,uint32_t data)
{
    GPIOx->DATAOUT=0x00FF & GPIOx->DATAOUT;
    GPIOx->DATAOUT=GPIOx->DATAOUT | (data<<8);
}  

//write cmd to lcd
static void Lcd_Write_Cmd(uint8_t cmd)
{
                
    Reset_GPIO(GPIO0,LCD_RS);
    Reset_GPIO(GPIO0,LCD_RW);
    Set_Lcd_Data(GPIO0,cmd); 
    Delay_ms(1);
    Set_GPIO(GPIO0,LCD_EN);
    Delay_ms(1);
    Reset_GPIO(GPIO0,LCD_EN);
    Delay_ms(1);
}

//write dat to lcd
static void Lcd_Write_Dat(uint8_t dat)
{                
    Set_GPIO(GPIO0,LCD_RS);
    Reset_GPIO(GPIO0,LCD_RW);
    Set_Lcd_Data(GPIO0,dat); 
    Delay_ms(1);
    Set_GPIO(GPIO0,LCD_EN);
    Delay_ms(1);
    Reset_GPIO(GPIO0,LCD_EN);
    Delay_ms(1);
}

static void Lcd_Disp_Char(uint8_t x,uint8_t y,uint8_t dat)
{
    unsigned char address;    
    if(y==1) address=0x80+x;
    else     address=0xc0+x;
    Lcd_Write_Cmd(address);
    Lcd_Write_Dat(dat);
}

