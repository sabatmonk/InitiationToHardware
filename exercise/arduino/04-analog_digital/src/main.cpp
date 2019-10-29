#include <Arduino.h>
const int potentiometerPin = A6;
int potentiometerValue = 0; //Do you know why this is not a const?

void setup() {
    // we do not need to set pinMode in this analog read
}

void loop() {
    potentiometerValue = analogRead(potentiometerPin); //This is the reason it is not a const
    potentiometerValue = map(potentiometerValue, 0, 1023,0,1000); //This is explained in the guide
}
