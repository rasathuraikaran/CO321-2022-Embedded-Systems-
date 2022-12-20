
/*
 * Lab3 task 5
 Author: Group 12
 Members: E/18/115
          E/18/168
 */
/*

prescalar used = 1:256
T(counter_clock) = 256 * 1/16 = 16 micros
let time interval as 2 ms
counter increments needed = 2 ms/ 16 μs = 125
Initial counter value = 1+255-125 = 131 counts 

*/
#include <avr/io.h>
#include<avr/interrupt.h>


unsigned char z = 0;

void delay_timer0(){

    TCNT0 = 131;        //Load timer0 counter register

    TCCR0A = 0x00;    // set timer0 under normal mode
    TCCR0B = 0x04;    // set prescalar 1:256

    sei();            //enable global interrupts (I=1 in SREG)

    TIMSK0|=(1<<TOIE0);     //enable timer0 overflow interrupt for TOIE0

    /*TIMSK0 – Timer0/Counter Interrupt Mask Register
    Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
    When the TOIE0 bit is written to one, and the I-bit in the Status Register is set, the Timer/Counter0 Overflow
    interrupt is enabled. The corresponding interrupt is executed if an overflow in Timer/Counter0 occurs, i.e., when
    the TOV0 bit is set in the Timer/Counter 0 Interrupt Flag Register – TIFR0. 

    */
}


//function for Interrupt Time0/Counter0 Overflow
 ISR(TIMER0_OVF_vect){
    z++;        //increment z 
    TCNT0 = 131;  //Again loading the counter for initiation

    //for 100ms --> z should be 50 so
    if(z>=50){
        PORTB = PORTB^(1<<0);   //blink led
        z = 0;              

     }
        

 }




int main(void){

    DDRB |= (1<<0);  //declaring PORTB Pin 0 as output
    delay_timer0();  //calling timer0 delay to blink the led at PIN0

    while(1){}      //infinite loop


}
