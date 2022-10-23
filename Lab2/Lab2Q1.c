

/*
 * Lab2 Question 1
 Author: Group 12
 Members: E/18/115 
          E/18/168
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 1000
int main (void){

unsigned char count;
DDRD &= 0x00; //pd7 as input 
DDRB=0xFF; // set the portb as output
PORTB =0x00; // set all  portb to low

while(1){

  //whenever the read the input in PIN
 if(PIND&(1<<7)){

		//if PIND gets input shows the working port as count
		PORTB=count;
     	 count++;//increamented by one 
	     _delay_ms(BLINK_DELAY_MS); 	
    	}
	}
  return 0;
}





   






