
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
#include "gw1ns2k.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "gw1ns2k_gpio.h"
#include "broadkey_demo_app.h"

extern int __puf;
extern int __ac;

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

const char SSID[]	=	"gnarlygrey\n";
const char PW[]		=	"67mercedes230\n";
static const char URL[]	=	"a2pb2f9st3ros6-ats.iot.us-east-2.amazonaws.com\n";
static const char THING[]	=	"ESP32_BKP_1\n";
static const char ROOTCA[]	=	"-----BEGIN CERTIFICATE-----\n\
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\n\
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6\n\
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL\n\
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv\n\
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj\n\
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM\n\
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw\n\
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6\n\
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L\n\
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm\n\
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC\n\
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA\n\
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI\n\
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs\n\
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv\n\
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU\n\
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy\n\
rqXRfboQnoZsG4q5WTP468SQvvG5\n\
-----END CERTIFICATE-----\r";

//ESP32_BKP_1 Cert
static const char DEVICECERT[]	=	"-----BEGIN CERTIFICATE-----\n\
MIIDWTCCAkGgAwIBAgIUW8csS50L0Ypc6fB3fbLGV5np9xYwDQYJKoZIhvcNAQEL\n\
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g\n\
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTE5MDQxNzE4MzUy\n\
NFoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0\n\
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBANsfNkyWKZTHlj8RmiRK\n\
eB3j33Q072y11Qbb3t44GkGLpFa03eMLqyfd6/X+0oEgFag+x0MiwgZQraUPBGgE\n\
HnhTdZf8/0peQ7bI0d3OLBE2py77ytB+RQ9LwtPuMV+x2Wl5H9ZKtRkD7G/o6hJO\n\
HBLbGHZTZSWkHHqIk6szBsE4ixjzlf1Uu8spnTLnp8DqYez1tAbgVgZNrMMcqjnY\n\
PIw2QUt7CCt5rSGCUJn941rs+lfK4HDzKznCtpsAYf7tPa9ZYt4QcuadEkhSb6r2\n\
SwEdSbTV1F0VXm99MY/R1msgE64nzAmVE2NXF6qM8xO1Y3qnMON7YheVMPpqb1mL\n\
oyUCAwEAAaNgMF4wHwYDVR0jBBgwFoAUCVMn21+uFWPLdFDG5iGhx4BoftowHQYD\n\
VR0OBBYEFCn3k95X4au1jlCBbBNY744aa00RMAwGA1UdEwEB/wQCMAAwDgYDVR0P\n\
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQASevnrGd0Y4alBdPIXS9m1qnz/\n\
O3ujf8ex/mVU2m9lD0Za4QUcAj6XJLu90v/a0kSLm9E9LsivBUrDwwEFEBZ+nBCs\n\
VbAWQz42ejDAdYukmo5RfdRqgRUVs7Ryp71fHt0ckMETzbkzqVZeVgZw5ZeZZwoq\n\
cJNcnKGLu0jWUHuVl5Bm+ZJGp9mMyqZbLWY+UNVYzZoXmjeEKGv2PSBlKPbiOHNa\n\
ixrfomhA6C86KDVl2sC/jbFX4wwz1k0s2xSZgMJP0Mk7G6NKgGtDf6bC9Hd3XOpN\n\
PPbve8C9Ol3Oa+puTulId6XyAwFS7y5YxnZdeVDPJ9buh9FfakMWWp+SW4uT\n\
-----END CERTIFICATE-----\r";

