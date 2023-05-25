#include <Arduino.h>
#include "Led.h"
#include "Uds.h" //Ultrasonic Distance Sensor (the type of sensor used in this exercise)

Led led(2);
Uds uds(3,4);//make sure to check the wiring, the first is the read (in) and the second is the write (out)

void setup() {
  uds.begin();
}

void loop() {

  delay(50); //wait a tiny bit before rechecking distance or it could lead to errors
}
