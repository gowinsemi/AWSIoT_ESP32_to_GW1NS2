
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
#include "gw1ns2c_gpio.h"

uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void UartInit(void);
void TimerInit(TIMER_TypeDef* TIMERx);
void Delay_ms(__IO uint32_t delay_ms);
char* int2str(int num,char*str,int radix);
void Delay(__IO uint32_t nCount)//25M 1s = 8333000
{
	for(; nCount != 0; nCount--);
}

const char SSID[]	=	"iPhone\n";
const char PW[]		=	"iphone123\n";
const char URL[]	=	"a2pb2f9st3ros6-ats.iot.us-east-2.amazonaws.com\n";
const char THING[]	=	"ESP32\n";
const char ROOTCA[]	=	"-----BEGIN CERTIFICATE-----\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
...
-------------------REPLACE WITH CERT!!!-------------------------\n\
-----END CERTIFICATE-----\r";

const char DEVICECERT[]	=	"-----BEGIN CERTIFICATE-----\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
...
-------------------REPLACE WITH CERT!!!-------------------------\n\
-----END CERTIFICATE-----\r";

const char DEVICEKEY []	=	"-----BEGIN RSA PRIVATE KEY-----\n\
-------------------REPLACE WITH CERT!!!-------------------------\n\
...
-------------------REPLACE WITH CERT!!!-------------------------\n\
-----END RSA PRIVATE KEY-----\r";

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
  //UART_SendString(UART0,"\nTimer Initial:\n");

  /* Initial all register to zero */
  GPIO0->DATA = 0;
  GPIO0->DATAOUT = 0;
  GPIO0->OUTENSET = 0;
  GPIO0->OUTENCLR = 0;
  GPIO0->ALTFUNCSET = 0;
  GPIO0->ALTFUNCCLR = 0;
  GPIO0->INTENSET = 0;
  GPIO0->INTENCLR = 0;
  GPIO0->INTTYPESET = 0;
  GPIO0->INTTYPECLR = 0;
  GPIO0->INTPOLSET = 0;
  GPIO0->INTPOLCLR = 0;
  GPIO0->INTCLEAR = 0;
  for(int pos = 0;pos < 256;pos++)
  {
	  GPIO0->MASKLOWBYTE[pos] = 0;
	  GPIO0->MASKHIGHBYTE[pos] = 0;
  }

	GPIO0->OUTENSET = 0xFFFFFFEF;
	GPIO0->OUTENCLR = 0x00000080;

	
   //Dispaly the message
   counter=0;

	
   //WiFi Credentials Begin
   //1 Enter SSID:
   //2 Enter Password:
   //3 Enter HOST_ADDRESS:
   //4 Enter CLIENT_ID:
   //5 Enter TOPIC_NAME:
   //6 Enter RootCA:
   //7 Enter Device Certificate:
   //8 Enter Device Private Key:
   //int DONE = 0;
   while(num<9)
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


       if     ((strcmp("1\n",user_input)==0))// && (num<1))
       {
    	   UART_SendString(UART0, SSID);
    	   num=2;
       }
       else if((strcmp("2\n",user_input)==0) && (num==2))
       {
    	   UART_SendString(UART0, PW);
    	   num=3;
       }
       else if((strcmp("3\n",user_input)==0) && (num==3))
       {
    	   UART_SendString(UART0, URL);
    	   num=4;
       }
       else if((strcmp("4\n",user_input)==0) && (num==4))
       {
    	   UART_SendString(UART0, THING);
    	   num=5;
       }
       else if((strcmp("5\n",user_input)==0) && (num==5))
       {
    	   UART_SendString(UART0, "$aws/things/ESP32/shadow/update\n");
    	   num=6;
       }
       else if((strcmp("6\n",user_input)==0) && (num==6))
       {
    	   UART_SendString(UART0, ROOTCA);
    	   num=7;
       }
       else if((strcmp("7\n",user_input)==0) && (num==7))
       {
    	   UART_SendString(UART0, DEVICECERT);
    	   num=8;
       }
       else if((strcmp("8\n",user_input)==0) && (num==8))
       {
    	   UART_SendString(UART0, DEVICEKEY);
    	   num=9;
    	   //DONE=1;
       }
   }

//UART_SendString(UART0, "Sending Buttons... Receiving LEDs\n");
//char* BUTTON[4];
char buffer[4];
int i=0;
int debounce=0;
//UART_SendString(UART0, "test");
while(1)
{

	if(Key_Scan(GPIO0,GPIO_Pin_4))
	{
		if(debounce>10000)
		{
			if(i<4)
				i++;
			else
				i=1;
			sprintf (buffer, "%d", i);
			UART_SendString(UART0, buffer);
			debounce=0;
		}
	}
	if(debounce<100000)
		debounce++;

	c = UART_ReceiveChar(UART0);
	if(c=='1')
	{
		GPIO_SetBit(GPIO0, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
		GPIO_ResetBit(GPIO0, GPIO_Pin_0);
	}
	else if (c=='2')
	{
		GPIO_SetBit(GPIO0, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
		GPIO_ResetBit(GPIO0, GPIO_Pin_1);
	}
	else if (c=='3')
	{
		GPIO_SetBit(GPIO0, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
		GPIO_ResetBit(GPIO0, GPIO_Pin_2);
	}
	else if (c=='4')
	{
		GPIO_SetBit(GPIO0, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
		GPIO_ResetBit(GPIO0, GPIO_Pin_3);
	}

}

}

uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	/*检测是否有按键按下 */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == 1 )
	{
		/*等待按键释放 */
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == 1);
		return 	1;
	}
	else
		return 0;
}
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  uint8_t bitstatus = 0x00;

  if ((GPIOx->DATA & GPIO_Pin) != 0)
  {
    bitstatus = (uint8_t)1;
  }
  else
  {
    bitstatus = (uint8_t)0;
  }
  return bitstatus;
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
