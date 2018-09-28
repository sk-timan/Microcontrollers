#include "reg51.h"

typedef unsigned int u16;

sbit LED1 = P2^0;
sbit LED2 = P2^1;
sbit K3 = P3^2;
sbit K4 = P3^3;

void delay(u16 i)
{
	while (i--);
}

void INTInterrupt(void)
{
	IT0 = 1;	//跳变沿出发方式（下降沿）；0为外部中断0（中断源符号：/INT0 ；中断号为0）
	IT1 = 1;	//1为外部中断1（中断源符号：/INT1 ；中断号为2），此单片机中INT0；INT1分别接P3.2;P3.3

	EX0 = 1;	//打开INT0的中断允许
	EX1 = 1;

	EA = 1;		//打开总中断
}

void Int0(void) interrupt 0
{
	delay(1000);
	if (K3 == 0){
		LED1 = ~LED1;
	}
}	

void Int1(void) interrupt 2
{
	delay(1000);
	if (K4 == 0){
		LED2 = ~LED2;
	}
}	

int main(void)
{
	LED1 = 0;
	LED2 = 0;
	INTInterrupt();

	while (1){
	}

	return 0;
}