#include "reg51.h"
#include "intrins.h"

typedef unsigned char u8;

#define LED P0

sbit SH_LD = P1^6;
sbit QH = P1^7;		   //�˿ڹ�����ʽΪ��һ��CLK�����أ���˳��(HGFEDCBA)��һ����ƽλ
sbit CLK = P3^6;


u8 getData(void)
{
	u8 Data = 0x00;
	u8 i;

	SH_LD = 0;
	_nop_();
	SH_LD = 1;

	for (i=0; i<8; i++){
		Data = Data << 1;
		CLK = 0;
		_nop_();
		Data |= QH;
		CLK = 1;
		_nop_();
	}

	return Data;
}
	

int main(void)
{
	u8 HC165;
	LED = 0;

	while (1){
		HC165 = getData();
		if (HC165 != 0xff){
			LED = ~HC165;
		}
	}

	return 0;
}
