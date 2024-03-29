//Michael Johns
//MSP430G2553
//Hardware PWM
#include <msp430.h>

volatile int duty = 500; //duty cycle value

int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;        //Stops the watchdog timer


    P1DIR |= BIT0;  //Sets 1.0 as an output


    P1DIR |= BIT6;  //Sets 1.6 as an output
    P1SEL |= BIT6;  //Selects PWM for p1.6

    P1OUT =  BIT3;  //Enables pullup resistor
    P1REN |= BIT3;  //Enables pullup resistor
    P1IE |= BIT3;   //Enables interrupt
    P1IES |= BIT3;  //Enable interrupt
    P1IFG &= ~BIT3; //Clear Flag on p1.3


    TA0CCR0 = 1000;       //Duty Cycle = 100%
    TA0CCTL1 = OUTMOD_7;  //Timer Output Mode
    TA0CCR1 = duty;       //Duty Cycle = 50%
    TA0CTL = TASSEL_2 + MC_1; //Timer Instantiation up mode

     __bis_SR_register(LPM0_bits + GIE);  //enters lowpowermode0 w/ interrupt
    }

#pragma vector=PORT1_VECTOR       //Vector for Port 1 when button pressed.
__interrupt void Port1(void){
          P1OUT ^= BIT0;    //Toggle LED 1.0
 if (duty == 1000){        //If Duty Cycle = 100%
        duty = 0;          //Duty Cycle = 0
    } else {
        duty += 100;   //Increment Duty Cycle by 10%
    }
    TA0CCR1 = duty;          //Set the Duty Cycle of PWM
    P1IFG = ~BIT3;           //Clear the interrupt flag
}
