#ifndef RgbLed_h
#include <Arduino.h>
#define RgbLed_h

class RgbLed
{
  public:
    RgbLed(int redPin, int greenPin, int bluePin);
    void begin();
    void turnOn();
    void turnOff();
    void flash(int delay);
    void setColor(int red, int green, int blue);
  private:
    int _redPin;
    int _greenPin;
    int _bluePin;
    int _redColor;
    int _greenColor;
    int _blueColor;
};

#endif

