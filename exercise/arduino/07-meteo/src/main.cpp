#include <Arduino.h>
#include <OneWire.h> //For the temperature
#include <DallasTemperature.h> // also for the temperature

#define ONE_WIRE_BUS 3 //what could a define be, it looks like its defining something...
const int photoPin = A5;
int photoValue;
float CValue=0;
float FValue=0;
int redPin = A2; //we need to define a pin for each color
int greenPin = A4;
int bluePin = A6;

OneWire oneWire(ONE_WIRE_BUS); //required for temperature reading, internet will help you understand if you are interested

DallasTemperature sensors(&oneWire); //required for temperature reading, internet will help you understand if you are interested

void setup(){
 pinMode(photoValue, INPUT); //this registration is optional
 sensors.begin(); //this is required
 pinMode(redPin, OUTPUT); //also one per color
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT);
}

void setColor(int red, int green, int blue) //This is a function, i give it to you, its stole from https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/arduino-sketch
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red); //we use analogWrite because digital is limited to 1 and 0, we want more control (0 to 255). it allows shades of colors
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}


void loop(){
  photoValue = analogRead(photoPin); //this value can be from 0 to 1023, you will need to play around to find the tiping point from light to dark
  //If only there was a fuction to make this range colser to the RGB limits (0 to 255)
  sensors.requestTemperatures(); //sensor now hold the temperature
  CValue=sensors.getTempCByIndex(0);
  FValue=sensors.toFahrenheit(CValue); //if you prefer American temperature
  //note that function code must be BEFORE we use it in our code.
  setColor(0,200,200); //this is how you call a function. Note that this one takes number from 0 to 255, as this is the range of a write function, and also the max value of a color.
}
