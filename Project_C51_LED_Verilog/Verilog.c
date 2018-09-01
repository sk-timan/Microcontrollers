

#include "reg52.h"			 
#include<intrins.h>

typedef unsigned int u16;	  
typedef unsigned char u8;


#define LED P0		 //将单片机的P0.0端口定义为led


void delay(u16 i)
{
	while(i--);	
}


void main()
{
	u8 i;					   //char型为1字节整形，定义为字符串时('a'),所含信息为该字符ASCII码
	LED = 0x01;
	delay(50000);
	while(1)
	{
		for(i=0;i<7;i++){
			LED = (0x03<<i);	 //将1右移i位，然后将结果赋值到P0口
			delay(50000); //大约延时450ms
		}
		LED = (0x81);
		delay(50000);
	}		
}
