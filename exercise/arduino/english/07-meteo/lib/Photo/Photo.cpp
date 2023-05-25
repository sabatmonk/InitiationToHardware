#include "Arduino.h"

#include "Photo.h"


Photo::Photo(int pin, int min, int max)
{

  _pin = pin;
  _state = 0;
  _min = min;
  _max = max;

}

void Photo::readValue(){
  _state = analogRead(_pin);
}
int Photo::getValue(){
    return map(_state, 0,1023,_min,_max);
}
