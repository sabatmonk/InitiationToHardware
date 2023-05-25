#include "Arduino.h"

#include "Led.h"


Led::Led(int pin)
{

  _pin = pin;

}
void Led::begin()
{
  pinMode(_pin, OUTPUT);
}

void Led::turnOn(){
  digitalWrite(_pin, HIGH);
}
void Led::turnOff(){
  digitalWrite(_pin,LOW);
}
void Led::flash(int delayTime){
  digitalWrite(_pin,HIGH);
  delay(delayTime);
  digitalWrite(_pin,LOW);
  delay(delayTime);
}