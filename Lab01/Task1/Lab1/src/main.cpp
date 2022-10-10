#include <avr/io.h>  //standard avr header 
#include <util/delay.h>
#define BLINK_DELAY_MS 1000
int main (void){
//DDRB = DDRB|(1<<5); /* configure pin 5 of PORTB for output*/


DDRB=0xFF;   //PortB is output 
PORTB =0x0F; // 1111 port 0,1,2,3, on
while(1){
PORTB = ~ PORTB ;// lights off
_delay_ms(BLINK_DELAY_MS);// delay the bulb


}


}