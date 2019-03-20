#include "./src/AWS_IOT.h"
#include <WiFi.h>

#define USERPARAMS

AWS_IOT hornbill;

char WIFI_SSID[] = "SSID";
char WIFI_PASSWORD[]="PASSWORD";
char HOST_ADDRESS[]="host address";
char CLIENT_ID[]= "thing name";
char TOPIC_NAME[] = "topic";
char user_array[10000];

int status = WL_IDLE_STATUS;
int tick=0,msgCount=0,msgReceived = 0;
char payload[512];
char rcvdPayload[512];
int DONE;
int i;
    
void mySubCallBackHandler (char *topicName, int payloadLen, char *payLoad)
{
    strncpy(rcvdPayload,payLoad,payloadLen);
    rcvdPayload[payloadLen] = 0;
    msgReceived = 1;
}



void setup() { 

    Serial.begin(115200);
    delay(2000);
#ifdef USERPARAMS    
//////////////////////////////////////////////////////////////////////////////     
//Obtain SSID from user
    //Serial.print("\nEnter SSID:");
    
    DONE=0;
    i=0;
    while((!DONE)) 
    {
      if(Serial.available()) {
        user_array[i] = Serial.read();
        Serial.print(user_array[i]);
        if((user_array[i]=='\n') || (user_array[i]=='\r') || (user_array[i]==']'))
          DONE=1;
        if(user_array[i] != -1)
          i=i+1;
      }
      else
      {
        Serial.print("1\n"); 
        delay(1000);
      }
    }
    while(Serial.available())
        Serial.read();
        
    char WIFI_SSID[i-1];
    
    for(int j=0;j<i-1;j++)
      WIFI_SSID[j] = user_array[j];
//////////////////////////////////////////////////////////////////////////////      
//Obtain SSID Password from user
    //Serial.print("\nEnter Password:");

    DONE=0;
    i=0;
    while((!DONE)) 
    {
      if(Serial.available()) {
        user_array[i] = Serial.read();
        Serial.print(user_array[i]);
        if((user_array[i]=='\n') || (user_array[i]=='\r') || (user_array[i]==']'))
          DONE=1;
        if(user_array[i] != -1)
          i=i+1;
      }
      else
      {
        Serial.print("2\n");
        delay(1000); 
      }
    }
    while(Serial.available())
        Serial.read();

    char WIFI_PASSWORD[i-1];
    
    for(int j=0;j<i-1;j++)
      WIFI_PASSWORD[j] = user_array[j];
////////////////////////////////////////////////////////////////////////////// 
//Obtain HOST_ADDRESS from user
    //Serial.print("\nEnter HOST_ADDRESS:");

    DONE=0;
    i=0;
    while((!DONE)) 
    {
      if(Serial.available()) {
        user_array[i] = Serial.read();
        Serial.print(user_array[i]);
        if((user_array[i]=='\n') || (user_array[i]=='\r') || (user_array[i]==']'))
          DONE=1;
        if(user_array[i] != -1)
          i=i+1;
      }
      else
      {
        Serial.print("3\n");
        delay(1000); 
      }
    }
    while(Serial.available())
        Serial.read();

    char HOST_ADDRESS[i-1];
    
    for(int j=0;j<i-1;j++)
      HOST_ADDRESS[j] = user_array[j];
////////////////////////////////////////////////////////////////////////////// 
//Obtain CLIENT_ID from user
    //Serial.print("\nEnter CLIENT_ID:");

    DONE=0;
    i=0;
    while((!DONE)) 
    {
      if(Serial.available()) {
        user_array[i] = Serial.read();
        Serial.print(user_array[i]);
        if((user_array[i]=='\n') || (user_array[i]=='\r') || (user_array[i]==']'))
          DONE=1;
        if(user_array[i] != -1)
          i=i+1;
      }
      else
      {
        Serial.print("4\n");
        delay(1000); 
      }
    }
    while(Serial.available())
        Serial.read();
    
    char CLIENT_ID[i-1];
    
    for(int j=0;j<i-1;j++)
      CLIENT_ID[j] = user_array[j];
////////////////////////////////////////////////////////////////////////////// 
//Obtain TOPIC_NAME from user
    //Serial.print("\nEnter TOPIC_NAME:");

    DONE=0;
    i=0;
    while((!DONE)) 
    {
      if(Serial.available()) {
        user_array[i] = Serial.read();
        Serial.print(user_array[i]);
        if((user_array[i]=='\n') || (user_array[i]=='\r') || (user_array[i]==']'))
          DONE=1;
        if(user_array[i] != -1)
          i=i+1;
      }
      else
      {
        Serial.print("5\n"); //SSID
        delay(1000);
      }
    }
    while(Serial.available())
        Serial.read();
        
    //Serial.print("\n");

    char TOPIC_NAME[i-1];
    
    for(int j=0;j<i-1;j++)
      TOPIC_NAME[j] = user_array[j];
////////////////////////////////////////////////////////////////////////////// 
#endif  
    while (status != WL_CONNECTED)
    {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(WIFI_SSID);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

        // wait 5 seconds for connection:
        delay(5000);
    }

    Serial.println("Connected to wifi");

    if(hornbill.connect(HOST_ADDRESS,CLIENT_ID)== 0)
    {
        Serial.println("Connected to AWS");
        delay(1000);

        if(0==hornbill.subscribe(TOPIC_NAME,mySubCallBackHandler))
        {
            Serial.println("Subscribe Successfull");
        }
        else
        {
            Serial.println("Subscribe Failed, Check the Thing Name and Certificates");
            while(1);
        }
    }
    else
    {
        Serial.println("AWS connection failed, Check the HOST Address");
        while(1);
    }

    delay(2000);
    
char LEDNUM='0';
Serial.print("9\n");
while(1)
{
    //if(msgReceived == 1)
    //{
    //    msgReceived = 0;
        //Serial.print("Received Message:");
        Serial.println(rcvdPayload);
   //}
    if(Serial.available())//tick >= 5)   // publish to topic every 5seconds
    {
        
        LEDNUM = Serial.read();
        
        sprintf(payload,"%c",LEDNUM);
        if (LEDNUM != '0')
          while(hornbill.publish(TOPIC_NAME,payload) != 0)
          {   
            //Serial.print("Publish Failed");     
          }

        //Serial.print("Publish Message:");
        Serial.println(LEDNUM);//payload);
        LEDNUM = '0';
    }   
    //delay(1000);
}
}

void loop() {
}
