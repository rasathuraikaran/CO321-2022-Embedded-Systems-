
/*
XTAL=16 MHz
Txal_clock=1/16microseconds

---->take prescaler as 1:8 

prescaler=1:8
TCounterClock=8 * 1/16
            =0.5microsec
conter increaments needed=2000 /0.5 = 4000 
Initial counter value=1+255-4000
                      =it is inappropiraite




---->take prescaler as 1:1024 

prescaler=1:1024
TCounterClock=1024 * 1/16
            =64microsec
conter increaments needed=2000 /64 = 31.25
Initial counter value=1+255-31.25
                      =it is inappropiraite (it is in decimal)


---->take prescaler as 1:256

prescaler=1:256
TCounterClock=256 * 1/16
            =16microsec
conter increaments needed=2000 /16 = 125
Initial counter value=1+255-125
                      =131



---->take prescaler as 1:64
prescaler=1:64
TCounterClock=64 * 1/16
            =4microsec
conter increaments needed=2000 /4 = 500
Initial counter value=1+255-500
                      =-244 (inappropriate)


So suitable prescaler is  1:256 
*/




#include <avr/io.h>
void delay_timer0(){
  TCNT0=131; //Load  timer counter register


  TCCR0A=0x00; // set the Timer0 under normalmode
  TCCR0B=0x04; //with prescale of 1:256
   
  while((TIFR0&0x00)==0);//wait till timer overflow bit (TOV0) is set


  TCCR0A=0x00; // clear timer setting (this stops timer)
  TCCR0B=0x00;

  TIFR0=0x01;//clear the timer overflow bit
}

int main(void){
  DDRB=DDRB|(1<<5);
  while(1){
    PORTB=PORTB^(1<<5); //toggle pin 5
    delay_timer0();

   
   

  }
}
