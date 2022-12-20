

/*
 * Lab3 task 6
 Author: Group 12
 Members: E/18/115
          E/18/168
 */
/*
/*
----------------------------For timer0--------------------------
prescalar used = 1:256
T(counter_clock) = 256 * 1/16 = 16 μs
let time interval as 2 ms
counter increments needed = 2 ms/ 16 μs = 125
Initial counter value = 1+255-125 = 131

*/


#include <avr/io.h>
#include<avr/interrupt.h>

unsigned char timer0 = 0;   //count for timer0


//delay function for timer0 for time interval 2 ms
void delay_timer0(){

    TCNT0 = 131;        //Load timer0 counter register

    TCCR0A = 0x00;    // set timer0 under normal mode
    TCCR0B = 0x04;    // set prescalar 1:256

    sei();            //enable global interrupts (I=1 in SREG)

    TIMSK0|=(1<<TOIE0);     //enable timer0 overflow interrupt for TOIE0

   
}


//function for Interrupt Time0/Counter0 Overflow
 ISR(TIMER0_OVF_vect){
    timer0++;      //increment timer0 
    TCNT0 = 131;  //Again loading the counter for initiation

    //for 50ms --> timer0 should be 25 so
    if(timer0>=25){
        PORTB = PORTB^(1<<0);   //blink led
        timer0 = 0;              

     }
        
 }


/*
----------------------------For timer1--------------------------
prescalar used = 1:256
T(counter_clock) = 256 * 1/16 = 16 μs
counter increments needed = 500 ms/ 16 μs = 31250
Initial counter value = 1+65535-31250 = 34,286

*/

//delay function for timer1 for time interval 500 ms
void delay_timer1(){
  TCNT1=34286;       //load the timer1 counter register

  TCCR1A=0x00;      //set to normal mode
  TCCR1B=0x04;      //set the prescale 1:256
  
  sei();            //enable global interrupts (I=1 in SREG)

  TIMSK1 |= (1<<TOIE1);    //enable timer1 overflow interrupt for TOIE1

 

 }

//function for Interrupt Time1/Counter1 Overflow
 ISR(TIMER1_OVF_vect){
    PORTB=PORTB^(1<<1);  //toggle led in PORTB PIN1
    TCNT1=34286;         //Again loading the counter for initiation
 
}



 int main(void){

    DDRB |= ((1<<1)|(1<<0));  //declaring PORTB Pin 0 and Pin1 as output
    delay_timer0();  //calling timer0 delay to blink the led at PIN0
    delay_timer1();  //calling timer1 delay to blink the led at PIN1

    while(1){}      //infinite loop


}
