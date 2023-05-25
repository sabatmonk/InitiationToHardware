#ifndef Uds_h
#include <Arduino.h>
#define Uds_h

class Uds
{
  public:
    Uds(int in, int out);
    void begin();
    void calculateDistance();
    int getDistanceInCm();
  private:
    int _outPin;
    int _inPin;
    int _distance;
    int _duration;
};

#endif

