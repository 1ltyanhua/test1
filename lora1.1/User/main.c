#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Key.h"
#include "Timer.h"
#include "Serial.h" 
#include "Delay.h"
#include "String.h"
uint8_t myykey_num = 0; 
//                                 信道      频段    速率     功率   波特率  串口数据位    停止位
uint8_t arry[36] = {0xaa,0xfa,0x03,0x0a   ,  0x01 ,  0x08  ,  0x07  , 0x03,    0x02,      0x01, \
//  校验位     netid        节点ID    工作模式mesh    模式选择   加密              秘钥
	0x01,     00,00,00,01,   00,02  ,     01  ,         00     ,  00 ,   01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01\
};
uint8_t arry1[4] = {0xAA,01,02,03};
char str2[30] = {"aaaaaaaaaa"};
char * str1 = "bbabb";
char str[30];

int main(void)
{
	LED_Init();
	Key_Init();
	Timer_Init();
	Serial_Init();
	SET_ON();
	CS_ON();
	SET_OFF();
	Delay_ms(50);
	Serial_SendArray(arry,36);
	
	SET_ON();
	while(1)
	{
		myykey_num = Key_GetNum();
//		if(myykey_num)
//		{
			//配置
//			SET_OFF();
//			Delay_ms(50);
//			Serial_SendArray(arry,36);
//			
//			SET_ON();
			//
//			arry1[1]++;
//			arry1[2]++;
//			arry1[3]++;
//			Serial_SendArray(arry1,4);
//			rx_falg = 1;
//		}
		if(Rxflag == 1)
		{
			
			if(Serial_RxPacket[0] == 0xAA)
			{
				
				sprintf(str,"t0.txt=\"%d %d \"\xff\xff\xff",Serial_RxPacket[1],Serial_RxPacket[2]);
				Serial2_SendString(str);
				
//				sprintf(str,"t1.txt=\"%d ms\"\xff\xff\xff",rx_delay/2);
//				Serial2_SendString(str);
				Serial_SendArray(Serial_RxPacket,3);
				
			}
			memset(Serial_RxPacket,0,pRxPacket);
			pRxPacket = 0;
			Rxflag = 0;
			rx_falg = 0;
			rx_delay = 0;
			
		}
	}
}

