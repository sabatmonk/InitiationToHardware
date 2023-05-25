#ifndef Pot_h
#include <Arduino.h>
#define Pot_h

class Pot
{
  public:
    Pot(int pin, int min, int max);
    void readValue();
    int getValue();
  private:
    int _pin;
    int _state;
    int _min;
    int _max;
};

#endif

