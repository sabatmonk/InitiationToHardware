#include <Arduino.h>
#include <OneWire.h> //For the temperature
#include <DallasTemperature.h> // also for the temperature

#define ONE_WIRE_BUS 3 //it define ONE_WIRE_BUS to equal 3 whenever it is written
const int photoPin = A5;
const int potentionmeterPin = A1;
const int button = 3;
const int speakerPin = 9;
const int ledPin = 2;

int photoValue;
int potValue;
float CValue=0;
int buttonState = 0;




OneWire oneWire(ONE_WIRE_BUS); //required for temperature reading, internet will help you understand if you are interested

DallasTemperature sensors(&oneWire); //required for temperature reading, internet will help you understand if you are interested

Music musicPlayer = Music(speakerPin,ledPin);

void setup(){
  pinMode(photoValue, INPUT); //this registration is optional
  pinMode(potentionmeterPin, INPUT);
  pinMode(button, INPUT);
  sensors.begin(); //this is required
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop(){
  photoValue = analogRead(photoPin); //this value can be from 0 to 1023, you will need to play around to find the tiping point from light to dark
  sensors.requestTemperatures(); //sensor now hold the temperature
  CValue=sensors.getTempCByIndex(0); //Canadian temp, because frezzing is Zero and it make more sense
  potValue = analogRead(potValue);
  buttonState = digitalRead(button);

  potValue = map(potValue,0,1023,0,10000); //lets limit the timer at 10 sec so 100000 millisec
  photoValue = map(photoValue, 0, 1023,0,3); // there is 4 songs : 0-3
  CValue = map(CValue, 15, 60,0,3); //Lets set the minimum of the temp to 15, otherwise the room is cold and we have quarters so, lets also limit it a 60

  if(buttonState == HIGH){
    if(photoValue<1){ //0-1 represent 50 our the light limit since we map it to 0-3, about normal lit room
      digitalWrite(ledPin,HIGH)
      delay(1000);//we wait 1 sec so we can go to bed
    }else{
      digitalWrite(ledPin,LOW)
    }
    delay(potValue);
    musicPlayer.sing(photoValue,CValue);
  }
}
