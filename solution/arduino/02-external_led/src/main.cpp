#include <Arduino.h>
int the_led = 2;    // assign the number 12 to variable the_led. It is the pin number where the led is connected

void setup() {
  pinMode(the_led, OUTPUT);     // define the_led as an output
}

void loop() {
  digitalWrite(the_led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                   // wait for a second
  digitalWrite(the_led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
}
