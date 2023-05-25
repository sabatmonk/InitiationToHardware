#include "Arduino.h"

#include "Btn.h"


Btn::Btn(int pin)
{

  _pin = pin;
  _state = 0;

}
void Btn::begin()
{
  pinMode(_pin, INPUT);
}

void Btn::readValue(){
  _state = digitalRead(_pin);
}
int Btn::getValue(){
    return _state;
}
