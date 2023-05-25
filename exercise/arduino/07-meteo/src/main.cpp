#include <Arduino.h>
#include "RgbLed.h"
#include "Photo.h"
#include "Temp.h"


Photo photo(A5,0,255); //Since we know that the led use values between 0 and 255, we transpose the value of the photosensitive sensor to those values
RgbLed rgbLed(9,10,11); //Led requires a PWN pin (a special type of pin) to works. They are identified with a tile "~" on the board. Usually, it's the 5,5,6,9,10,11
Temp tempSensor(3); //Use an analog pin;

void setup(){
  tempSensor.begin(); //this is required
  rgbLed.begin();
}



void loop(){
  //here you will need to perform a read action on the analog sensors and then use those values on the setcolor function
  //Temperature can be obtained in celsius or in "american (F)"
  

  //note that function code must be BEFORE we use it in our code.
  rgbLed.setColor(0,0,0); //this is takes 3 values, between 0 and 255, first is the red value, the second is green and the last is blue. The result is a collor following additive color
}
