#include "reg51.h"

#define time 200

typedef unsigned char u8;
typedef unsigned int u16;

sbit A_P = P1^0;
sbit A_N = P1^1;
sbit B_P = P1^2;
sbit B_N = P1^3;

void delay(u16 i)
{
	while (i--);
}

int main(void)
{
	P1 = 0;
	while (1){
		A_P = 1;
		A_N = 0;
		B_P = 1;
		B_N = 1;
		delay(time);

		A_P = 0;
		A_N = 1;
		B_P = 1;
		B_N = 1;
		delay(time);

		A_P = 1;
		A_N = 1;
		B_P = 1;
		B_N = 0;
		delay(time);

		A_P = 1;
		A_N = 1;
		B_P = 0;
		B_N = 1;
		delay(time);
	}
	
	return 0;
}