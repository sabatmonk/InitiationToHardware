#include <Arduino.h>
#include <OneWire.h> //For the temperature
#include <DallasTemperature.h> // also for the temperature

#define ONE_WIRE_BUS 3 //it define ONE_WIRE_BUS to equal 3 whenever it is written
const int photoPin = A5;
const int potentionmeterPin = A7; //We'll use potentionmeter as our 3rd sensor
int photoValue;
int potValue;
float CValue=0;
float FValue=0;
int redPin = A2; //we need to define a pin for each color
int greenPin = A4;
int bluePin = A6;


OneWire oneWire(ONE_WIRE_BUS); //required for temperature reading, internet will help you understand if you are interested

DallasTemperature sensors(&oneWire); //required for temperature reading, internet will help you understand if you are interested

void setup(){
  pinMode(photoValue, INPUT); //this registration is optional
  pinMode(potentionmeterPin, INPUT);
  sensors.begin(); //this is required
  pinMode(redPin, OUTPUT); //also one per color
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
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
  potValue = analogRead(potentionmeterPin);
  sensors.requestTemperatures(); //sensor now hold the temperature
  CValue=sensors.getTempCByIndex(0); //Canadian temp, because frezzing is Zero and it make more sense
  Serial.println(CValue);
  potValue = map(potValue,0,1023,0,255);
  photoValue = map(photoValue, 0, 1023,0,255); // an array start at 0, we keep the logic, it could be 1, but the if/else would have to be modified
  //We do not use map on CValue, because it is temp and i have to assumptions: 1(No one is doing this in freezing temp) 2(no on is doing this over 255 celcius OR faranheit)

  //note that function code must be BEFORE we use it in our code.
  setColor(CValue,potValue,photoValue); //this is how you call a function. Note that this one takes number from 0 to 255, as this is the range of a write function, and also the max value of a color.
}
