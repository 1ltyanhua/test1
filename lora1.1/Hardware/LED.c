     #include "stm32f10x.h"           
#include "LED.h"
/**
  * 函    数：LED初始化
  * 参    数：无
  * 返 回 值：无
  */
void LED_Init(void)
{
	/*开启时钟*/

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);						

}

/**
  * 函    数：LED1开启
  * 参    数：无
  * 返 回 值：无
  */
void SET_OFF(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_8);		//设置PA1引脚为低电平
}

/**
  * 函    数：LED1关闭
  * 参    数：无
  * 返 回 值：无
  */
void SET_ON(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_8);		//设置PA1引脚为高电平
}

void CS_OFF(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_11);		//设置PA1引脚为低电平
}

/**
  * 函    数：LED1关闭
  * 参    数：无
  * 返 回 值：无
  */
void CS_ON(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_11);		//设置PA1引脚为高电平
}
