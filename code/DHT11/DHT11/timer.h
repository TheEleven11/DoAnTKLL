#ifndef timer_h
#define timer_h

extern int timer0_flag;
extern int timer0_counter;
extern int TIMER_CYCLE;

void setTimer0(int);

void timerRun(void); 

#endif
