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
	IT0 = 1;	//�����س�����ʽ���½��أ���0Ϊ�ⲿ�ж�0���ж�Դ���ţ�/INT0 ���жϺ�Ϊ0��
	IT1 = 1;	//1Ϊ�ⲿ�ж�1���ж�Դ���ţ�/INT1 ���жϺ�Ϊ2�����˵�Ƭ����INT0��INT1�ֱ��P3.2;P3.3

	EX0 = 1;	//��INT0���ж�����
	EX1 = 1;

	EA = 1;		//�����ж�
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