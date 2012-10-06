#include <msp430.h>

void button_init()
{
	P1REN |= 0x08;
	P1DIR |= 0x01;
}

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;
	button_init();
	P1OUT |= ~0X01;
	while(1) {
		if (P1IN&0x08)
			P1OUT &= ~0X01;
		else
			P1OUT |= 0x01;
	}
	return 0;
}
