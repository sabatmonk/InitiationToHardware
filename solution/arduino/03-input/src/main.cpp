#include <Arduino.h>


const int button = 3;     // the  pin number of the button
const int the_led = 2;    // assign the number 2 to variable the_led. It is the pin number where the led is connected

int buttonState = 0;      // this is the state ofthe button, 0 is off 1 is on

void setup() {
  pinMode(button, INPUT);       // initialize the button as an input:
  pinMode(the_led, OUTPUT);     // define the_led as an output

}

void loop() {
  // read the state of the button value, it is a digital read, the button must then be connected to a digital pin:
  buttonState = digitalRead(button);

  // a conditionnal should be checked here, if the button is pressed, buttonState will be HIGH (or 1, either is fine). It should look like if(buttonState == ...)
  if(buttonState==HIGH){
    digitalWrite(the_led, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else{
    digitalWrite(the_led, LOW);   // turn the LED off (LOW is the voltage level)
  }
}
