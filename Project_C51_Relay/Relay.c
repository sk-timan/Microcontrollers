#include "reg51.h"
#include "intrins.h"

sbit Relay = P1^4;

int main(void)
{
	Relay = 0;
	while (1){
	}
	return 0;
}