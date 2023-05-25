#include "Arduino.h"

#include "RgbLed.h"


RgbLed::RgbLed(int rPin, int gPin, int bPin)
{

    _redPin = rPin;
    _greenPin = gPin;
    _bluePin = bPin;
    _redColor = 255;
    _greenColor = 255;
    _blueColor =255;

}
void RgbLed::begin()
{
    pinMode(_redPin, OUTPUT);
    pinMode(_greenPin, OUTPUT);
    pinMode(_bluePin, OUTPUT);
}

void RgbLed::turnOn(){
    analogWrite(_redPin,_redColor);
    analogWrite(_greenPin,_greenColor);
    analogWrite(_bluePin,_blueColor);
}
void RgbLed::turnOff(){
    analogWrite(_redPin,0);
    analogWrite(_greenPin,0);
    analogWrite(_bluePin,0);
    }
void RgbLed::flash(int delayTime){
    this->turnOn();
    delay(delayTime);
    this->turnOff();
    delay(delayTime);
}

void RgbLed::setColor(int r, int g, int b){
     #ifdef COMMON_ANODE
        r = 255 - r;
        g = 255 - g;
        b = 255 - b;
    #endif
    _redColor = r;
    _greenColor = g;
    _blueColor = b;
}