//ESP32_BKP_2 Cert
/*static const char DEVICECERT[]	=	"-----BEGIN CERTIFICATE-----\n\
MIIDWjCCAkKgAwIBAgIVAJxQmaRuW0bx3AL8RJQwIjG0Pe/PMA0GCSqGSIb3DQEB\n\
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t\n\
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0xOTA0MjQxMzA0\n\
MjRaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh\n\
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDvOJzzbbKPs1WlDqhk\n\
PuUlwyQLgKT3Jirt7k+vnSpySrV87MfazOi/xrbg7YLFpxjYcJTlu/RM5o07ZXuF\n\
dxI6iE/uLvsr7/2DaUjanZgq/jksvd7cYVMW2NEaO6GvDTyedQ3MeA22RDi9xmK9\n\
xf+lmD5mjTOfmLDtJxj+8nXR4+6fMkmrKsH9YqlDBRCArBwi+f7yeHmzhqs4uuxk\n\
X2IL4x/OAhC9Z/+QNsAEpDp+OqOu/56LkeoSNEQONjAvlYBtP8rO51jK3hhCZYzu\n\
XGHo4SNEnN3VCV1k6ZWMX8PPBN5G66/8wq7cZsP+mcKOdZkMVt/Coeg5QAvWC1PJ\n\
0bU7AgMBAAGjYDBeMB8GA1UdIwQYMBaAFMO/+ageSRliZTpTjeNkZwFcxnpbMB0G\n\
A1UdDgQWBBSbmNmaWTDnBRBlY9CpBib105adhDAMBgNVHRMBAf8EAjAAMA4GA1Ud\n\
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAVWuPhkyEX96A1Uv2Dh88rtPM\n\
X5Xt0+zeGBg3L6SfkLc9N3SvgASPEoUtkX/69puza7vBIq2DZrBH1E0g+CmKFJ8E\n\
R9LzS3Xkwl1MGzuU9sg0G20IZRVnCeyJ7wp0/r38k29cZCD7uCkajzjsr021fno4\n\
T1ruOIamo/m3lzWiIZMFbgAuGjaUpUaLF1K7o9Dx3NQy+8R05iVJ7LoAe+H0AlwO\n\
pVTdas8/ZHbGZd6mIv7Y+dWszWdsPAY/bgz855+/ouQkpxMHxW2qe0q5BjwV+Flb\n\
4ojo8zd3lOPeGMgF07s0ECSybUhduD8GiAYk4sLjJ/o3tVcg+Yv76+cIhOMz4g==\n\
-----END CERTIFICATE-----\r";*/
//ESP32_BKP_1 Private Key
/*static const char DEVICEKEY []	=	"-----BEGIN RSA PRIVATE KEY-----\n\
MIIEowIBAAKCAQEA2x82TJYplMeWPxGaJEp4HePfdDTvbLXVBtve3jgaQYukVrTd\n\
4wurJ93r9f7SgSAVqD7HQyLCBlCtpQ8EaAQeeFN1l/z/Sl5DtsjR3c4sETanLvvK\n\
0H5FD0vC0+4xX7HZaXkf1kq1GQPsb+jqEk4cEtsYdlNlJaQceoiTqzMGwTiLGPOV\n\
/VS7yymdMuenwOph7PW0BuBWBk2swxyqOdg8jDZBS3sIK3mtIYJQmf3jWuz6V8rg\n\
cPMrOcK2mwBh/u09r1li3hBy5p0SSFJvqvZLAR1JtNXUXRVeb30xj9HWayATrifM\n\
CZUTY1cXqozzE7Vjeqcw43tiF5Uw+mpvWYujJQIDAQABAoIBAEnuXgO5Jo5sSOU+\n\
qyNTfPOYzuwGcEHdl+KYjLmtdC5pTylyHOteJIFu/w4gzCWFDcmWZOTh9VTsI6pt\n\
Rq9RtHYksqh1VC1jYLVrTGPqDDRCnGXdzrBJ6kMe7L1UwJPpDdHobDWBP1kRWdTo\n\
YRGMCSzTf41s1dO9a15sdmZs8Pp/2Wx4Srhe49jOohGnHjj/yjOrBWixQa3iQrPa\n\
ukohoCBqKoHrcxeebIF3Yxf7HrKec/F/lvyOt/Zo4cY2nVN/aQFDNC65gbMCUJRp\n\
6Rq9xp0M5sexPBjMWX5v+dzKmU620TxhmDge7OIlJ7UfJ0G7Bff409Bnj4VE3xSx\n\
ev4I1IECgYEA+IT5yoR3Xug9a3HyOgLWHmvBPThPvA2AR6FdJChN9kBlgBnmUggP\n\
ChEK8Bd+3uRkxSLAsaz7AwBSOhSWZS3F4iULpWQK5PyuCOzYHiNrQonj10EGtI7E\n\
flwXUmosaN+cXQzCzq5i7J1An4IurKOxW63HwMRqp7Cxs0FiCxOhV7sCgYEA4be0\n\
/OxXqgq4YwYhs8LrGobjCgdbIfJ1ZluSiDwxPcBlj2jl+SjFWzFkzOG6xbF4kmID\n\
C51fpz0iZ/lZpURo+PxE+IulaRd0vMacD4fVe76AKfiIUbRI4ix7E/o/qUTv5LfG\n\
jqf8vqg9oDxLbDdOaEZnRExRMS06gMLYDEpREp8CgYBcwOSp3T7gQTWLQH/zftOD\n\
jxwUSUwZF8Dk+yjUMebHHcnEQeZgf3l9fFbkvSAw+HVTzmC076bPu/L0knJ/WNIe\n\
UU1DcU9Pn68kzaDrvrRtpSFQWYizIwXbU2uw6segbLTjVbvvf86UGSzhW6kn7gBo\n\
AzgmjihwZdYs3R5GnBD/uQKBgDMVUHCtTGm/Y1uF17rHMk4emON8JrPYG5m+v7r1\n\
ZG+FS3bZVrK8921cEGQN8icrsw3uAKJwS2WeAFtno1Iz2U4ASdu2Pwk5tcHDcS5S\n\
n44R3w+gn7leA+CsEG7FBANbBq/Mp7NBcYH0sX3CJ4+mNKiExno+i2GFyue5MQwX\n\
BaIhAoGBALNIo/9KmsemBhf+h/6XflzHAPtdMQ9zVaGhlRr7ARuTxpLvDZiMZ/xb\n\
BasU4jSiVCRdLvoTUEAFn5IszpttxnMjnBUwMepvHh+fzBITcU3m9jL4//sR7O8V\n\
IPMyE9Q3Scq8N/3nckvaWtboA+H2kIkkhgQRoHtnpUz+tPAnQTPa\n\
-----END RSA PRIVATE KEY-----\r";*/
//ESP32_BKP_2 Private Key
/*static const char DEVICEKEY []	=	"-----BEGIN RSA PRIVATE KEY-----\n\
MIIEowIBAAKCAQEA7zic822yj7NVpQ6oZD7lJcMkC4Ck9yYq7e5Pr50qckq1fOzH\n\
2szov8a24O2CxacY2HCU5bv0TOaNO2V7hXcSOohP7i77K+/9g2lI2p2YKv45LL3e\n\
3GFTFtjRGjuhrw08nnUNzHgNtkQ4vcZivcX/pZg+Zo0zn5iw7ScY/vJ10ePunzJJ\n\
qyrB/WKpQwUQgKwcIvn+8nh5s4arOLrsZF9iC+MfzgIQvWf/kDbABKQ6fjqjrv+e\n\
i5HqEjREDjYwL5WAbT/KzudYyt4YQmWM7lxh6OEjRJzd1QldZOmVjF/DzwTeRuuv\n\
/MKu3GbD/pnCjnWZDFbfwqHoOUAL1gtTydG1OwIDAQABAoIBADSC5uEAqXul0B0F\n\
VK18qOxbI6RqvsuJ006bS16vT0v7Xk9n4o8C/+xpAGfrexNMFMYeIHE1ivD+gu4Q\n\
3sZzVssGdRVBttz0N2ALUnS6t1Zoq8BIhY02x/hx66SohltYun/GDhteFxR1cUcn\n\
LzGdLvr4qmn0gOp9qAjG1lPQgVBrHacOav46o+xtj232NOnkMhnbuv506jtuRgCn\n\
EDy61pSXKE1SZ5gb/HR0FWWJVlXLIviPKaiPlpqu0YxZYGWIoaoqd9l0JFPn3G9H\n\
/hCqG4r3LoAkdTLpwryQkXFvSe0Vyg4wSEFT3pXPsS2J71hiYTyIGbCnOwN+qv59\n\
MkWrqIECgYEA+DkHVvIxvqyaZonrpo4vZSNWKunUk2AHL/yFmFGq/Wikv1zzit+E\n\
954kCJ0ttc5DhlwsDm5o+GXIXcMILHYT1haMfsdim2ul2ifHkvB+MW31ykQLDrXd\n\
kQxuUpi9KHLHy5Ki8o7U3ZDE9UezcYTiG9HgsDOCuVXUAB+FZ1rCn6ECgYEA9rdi\n\
HKv9I4FxdXKQ6Pd8Us+z+JTd+HiS7Hdya76DygtQXpUY0+gk7xiJV1FG+N59s/JN\n\
tFl/qBF44sj5eF97D1RQP9LGKIh3H9T+wf8lZs6ma0WiDMZtgP7XnitSHQIzVi7+\n\
NM5E8Z3yeQbsEQFJ3CGPc2qEzIo0BKVCLpSbl1sCgYAHFiG2gr2W0vipesCGhcKm\n\
oYahPQG7n181KIFr4tD94RHrAK1XRqBWLWab9FjMuvHEkTcUxmQqy0UYICxIkKpq\n\
T0R9jhWrmDwo6T/SWxlPMfN1bdHe/qQvsuonY4Lq97PqhOowAJHlLW/iDMT7ta56\n\
2tgOT7oormGaC0xUsguiYQKBgQDFxB57iUpzibGfSeTrOmeIIkLLwtlj8ZMkxmMM\n\
Bz2xWfxktPOf+fiRSIPfYKGZoQ/2jQbIyO1Rlh/m+t8vJKqKkTV608RQfYOwGpbU\n\
f2hFzuUMHFdYEj95Jc9FVMiPxFHOhgDz51zQqaHSbkARKY1BTg2loP8uzqIAD1DL\n\
8gf+/QKBgH1xONpRG2l54jJPccgNH1IFu/3pJ81uoPy1kW2VdUUou8eyb5PgO6dZ\n\
HWz8yOpJD9ULczTLp9ifrgXvAbzu/EZ8QptFIvfbz5axGTjiuQuGep+meQ0fsyWf\n\
8giGFge0K/4XgwdKEqJUavS6c+q04kHhSSPTeBQF70tVqwF8N6Dx\n\
-----END RSA PRIVATE KEY-----\r";*/

