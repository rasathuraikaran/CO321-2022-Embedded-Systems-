/*
 * Lab1 task 2.c
  Author: Karan Rasathurai
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 3000
int main (void){
//DDRB = DDRB|(1<<5); /* configure pin 5 of PORTB for output*/

unsigned char z;
DDRB=0xFF; // set the portb as output
PORTB =0x00; // set the portb to low
while(1){
for (int i=0;i<4;i++){
  PORTB =PORTB | (1<<i); //activate a portbi
  _delay_ms(BLINK_DELAY_MS); //set delay
  printf("led lights on  ");
  PORTB =  PORTB &~ (1<<i);//Deactivate a portbi
  printf("led lights off  ");
    
}

for (int i=3;i>=0;i++){
  PORTB =PORTB | (1<<i);//activate a portbi
  _delay_ms(BLINK_DELAY_MS);//set delay
  PORTB =  PORTB &~(1<<i);//Deactivate a portbi
    
}


   



   

}


}
