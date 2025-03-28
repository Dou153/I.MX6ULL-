/**************************************************************
Copyright © zuozhongkai Co., Ltd. 1998-2019. All rights reserved.
文件名	: 	 mian.c
作者	   : 左忠凯
版本	   : V1.0
描述	   : I.MX6U开发板裸机实验3 STM32模式的LED灯开发
		 使用STM32开发模式来编写LED灯驱动，学习如何从STM32来转入
		 I.MX6U的裸机开发，同时也通过本实验了解STM32库的运行方式。
其他	   : 无
日志	   : 初版V1.0 2019/1/3 左忠凯创建
**************************************************************/
#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exti.h"
#include "bsp_epit.h"
#include "bsp_key_filter.h"
#include "bsp_uart.h"
#include "stdio.h"


int main(void)
{
	int_init();
	clk_init();
	clk_enable();		/* 使能所有的时钟 			*/
	beep_init();
	led_init();			/* 初始化led 			*/
	delay_init();
	uart_init(UART1,115200);
	keyFilter_init();			/*使用EPIT1给按键消抖*/
	int a,b;
	int ret;					//记录scanf检测到的输入变量个数


	while(1)			/* 死循环 				*/
	{	
		printf("请输入2个整数,使用空格隔开:");
		ret = scanf("%d %d", &a,&b);
		while(ret!=2)	//如果scanf没有读到2个变量，重来
		{
			printf("\r\n");
			printf("请重新输入：");
			ret = scanf("%d %d", &a,&b);
		}
		printf("\r\n数据%d+%d=%d",a,b,a+b);//不支持浮点
		printf("\r\n");


	}

	return 0;
}
