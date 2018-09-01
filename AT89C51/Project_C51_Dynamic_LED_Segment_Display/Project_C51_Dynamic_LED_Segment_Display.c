#include "reg51.h"

sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

void delay(unsigned int i)
{
	while (i--);
}

unsigned char code duan[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void DynamicDisplay(void)
{
	unsigned char i;
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
		P0 = duan[i];
		delay(50);
		P0 = 0x00;
	}
}

int main(void)
{
	while (1){
		DynamicDisplay();
	}
	return 0;
}














