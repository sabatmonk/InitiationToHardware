#include <Arduino.h>
#include "Pot.h"
#include "Led.h"

Pot pot(A6,0,100); //Change A6 for the analog pin used (make sure to use A before the number). 0 and 100 are the minimum and maximum that we want to have from the potentionmeter

void setup() {
    // we do not need to use begin(setting the pin mode) in analog (analog pin are input only)
}

void loop() {
    pot.readValue();
    if(pot.getValue()>50){ //it will be between 0 and 100
    
    }else if(pot.getValue()<25){ //you can have has many "if" as you want this way, but if 2 condition are true, the first one is taken

    }else{ //this will be used if the value is not higher than 50 nor smaller than 25 (so 25-50)

    }
}
