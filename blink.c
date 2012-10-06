#include <msp430.h>

#define D_TIME 99999

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;
	P1DIR=0x41;
	for(;;) {
		P1OUT|=0X40;
		__delay_cycles(D_TIME);
		P1OUT&=~0x40;
		P1OUT|=0X01;
		__delay_cycles(D_TIME);
		P1OUT=~P1OUT;
	}
	return 0;
}
