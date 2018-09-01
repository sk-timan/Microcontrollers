#include "reg51.h"
#include "intrins.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit SER = P3^4;
sbit RCLK = P3^5;
sbit SRCLK = P3^6;

void delay(u16 i)
{
	while (i--);
}

void hc595output(u8 dat)
{
	u8 i;

	SRCLK = 1;
	RCLK = 1;

	for (i=0; i<8; i++){
		SER = dat >> 7;
		dat <<= 1;
		
		SRCLK = 0;
		_nop_();
		SRCLK = 1;
	}

	RCLK = 0;
	_nop_();
	RCLK = 1;
}

int main(void)
{
	u8 LEDnum = 0x01;
	while (1){
		hc595output(LEDnum);
		LEDnum = _crol_(LEDnum,1);
		delay(50000);
	}
	return 0;
}


		
	  