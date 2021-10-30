#include "button_reading.h"
#include "timer.h"
#include "Arduino.h"

#define DURATION_FOR_AUTO_INCREASING     2000/TIMER_CYCLE
#define DURATION_FOR_AUTO_CHANGE       2000/TIMER_CYCLE

int buttonBuffer;
int buttonState1;
int buttonState2;
int buttonState3;

int counterForButtonPress2s;
int flagForButtonPress2s;

int counterAutoChange = DURATION_FOR_AUTO_CHANGE;
int flagForAutoChange;

void button_reading(void){
    buttonState3 = buttonState2;
    buttonState2 = buttonState1;
    
    buttonState1 = digitalRead(buttonPin);
    
    if(buttonState1 == buttonState2 && buttonState2 == buttonState3){
      buttonBuffer = buttonState1;
    }
    if(buttonBuffer == LOW){
        if(counterForButtonPress2s < DURATION_FOR_AUTO_INCREASING){
          counterForButtonPress2s++;
        }
        else {
          flagForButtonPress2s = 1;
          counterAutoChange++;
          if(counterAutoChange >= DURATION_FOR_AUTO_CHANGE){
            flagForAutoChange = 1;
            counterAutoChange = 0;
          }
        }
      } else {
        counterForButtonPress2s = 0;
        flagForButtonPress2s = 0;
        
        counterAutoChange = DURATION_FOR_AUTO_CHANGE;
        flagForAutoChange = 0;
      }
}

bool is_button_pressed(){
  return (buttonBuffer == LOW);
}

bool is_button_pressed_2s(){
  return (flagForButtonPress2s == 1);
}

bool is_auto_change(){
  return (flagForAutoChange == 1);
}

void reset_flag_auto_change(){
  flagForAutoChange = 0;
}
