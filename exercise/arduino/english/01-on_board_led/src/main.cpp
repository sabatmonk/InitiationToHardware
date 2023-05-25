#include <Arduino.h>
#include "Led.h"
int onboard_led = LED_BUILTIN;


Led led(onboard_led); //tells the board which led to use (in this case, the onboard led) 

void setup() {
    led.begin(); //important step called the initialisation. This "prepare" the led for usage later
}

void loop() {
    led.turnOn();
    delay(1000); //create a pause in the program, since it is in milliseconds, this means "wait 1 second before continuing" Not putting this would make the led flash so fast we would see it
    led.turnOff();
    delay(1000);
    led.flash(1000); //this commands is the same as the past 4 lines
}
