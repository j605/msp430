//program1

#include <msp430.h>
int ADC;
void main(void) 
{
WDTCTL = WDTPW + WDTHOLD;
 P1DIR |= 0x41;             // P1.6 to output  
            		// Use Vcc/Vss for Up/Low Refs, 16 x ADC10CLKs, turn on ADC
   ADC10CTL0 = SREF_0 + ADC10SHT_2 + ADC10ON;
            		// P1.5 input, use ADC10CLK div 1, single channel mode  
    ADC10CTL1 =  INCH_5 + SHS_0 + ADC10SSEL_0 + ADC10DIV_0 + CONSEQ_0;
    ADC10AE0 = BIT5;      	// Enable ADC input on P1.1
    ADC10CTL0 |= ENC;     	// Enable conversions.

    while(1) 
    {
    ADC10CTL0 |= ADC10SC;  		 	// start a new conversion
        while ((ADC10CTL1 & ADC10BUSY) == 0x01);   	// wait for conversion to end
        ADC=ADC10MEM;      			// convert to volts and store
    ADC=ADC>>2;
if(ADC<85) P1OUT=0x01;
    else if(ADC<170) P1OUT=0x40;
    else P1OUT=0x41;
    
    }    
} 


/*//program2
#include "msp430.h"
int ADC;
void main(void) 
{
WDTCTL = WDTPW + WDTHOLD;
 P1DIR |= 0x40;        	     	// P1.6 to output
 P1SEL |= 0x40;             		// Enabling PWM feature on P1.6 
CCR0 = 255;             		// PWM Period
CCTL1 = OUTMOD_7; 	// CCR1 reset/set
 TACTL = TASSEL_2 + MC_1  + ID_3;   // SMCLK, up mode, prescale by 8
  
            			// Use Vcc/Vss for Up/Low Refs, 16 x ADC10CLKs, turn on ADC
 
  ADC10CTL0 = SREF_0 + ADC10SHT_2 + ADC10ON;

          			  // P1.5 input, use ADC10CLK div 1, single channel mode  

    ADC10CTL1 =  INCH_5 + SHS_0 + ADC10SSEL_0 + ADC10DIV_0 + CONSEQ_0;
    ADC10AE0 = BIT5;      		// Enable ADC input on P1.1
    ADC10CTL0 |= ENC;    		// Enable conversions.

    while(1) 
    {
    	ADC10CTL0 |= ADC10SC;  		 // start a new conversion
        while ((ADC10CTL1 & ADC10BUSY) == 0x01);	 // wait for conversion to end
        ADC=ADC10MEM;     			 // convert to volts and store
    	ADC=ADC>>2;
    	CCR1=ADC;                			// CCR1 PWM duty cycle
    }    
} */
