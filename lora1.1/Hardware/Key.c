
#include "Delay.h"

/**
  * 函    数：按键初始化
  * 参    数：无
  * 返 回 值：无
  */
void Key_Init(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);						//将PB1和PB11引脚初始化为上拉输入
	
}

uint8_t KeyNum = 0;		//定义变量，默认键码值为0
uint8_t Key_GetNum(void)
{
	uint8_t Temp;
	if(KeyNum)
	{
		Temp = KeyNum;
		KeyNum = 0;//防止按键一直触发
		return Temp;
	}
	return Temp;
}

uint8_t Key_GetState(void)
{
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12) == 0)
	{
		return 1;
	}
	return 0;
}

void Key_Tick(void)
{
	static uint8_t key_stata, key_statb;
	static uint8_t Key_count;
	Key_count++;
	if(Key_count >=20)
	{
		Key_count = 0;
		
		key_stata = key_statb;
		key_statb = Key_GetState();
		
		if(key_statb == 0 && key_stata != 0)//抬起有效
		{
			KeyNum = key_stata;
		}
					
	}
	
}
