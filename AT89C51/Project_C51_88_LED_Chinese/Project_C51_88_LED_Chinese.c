#include "reg51.h"
#include "intrins.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit SER = P3^4;
sbit RCLK = P3^5;
sbit SRCLK = P3^6;

u8 LEDByte[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

u8 LEDSegment[] = {0x00,0x04,0x9F,0xAA,0xAA,0x84,0xCA,0x00};

void delay(u16 i)
{
	while (i--);
}

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
	u8 i;
	
	while (1){
		for (i=0; i<8; i++){
			hc595output(~LEDSegment[i],LEDByte[i]);
			delay(10);
		}
	}
	
	return 0;
}
		 			