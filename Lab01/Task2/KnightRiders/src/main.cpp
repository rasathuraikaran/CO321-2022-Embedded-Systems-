#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 1000
int main (void){
//DDRB = DDRB|(1<<5); /* configure pin 5 of PORTB for output*/

unsigned char z;
DDRB=0xFF;
PORTB =0x00;
while(1){
//for (int i=0;i<4;i++){
 // PORTB =PORTB | (1<<i);
 // _delay_ms(BLINK_DELAY_MS);
 // PORTB = ~ PORTB |(1<<i);
    
//}

//for (int i=3;i>=0;i--){
 // PORTB =PORTB | (1>>i);
 // _delay_ms(BLINK_DELAY_MS);
 // PORTB = ~ PORTB |(1>>i);
    
//}
   PORTB =0b00000001;
     _delay_ms(BLINK_DELAY_MS);
    PORTB =0b00000010;
     _delay_ms(BLINK_DELAY_MS);
    PORTB =0b00000100;
     _delay_ms(BLINK_DELAY_MS);
    PORTB =0b00001000;
     _delay_ms(BLINK_DELAY_MS);
    PORTB =0b00000100;
     _delay_ms(BLINK_DELAY_MS);
    PORTB =0b00000010;
     _delay_ms(BLINK_DELAY_MS);
    PORTB =0b00000001;
     _delay_ms(BLINK_DELAY_MS);




   

}


}