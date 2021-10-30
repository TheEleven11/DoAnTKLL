#include "timer.h"
#include "fsm_button.h"
#include "button_reading.h"

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(ledPin, LOW);
}

void loop() {
  button_reading();
  fsm_for_button();
  delay(10);
}
