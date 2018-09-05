#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit motor = P1^0;

void delay(u16 i)
{
	while (i--);
}

int main(void)
{
	motor = 0;
	while (1){
		motor = 1;
		delay(50000);
		motor = 0;
		delay(50000);
		delay(50000);
		delay(50000);
	}
	
	return 0;
}