#ifndef timer_h
#define timer_h

#define TIMER_CYCLE  10

extern int timer0_flag;
extern int timer0_counter;

void setTimer0(int);

void timerRun(void); 

#endif
