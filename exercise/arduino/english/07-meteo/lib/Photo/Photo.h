#ifndef Photo_h
#include <Arduino.h>
#define Photo_h

class Photo
{
  public:
    Photo(int pin, int min, int max);
    void readValue();
    int getValue();
  private:
    int _pin;
    int _state;
    int _min;
    int _max;
};

#endif

