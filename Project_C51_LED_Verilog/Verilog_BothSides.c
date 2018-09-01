#include "reg52.h"			 
#include <intrins.h>

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
