#include "Arduino.h"
#include "Temp.h"
#include <OneWire.h> 
#include <DallasTemperature.h> 


Temp::Temp(int pin)
{

  OneWire oneWire(pin);
  _sensor = DallasTemperature(&oneWire);

}

void Temp::begin(){
    _sensor.begin();
}

void Temp::readTemperature(){
  _sensor.requestTemperatures();
}
float Temp::getCelsiusValue(){
    return _sensor.getTempCByIndex(0);
}
float Temp::getFaranheitValue(){
    return _sensor.getTempFByIndex(0);
}