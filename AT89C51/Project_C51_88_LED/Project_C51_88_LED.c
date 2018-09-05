#include "reg51.h"
#include "intrins.h"

typedef unsigned char u8;

sbit SER = P3^4;
sbit RCLK = P3^5;
sbit SRCLK = P3^6;

void hc595output(u8 dat1, u8 dat2)
{
	u8 i;

	RCLK = 1;
	SRCLK = 1;

	for (i=0; i<8; i++){
		SER = dat1 >> 7;
		dat1 <<= 1;

		SRCLK = 0;
		_nop_();
		SRCLK = 1;
	}
	
	for (i=0; i<8; i++){
		SER = dat2 >> 7;
		dat2 <<= 1;

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
	hc595output(0x7f,0x01);
	while (1){
	}
	return 0;
}
		 			