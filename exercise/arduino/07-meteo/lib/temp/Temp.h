#ifndef Temp_h
#include <Arduino.h>
#include <OneWire.h> 
#include <DallasTemperature.h> 
#define Temp_h

class Temp
{
  public:
    Temp(int pin);
    void begin();
    void readTemperature();
    float getCelsiusValue();
    float getFaranheitValue();
  private:
    DallasTemperature _sensor;
};

#endif

