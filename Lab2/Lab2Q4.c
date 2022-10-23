#include <Arduino.h>

/*
 * Lab2 Question 4
 Author: Group 12
 Members: E/18/115
          E/18/168
Connect two push buttons (A and B) to two external interrupt pins. Connect 6 LEDs to
a GPIO port. Write a program where a user can input a binary number using the two
push buttons (press A to input a '0', press B to input a '1') through external interrupts,
and display that number using the LEDs. The number must be updated and displayed
every time one of the buttons are pressed.

 */

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define BLINK_DELAY_MS 6000

int main(void)
{

        DDRD &= ~(1 << 2); // portD2 INT0   as input
        DDRD &= ~(1 << 3); // portD3 INT0   as input

        DDRB = 0xFF;  // set the portb as output
        PORTB = 0x00; // set all  portb to low

        EICRA |= (1 << ISC01);  // setting a rising edge detection PIND2
        EICRA |= ~(1 << ISC00); // setting a rising  edge detection PIND2
        EICRA |= (1 << ISC11);  // setting a rising  edge detection PIND3
        EICRA |= (1 << ISC10);  // setting a rising  edge detection PIND3
        sei();
        EIMSK |= (1 << INT0); // enables the external interrupt PIND2
        EIMSK |= (1 << INT1); // enables the external interrupt PIND3
        while (1)
        {
                // never ending loop
        }
}
ISR(INT0_vect)
{
        // Pind2 input is 0 so when get 0 only we have shift  the value is enought
        PORTB = PORTB << 1;

        _delay_ms(BLINK_DELAY_MS);
}
ISR(INT1_vect)
{
        // Pind3 input is 1 so when get 1  we have shift  the value and add one

        PORTB = PORTB << 1;
        PORTB++;
        _delay_ms(BLINK_DELAY_MS);
}

