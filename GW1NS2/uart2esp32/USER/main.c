
/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2018 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			main.c
 * @author		Embedded Development Team
 * @version		V1.0.0
 * @date			2018-5-1 09:00:00
 * @brief			Main program body.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns2c.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void UartInit(void);
void TimerInit(TIMER_TypeDef* TIMERx);
void Delay_ms(__IO uint32_t delay_ms);
char* int2str(int num,char*str,int radix);

char buff[20];
volatile uint32_t counter;

int main()
{   
  int num=0;
  char c;
  char user_input[100];
	
	//Init System
	SystemInit();
	
  //Init Uart
  UartInit();
  UART_SendString(UART0,"\nUart Initial finished\n");
  UART_SendString(UART0,"\nTimer Initial:\n");
	
	//Init Timer
  TimerInit(TIMER0);
	
   //Dispaly the message
   counter=0;
   NVIC_EnableIRQ(TIMER0_IRQn);
   UART_SendString(UART0,"\nNVIC ENABLE IRQ TIMER0\n");
   TIMER_EnableIRQ(TIMER0);
   UART_SendString(UART0,"\nTIMER0 IRQ ENABLE\n");
   TIMER_StartTimer(TIMER0);
   UART_SendString(UART0,"\nSTART TIMER0\n");
	
   //WiFi Credentials Begin
			 
   while(1)
   {
       int i=0;
       while(c != '\n')
       {
    	   c = UART_ReceiveChar(UART0);
    	   user_input[i] = c;
    	   //UART_SendString(UART0, &c);//int2str(num,buff,10));
    	   i++;
       }

       c=-1; //clear '\n' return
       user_input[i]='\0'; //end string

       //Enter SSID:
       //Enter Password:
       //Enter HOST_ADDRESS:
       //Enter CLIENT_ID:
       //Enter TOPIC_NAME:
       //Enter RootCA:
       //Enter Device Certificate:
       //Enter Device Private Key:
       if     (strcmp("Enter SSID:\n",user_input)==0)
       {
    	   UART_SendString(UART0, "REPLACE_WITH_SSID!!!\n"); //Replace this with the SSID name for your network
       }
       else if(strcmp("Enter Password:\n",user_input)==0)
       {
    	   UART_SendString(UART0, "REPLACE_WITH_PW!!!\n"); //Replace with SSID password for your network
       }
       else if(strcmp("Enter HOST_ADDRESS:\n",user_input)==0)
       {
    	   UART_SendString(UART0, "a2pb2f9st3ros6-ats.iot.us-east-2.amazonaws.com\n");
       }
       else if(strcmp("Enter CLIENT_ID:\n",user_input)==0)
       {
    	   UART_SendString(UART0, "ESP32\n");
       }
       else if(strcmp("Enter TOPIC_NAME:\n",user_input)==0)
       {
    	   UART_SendString(UART0, "$aws/things/ESP32/shadow/update\n");
       }
       else if(strcmp("Enter RootCA:\n",user_input)==0)
       {
    	   UART_SendString(UART0,
    			   "-----BEGIN CERTIFICATE-----\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
----------------------------\n\
-----END CERTIFICATE-----\n");
       }
       else if(strcmp("Enter Device Certificate:\n",user_input)==0)
       {
    	   UART_SendString(UART0, "-----BEGIN CERTIFICATE-----\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-----END CERTIFICATE-----\n");
       }
       else if(strcmp("Enter Device Private Key:\n",user_input)==0)
       {
    	   UART_SendString(UART0, "-----BEGIN RSA PRIVATE KEY-----\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
-------------------REPLACE WITH CERT!!!-------------\n\
-----END RSA PRIVATE KEY-----\n");
       }
       /*else
       {
    	   UART_SendString(UART0, user_input);
       }*/
   }

}

void UartInit(void)
{
  UART_InitTypeDef UART_InitStruct;
	
  UART_InitStruct.UART_Mode.UARTMode_Tx = ENABLE;
  UART_InitStruct.UART_Mode.UARTMode_Rx = ENABLE;
  UART_InitStruct.UART_Int.UARTInt_Tx = DISABLE;
  UART_InitStruct.UART_Int.UARTInt_Rx = DISABLE;
  UART_InitStruct.UART_Ovr.UARTOvr_Tx = DISABLE;
  UART_InitStruct.UART_Ovr.UARTOvr_Rx = DISABLE;
  UART_InitStruct.UART_Hstm = DISABLE;
  UART_InitStruct.UART_BaudRate = 115200;//Baud Rate
	
  UART_Init(UART0,&UART_InitStruct);
}

void Delay_ms(__IO uint32_t delay_ms)
{
  for(delay_ms=delay_ms*8500; delay_ms != 0; delay_ms--);
}

void TimerInit(TIMER_TypeDef* TIMERx)
{ 
  TIMERx->INTCLEAR = 0;
  TIMER0->RELOAD=25000026;//Set the value of the Timmer 1s
  TIMER0->VALUE= TIMER0->RELOAD; //Set the init value
  TIMER0->CTRL=0;  // timmer interrupt
	
  UART_SendString(UART0,"TIMERx->INTCLEAR = 0;\n");
  UART_SendString(UART0,"TIMER0->RELOAD=25000026;\n");
  UART_SendString(UART0,"TIMERx->VALUE= TIMER0->RELOAD;\n");
  UART_SendString(UART0,"TIMERx->CTRL = 0;\n");
}

void TIMER0_Handler(void)
{
  if(TIMER_GetIRQStatus(TIMER0) != RESET)
  {
    counter++;
    TIMER_ClearIRQ(TIMER0);
  }
}

char* int2str(int num,char*str,int radix)
{
	char index[]="0123456789ABCDEF";
	unsigned unum;
	int i=0,j,k;
	char temp;

	if(radix==10&&num<0)
	{
		unum=(unsigned)-num;
		str[i++]='-';
	}
	else
	{
		unum=(unsigned)num;
	}

	do
	{
		str[i++]=index[unum%(unsigned)radix];
		unum/=radix;
	}while(unum);
	str[i]='\0';

	if(str[0]=='-')
	{
		k=1;
	}
	else
	{
		k=0;
	}
	
	for(j=k;j<=(i-1)/2;j++)
	{
		temp=str[j];
		str[j]=str[i-1+k-j];
		str[i-1+k-j]=temp;
	}
	
	return str;
}
