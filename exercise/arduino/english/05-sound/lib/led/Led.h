#ifndef Led_h
#include <Arduino.h>
#define Led_h

class Led
{
  public:
    Led(int pin);
    void begin();
    void turnOn();
    void turnOff();
    void flash(int delay);
  private:
    int _pin;
};

#endif