volatile uint32_t counter;

int main()
{   
  int num=0;
  char c;
  char user_input[100];
  uint32_t i;

    uint8_t * sram_puf = (uint8_t *)&__puf;

    uint8_t * sram_ac = (uint8_t *)&__ac;
	
	//Init System
	SystemInit();

  //Init Uart
  UartInit();
  UART_SendString(UART0,"\nUart Initial finished\n");
  //UART_SendString(UART0,"\nTimer Initial:\n");

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



	//broadkey_demo_app(sram_puf, sram_ac);

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

	
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
       i=0;
       while(c != '\n')
       {
    	   c = UART_ReceiveChar(UART0);
    	   user_input[i] = c;
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
    	   //UART_SendString(UART0, DEVICEKEY);
    	   broadkey_demo_app(sram_puf, sram_ac);
    	   num=9;
    	   //DONE=1;
       }
   }


		GPIO_SetBit(GPIO0, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
		GPIO_ResetBit(GPIO0, GPIO_Pin_1);
		GPIO_ResetBit(GPIO0, GPIO_Pin_3);




//UART_SendString(UART0, "Sending Buttons... Receiving LEDs\n");
//char* BUTTON[4];
char buffer[4];
i=0;
int debounce=0;
//UART_SendString(UART0, "test");
  while(1)
  {
	c = UART_ReceiveChar(UART0);
	//UART_SendChar(UART0, c);
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

	if(Key_Scan(GPIO0,GPIO_Pin_4))
	{
		if(debounce>10000)
		{
			if(i<4)
				i++;
			else
				i=1;
			sprintf (buffer, "%d", i);
			//UART_SendString(UART0, buffer);
			UART_SendChar(UART0, buffer[0]);
			debounce=0;
		}
	}
	if(debounce<100000)
		debounce++;

  }

}

uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	/*检测是否有按键按下 */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == 0 )
	{
		/*等待按键释放 */
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == 0);
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
