#include "reg51.h"

typedef unsigned int u16;

sbit LED = P2^0;

void Timer0Init(void)
{
	TMOD |= 0x01;	//ģʽ1�� ��λ���㣬��֤ǰ��4λ���ݲ��䣻

	TH0 = 0xfc;
	TL0 = 0x18;	//FC18 = FFFF(65535)-1000(us)����������Ϊ1us��+1;

	ET0 = 1;    //��T0���ж�����
	EA = 1;		//���ж��ܿ���
	TR0 = 1;	//��T0��ʱ��
}

void delay(u16 i)
{
	while (i--);
}

int main(void)
{
	Timer0Init();			 //�������ⲻ����������Ӱ��
	while (1){
		//Timer0Init();
		//delay(10000);	 //��ʱ�жϹ�����ѭ����֮��ʱ���ж��������ܵ�ѭ��ʱ��Ӱ�죨��ѭ��ʱ��̫��������ִ���жϲ�����ֱ��������һ���жϣ�
	}
	
	return 0;
}

void Timer0(void) interrupt 1
{
	static u16 i;
	TH0 = 0xfc;
	TL0 = 0x18;
	i++;
	if (i == 1000){
		i = 0;
		LED = ~LED;
	}
}

		