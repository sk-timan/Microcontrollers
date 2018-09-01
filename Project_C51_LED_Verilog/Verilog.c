

#include "reg52.h"			 
#include<intrins.h>

typedef unsigned int u16;	  
typedef unsigned char u8;


#define LED P0		 //����Ƭ����P0.0�˿ڶ���Ϊled


void delay(u16 i)
{
	while(i--);	
}


void main()
{
	u8 i;					   //char��Ϊ1�ֽ����Σ�����Ϊ�ַ���ʱ('a'),������ϢΪ���ַ�ASCII��
	LED = 0x01;
	delay(50000);
	while(1)
	{
		for(i=0;i<7;i++){
			LED = (0x03<<i);	 //��1����iλ��Ȼ�󽫽����ֵ��P0��
			delay(50000); //��Լ��ʱ450ms
		}
		LED = (0x81);
		delay(50000);
	}		
}
