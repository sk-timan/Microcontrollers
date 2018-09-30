#include "reg51.h"

sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

#define GPIO_DIG P0


typedef unsigned int u16;
typedef unsigned char u8;

u8 code duan[17] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

u8 DATADisplay[8];

unsigned long int Count;
unsigned long int Frequency;


void delay(u16 i)
{
	while (i--);
}

void DynamicDisplay(void)
{
	u8 i;
	for (i=0; i<8; i++){
		switch (i){
			case 0:
				LSA = 0;
				LSB = 0;
				LSC = 0;
				break;
			case 1:
				LSA = 1;
				LSB = 0;
				LSC = 0;
				break;
			case 2:
				LSA = 0;
				LSB = 1;
				LSC = 0;
				break;
			case 3:
				LSA = 1;
				LSB = 1;
				LSC = 0;
				break;
			case 4:
				LSA = 0;
				LSB = 0;
				LSC = 1;
				break;
			case 5:
				LSA = 1;
				LSB = 0;
				LSC = 1;
				break;
			case 6:
				LSA = 0;
				LSB = 1;
				LSC = 1;
				break;
			case 7:
				LSA = 1;
				LSB = 1;
				LSC = 1;
				break;	 
		}
		GPIO_DIG = DATADisplay[i];
		delay(100);
		GPIO_DIG = 0x00;	//消影
	}
}



void TimerConfig(void)
{
	TMOD |= 0x51;	//0101 0001   启动T1计数，T0计时 都为模式01（8+8）

	TH0 = 0x3C;
	TL0 = 0xB0;	//50ms计时

	ET0 = 1;    //打开T0的中断允许
	ET1 = 1;
	EA = 1;		//打开中断总开关
	TR0 = 1;	//打开T0计时器
	TR1 = 1;
}




void Timer0(void) interrupt 1
{
	TH0 = 0x3C;
	TL0 = 0xB0;
	Count++;
	if (Count == 20){	//达到1s
		Count = 0;
		TR0 = 0;
		TR1 = 0;	//关闭T1 T0
	}
}

void Timer1(void) interrupt 3
{
	Frequency += 65536;	//计数器溢出一次就算一次之前总的计数
}

int main(void)
{
	TimerConfig();
	
	while (1){
		if (TR1 == 0){
			Frequency += (TH1 * 256) + TL1;	 	//加上最后一次未加上的值
					
			DATADisplay[0] = duan[Frequency %100000000/10000000];
			DATADisplay[1] = duan[Frequency %10000000/1000000];
			DATADisplay[2] = duan[Frequency %1000000/100000];
			DATADisplay[3] = duan[Frequency %100000/10000];
			DATADisplay[4] = duan[Frequency %10000/1000];
			DATADisplay[5] = duan[Frequency %1000/100];
			DATADisplay[6] = duan[Frequency %100/10];
			DATADisplay[7] = duan[Frequency %10/1];
			
			Frequency = 0;
			TH1 = 0;
			TL1 = 0;
			TR0 = 1;
			TR1 = 1;
		}
		DynamicDisplay();
	}	
		
	return 0;
}
	

			
			
			
			
		


			
			
			
			
		
	
	