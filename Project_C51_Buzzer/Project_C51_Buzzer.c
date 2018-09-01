#include "reg51.h"
#include <intrins.h>

typedef unsigned int u16;
typedef unsigned char u8;

sbit Buzzer = P1^5;

void delay(u16 i)
{
	while (i--);
}



int main(void)
{
	u16 i;
	while (1){
		i = 0x00;
		while (i<=500){
			Buzzer = 0x01;
			delay(100);
			Buzzer = 0x00;
			delay(100);
			i++;
		}	
		Buzzer = 0x01;
		delay(50000);
		delay(50000);
	}
	return 0;
}