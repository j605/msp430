#include <msp430.h>

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;

	P1DIR|=0X40;
	P1SEL|=0X40; //P1.6 to TAo.1

	CCR0 = 500;
	CCTL1 = OUTMOD_7;
	CCR1 = 200;
	TACTL = TASSEL_2 + MC_1 + ID_3;
}
