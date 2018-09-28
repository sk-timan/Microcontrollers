#include "reg51.h"

typedef unsigned int u16;

sbit LED = P2^0;

void Timer0Init(void)
{
	TMOD |= 0x01;	//模式1； 或位运算，保证前面4位数据不变；

	TH0 = 0xfc;
	TL0 = 0x18;	//FC18 = FFFF(65535)-1000(us)（机器周期为1us）+1;

	ET0 = 1;    //打开T0的中断允许
	EA = 1;		//打开中断总开关
	TR0 = 1;	//打开T0计时器
}

void delay(u16 i)
{
	while (i--);
}

int main(void)
{
	Timer0Init();			 //挂载在外不受其他因素影响
	while (1){
		//Timer0Init();
		//delay(10000);	 //计时中断挂载在循环体之内时，中断启动会受到循环时间影响（如循环时间太短来不及执行中断操作，直接重启下一次中断）
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

		