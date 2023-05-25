#ifndef Btn_h
#include <Arduino.h>
#define Btn_h

class Btn
{
  public:
    Btn(int pin);
    void begin();
    void readValue();
    int getValue();
  private:
    int _pin;
    int _state;
};

#endif

