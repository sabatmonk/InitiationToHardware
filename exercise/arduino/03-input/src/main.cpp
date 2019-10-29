#include <Arduino.h>


const int button = 3;     // the  pin number of the button

int buttonState = 0;      // this is the state ofthe button, 0 is off 1 is on

void setup() {
  // initialize the button as an input:
  pinMode(button, INPUT);
}

void loop() {
  // read the state of the button value, it is a digital read, the button must then be connected to a digital pin:
  buttonState = digitalRead(button);

  // a conditionnal should be checked here, if the button is pressed, buttonState will be HIGH (or 1, either is fine). It should look like if(buttonState == ...)
}
