//Q3 - A PWM signal w/ a 20% duty cycle and a 250ms period is output @P1.6
#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;                 // Stop WDT

    P1DIR |= BIT6;                            // P1.6 output
    P1SEL1 |= BIT6;                           // P1.6 options select

    PM5CTL0 &= ~LOCKLPM5;

    TB0CCR0 = 8192-1;                          // PWM Period
    TB0CCTL1 = OUTMOD_7;                      // CCR1 reset/set
    TB0CCR1 = 1638.4;                            // CCR1 PWM duty cycle
    TB0CTL = TBSSEL__ACLK | MC__UP | TBCLR;  // ACLK, up mode, clear TBR

    while(1)
    {
        P1OUT ^=BIT6;// For debugger
    }
}
