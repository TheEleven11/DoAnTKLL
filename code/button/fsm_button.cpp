#include "fsm_button.h"
#include "button_reading.h"
#include "Arduino.h"
enum state{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_2_SECOND} ;

int ledState = LOW;

enum state stateButton = BUTTON_RELEASED;
void fsm_for_button( void ) {
  switch(stateButton){
    case BUTTON_RELEASED:
      if(is_button_pressed()){
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
        stateButton = BUTTON_PRESSED;
      }
      break;
    case BUTTON_PRESSED:
      if(!is_button_pressed()){
        stateButton = BUTTON_RELEASED;
      }
      else {
        if(is_button_pressed_2s()){
          stateButton = BUTTON_PRESSED_MORE_THAN_2_SECOND;
        }
      }
      break;
    case BUTTON_PRESSED_MORE_THAN_2_SECOND:
      if(!is_button_pressed()){
        stateButton = BUTTON_RELEASED;
      }
      else{
        if(is_auto_change()){
          ledState = !ledState;
          digitalWrite(ledPin, ledState);
          reset_flag_auto_change();
          stateButton = BUTTON_PRESSED_MORE_THAN_2_SECOND;
        }
      }
      break;
    default:
      break;
  }
}
