#include <Arduino.h>
#include "Btn.h"
#include "Led.h"

Btn button(3); //change to the pin number of the button



void setup() {
  // initialize the button as an input:
  button.begin();
}

void loop() {
  // read the state of the button value, it is a digital read, the button must then be connected to a digital pin:
  button.readValue();

  // a conditionnal should be checked here, if the button is pressed, buttonState will be HIGH (or 1, either is fine). It should look like if(buttonState == ...)
  if(button.getValue()==1){
    //what to do if the button is pressed
  }else{
    //what to do if the button is not pressed
  }
}
