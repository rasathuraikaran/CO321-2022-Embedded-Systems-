

/*
 * Lab2 Question2
 Author: Group 12
 Members: E/18/115
          E/18/168


Write a program that toggles pin PB0 (show using a connected LED) whenever the push
button is released, using external interrupts.
 */

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define BLINK_DELAY_MS 2000
int main(void)
{
  DDRD &= ~(1 << 2); // portD2 INT0   as input
  DDRB |= (1 << 0);  /// port B 0 as output
  PORTB |= (1 << 0);

  EICRA |= (1 << ISC01); // setting a falling edge detection
  EICRA |= (0 << ISC00); // setting a falling edge detection
  sei();
  EIMSK |= (1 << INT0); // enables the external interrupt

  while (1)
  {
    // never ending functions
  }
}
ISR(INT0_vect)
{
  PORTB = PORTB ^ (1 << 0);  // for toggling action
  _delay_ms(BLINK_DELAY_MS); // getting clear outputs
}

