#include "Arduino.h"

#include "Pot.h"


Pot::Pot(int pin, int min, int max)
{

  _pin = pin;
  _state = 0;
  _min = min;
  _max = max;

}

void Pot::readValue(){
  _state = analogRead(_pin);
}
int Pot::getValue(){
    return map(_state, 0,1023,_min,_max);
}
