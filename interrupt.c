#include <msp430.h>

int main() {
	WDTCTL = WDTPW + WDTHOLD;
	P1DIR |= 0X01;
	P1DIR &= ~0x08;
	P1OUT &= ~0X01;
	P1REN |= 0X08;
	P1OUT |= 0x08;
	P1IE |= 0X08;
	P1IES |= 0X08;
	_BIS_SR(GIE);
	while(1){}
	return 0;
}

void __attribute__((interrupt(PORT1_VECTOR))) ISR(void)
{
	P1OUT ^= 0x01;
	P1IFG &= ~0x08;
}
