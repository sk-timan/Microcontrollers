#include "reg51.h"

typedef unsigned char u8;

void USART_Init(void) 	//串行口初始化
{
	TMOD = 0x20; 	//T1 模式3：自动补位
	TH1 = 0xF3;
	TL1 = 0xF3;
	PCON = 0x80;	//比特率加倍
	TR1 = 1;

	SCON = 0x50;	//串口工作方式 模式2 开启允许接收
	ES = 1;		//RI／TI串行口中断请求标识 打开
	EA = 1;		//总中断打开
}

void USART() interrupt 4
{
	u8 receive;
	receive = SBUF;	//为某个数据赋值SBUF 意义为取出SBUF接受的缓存
	RI = 0;		//RI 为接收一段（8 bit）后自动置1发送中断，需软件置0
	SBUF = receive;	//给SBUF赋值为发送该值
	
	while (!TI){	//TI 为发送中断，未发送完成期间，为0，完成后为1；需软件置0
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
	
