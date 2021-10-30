
#include "timer.h"

int timer0_counter = 0;
int timer0_flag = 0; 

void setTimer0(int duration){
  timer0_counter = duration / TIMER_CYCLE ;
  timer0_flag = 0;
}

void timerRun( void ){ 
  if( timer0_counter > 0){
    timer0_counter --;
    if ( timer0_counter == 0) timer0_flag = 1;
   }
}
