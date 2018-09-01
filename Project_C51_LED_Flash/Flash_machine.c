#include "reg51.h"
#include "intrins.h"

sbit led = P0^0;

void delay1s(void)   //Îó²î 0us
{
    unsigned char a,b,c;
    for(c=167;c>0;c--)
        for(b=171;b>0;b--)
            for(a=16;a>0;a--);
    _nop_();  //if Keil,require use intrins.h
}

int main(void)
{
	while (1){
		led = 1;
		delay1s();
		led = 0;
		delay1s();	
	}
	return 0;
}