#include "Arduino.h"

#include "Uds.h"


Uds::Uds(int in, int out)
{

  _inPin = in;
  _outPin = out;


}
void Uds::begin()
{
  pinMode(_outPin, OUTPUT);
  pinMode(_inPin, INPUT);
}

void Uds::calculateDistance(){
  digitalWrite(_outPin, LOW);
  delayMicroseconds(5);
  digitalWrite(_outPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_outPin, LOW);
  _duration = pulseIn(_inPin, HIGH);
  _distance= _duration*0.034/2;
}
int Uds::getDistanceInCm(){
  return _distance;
}
