
#include "timer.h"

const int buttonPin = 2;     
const int ledPin =  13; 
int ledStatus = LOW;     
void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    digitalWrite(ledPin, LOW);
    setTimer0(1000);
}

void loop() {
  if(timer0_flag == 1){
    ledStatus = !ledStatus;
    digitalWrite(ledPin, ledStatus);
    setTimer0(1000);
  }
  timerRun();
  delay(10);
}
