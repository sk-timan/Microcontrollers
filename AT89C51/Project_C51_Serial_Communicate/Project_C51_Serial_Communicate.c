#include "reg51.h"

typedef unsigned char u8;

void USART_Init(void) 	//���пڳ�ʼ��
{
	TMOD = 0x20; 	//T1 ģʽ3���Զ���λ
	TH1 = 0xF3;
	TL1 = 0xF3;
	PCON = 0x80;	//�����ʼӱ�
	TR1 = 1;

	SCON = 0x50;	//���ڹ�����ʽ ģʽ2 �����������
	ES = 1;		//RI��TI���п��ж������ʶ ��
	EA = 1;		//���жϴ�
}

void USART() interrupt 4
{
	u8 receive;
	receive = SBUF;	//Ϊĳ�����ݸ�ֵSBUF ����Ϊȡ��SBUF���ܵĻ���
	RI = 0;		//RI Ϊ����һ�Σ�8 bit�����Զ���1�����жϣ��������0
	SBUF = receive;	//��SBUF��ֵΪ���͸�ֵ
	
	while (!TI){	//TI Ϊ�����жϣ�δ��������ڼ䣬Ϊ0����ɺ�Ϊ1���������0
	};
	TI = 0;
}


int main(void)
{
	USART_Init();
	while (1){
	};
	
	return 0;
}
	
