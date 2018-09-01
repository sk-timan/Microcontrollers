#include "reg52.h"			 
#include <intrins.h>

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
	LED = 0x03;
	delay(50000);
	while(1)
	{
		for(i=0;i<6;i++){
			LED = _crol_(LED,1);	 
			delay(50000); 
		}
		for (i=0; i<6; i++){
			LED = _cror_(LED,1);
			delay(50000);
		}
	}		
}
