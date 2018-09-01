#include "reg51.h"

typedef unsigned int u16;

sbit LED = P0^0;
sbit Button = P1^0;

void delay(u16 i)
{
	while (i--);
}

void Push(void)
{
	if (Button == 0){
		delay(1000);
		if (Button == 0){
			LED = ~LED;
		}while (!Button);
	}
}

int main(void)
{
	LED = 0;
	while (1){
		Push();
	}
	return 0;
}