#include "reg51.h"

sbit led = P0^0;

int main(void)
{
	while (1){
		led=1;	
	}
	return 0;
}