

/*
 * Lab2 Q3
 Author: Group 12
 Members: E/18/115
	 E/18/168
Extend the program in part 2, so that the number of times the push button was released
is displayed as a binary number on a set of LEDs connected to PORTB.
 */

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define BLINK_DELAY_MS 3000
unsigned char count;

int main(void)
{

	DDRD &= ~(1 << 2); // portD2 INT0   as input
	DDRB = 0xFF;	   // set the portb as output
	PORTB = 0x00;	   // set all  portb to low

	EICRA |= (1 << ISC01);	// setting a falling edge detection
	EICRA &= ~(1 << ISC00); // setting a falling edge detection
	sei();
	EIMSK |= (1 << INT0); // enables the external interrupt
	while (1)
	{
	}
}

//whenever interupt signal calls this function will work
ISR(INT0_vect)
{
	PORTB = count; //portB shows the output as count 
	count++; // increament the count 
	_delay_ms(BLINK_DELAY_MS);
}

