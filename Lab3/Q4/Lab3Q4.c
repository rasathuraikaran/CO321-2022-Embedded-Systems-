

/*
 * Lab3 task 4
 Author: Group 12
 Members: E/18/115
          E/18/168
 */

/*
prescalar used = 1:256
T(counter_clock) = 256 * 1/16 = 16 μs
counter increments needed = 1000 ms/ 16 μs = 62500
Initial counter value = 1+65535-62500 = 3036

*/
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 1000
#include <avr/interrupt.h>

void delay_time1()
{
  TCNT1 = 3036; // load the timer1 counter register

  TCCR1A = 0x00; // set to normal mode
  TCCR1B = 0x04; // set the prescale 1:256

  sei(); // enable global interrupts (I=1 in SREG)

  TIMSK1 |= (1 << TOIE1); // enable timer1 overflow interrupt for TOIE1
}

// function for Interrupt Time1/Counter1 Overflow
ISR(TIMER1_OVF_vect)
{
    PORTB=PORTB^(1<<5);/*toggle pin 5*/
  TCNT1 = 3036;             // Again loading the counter for initiation
}

int main(void)
{
  // DDRB = DDRB|(1<<5); /* configure pin 5 of PORTB for output*/
    DDRB|=(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<5);//PB0,PB1,PB2,PB3,PB5 output
delay_time1();
  // calling timer1 delay to toggle the led at PIN5
while(1){
  
  for (int i = 0; i < 4; i++)
  {

    PORTB = PORTB | (1 << i);  // setting a portbi
    _delay_ms(BLINK_DELAY_MS); // set delay
    PORTB = PORTB & ~(1 << i); // clearing the single a portbi
  }

  for (int i = 2; i > 0; i--)
  {

    PORTB = PORTB | (1 << i);  // setting a single a portbi
    _delay_ms(BLINK_DELAY_MS); // set delay
    PORTB = PORTB & ~(1 << i); // clearing the single  a portbi
  }

 
}
}

