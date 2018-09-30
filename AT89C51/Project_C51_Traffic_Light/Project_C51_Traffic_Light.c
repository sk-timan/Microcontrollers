#include "reg51.h"

sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

#define GPIO_DIG P0
#define GPIO_TRAFFIC P1

sbit REDL = P1^0;
sbit GREENL = P1^1;

sbit REDU = P1^2;
sbit GREENU = P1^4;
sbit YELLOWU = P1^3;

sbit REDR = P1^5;
sbit GREENR = P1^7;
sbit YELLOWR = P1^6;

sbit REDD = P3^0;
sbit GREEND = P3^1;

typedef unsigned int u16;
typedef unsigned char u8;

u8 code duan[17] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

u8 DATADisplay[8];
u8 Second;


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



void Timer0Init(void)
{
	TMOD |= 0x01;	//模式1； 或位运算，保证前面4位数据不变；

	TH0 = 0xfc;
	TL0 = 0x18;	//FC18 = FFFF(65535)-1000(us)（机器周期为1us）+1;

	ET0 = 1;    //打开T0的中断允许
	EA = 1;		//打开中断总开关
	TR0 = 1;	//打开T0计时器
}




void Timer0(void) interrupt 1
{
	static u16 i;
	TH0 = 0xfc;
	TL0 = 0x18;
	i++;
	if (i == 1000){
		i = 0;
		Second++;
	}
}


int main(void)
{
	Second = 1;
	Timer0Init();
	
	while (1){
		if (Second == 70){
			Second = 1;
		}
		
		if (Second <=30){		//两个if为同时判断，else if 为按顺序判断（当某个if或else if 不再满足时，依次进行下面的判断）
			DATADisplay[0] = 0x00;
			DATADisplay[1] = 0x00;
			DATADisplay[2] = duan[(30 - Second) / 10];
			DATADisplay[3] = duan[(30 - Second) % 10];
			DATADisplay[4] = 0x00;
			DATADisplay[5] = 0x00;
			DATADisplay[6] = DATADisplay[2];
			DATADisplay[7] = DATADisplay[3];
			DynamicDisplay();
		
			GPIO_TRAFFIC = 0xff;
			REDD = 1;
			GREEND = 1;
			
			GREENU = 0;	//宝田路通行
			delay(50);
			GREENU = 1;
			delay(200);
			
			GREENL = 0;
			delay(50);
			GREENL = 1;
			delay(200);

			REDR = 0;
			delay(50);
			REDR = 1;
			delay(200);

			REDD = 0;
			delay(50);
			REDD = 1;
			delay(200);
		}
		
		else if (Second <=35){
			DATADisplay[0] = 0x00;
			DATADisplay[1] = 0x00;
			DATADisplay[2] = duan[(35 - Second) / 10];
			DATADisplay[3] = duan[(35 - Second) % 10];
			DATADisplay[4] = 0x00;
			DATADisplay[5] = 0x00;
			DATADisplay[6] = DATADisplay[2];
			DATADisplay[7] = DATADisplay[3];
			DynamicDisplay();
		
			GPIO_TRAFFIC = 0xff;
			REDD = 1;
			GREEND = 1;
		
			YELLOWU = 0;	//黄灯等待交换
			delay(50);
			YELLOWU = 1;
			delay(200);

			REDL = 0;
			delay(50);
			REDL = 1;
			delay(200);

			YELLOWR = 0;
			delay(50);
			YELLOWR = 1;
			delay(200);

			REDD= 0;
			delay(50);
			REDD = 1;
			delay(200);
		}
	
		else if(Second <=65){
			DATADisplay[0] = 0x00;
			DATADisplay[1] = 0x00;
			DATADisplay[2] = duan[(65 - Second) / 10];
			DATADisplay[3] = duan[(65 - Second) % 10];
			DATADisplay[4] = 0x00;
			DATADisplay[5] = 0x00;
			DATADisplay[6] = DATADisplay[2];
			DATADisplay[7] = DATADisplay[3];
			DynamicDisplay();
	
			GPIO_TRAFFIC = 0xff;
			REDD = 1;
			GREEND = 1;

			REDU = 0;	//前进路通行
			delay(50);
			REDU = 1;
			delay(200);

			REDL = 0;
			delay(50);
			REDL = 1;
			delay(200);

			GREENR = 0;
			delay(50);
			GREENR = 1;
			delay(200);

			GREEND = 0;
			delay(50);
			GREEND = 1;
			delay(200);
		}
		
		else {
			DATADisplay[0] = 0x00;
			DATADisplay[1] = 0x00;
			DATADisplay[2] = duan[(70 - Second) / 10];
			DATADisplay[3] = duan[(70 - Second) % 10];
			DATADisplay[4] = 0x00;
			DATADisplay[5] = 0x00;
			DATADisplay[6] = DATADisplay[2];
			DATADisplay[7] = DATADisplay[3];
			DynamicDisplay();
	
			GPIO_TRAFFIC = 0xff;
			REDD = 1;
			GREEND = 1;
		
			YELLOWR = 0;	//黄灯准备
			delay(50);
			YELLOWR = 1;
			delay(200);

			REDL = 0;
			delay(50);
			REDL = 1;
			delay(200);

			YELLOWU = 0;
			delay(50);
			YELLOWU = 1;
			delay(200);

			REDD = 0;
			delay(50);
			REDD = 1;
			delay(200);
		}
	}
	
	return 0;
}
	

			
			
			
			
		


			
			
			
			
		
	
	