#include <Arduino.h>
#include <Music.h>

const int songSpeedPotPin = A5;
const int SongSelectPotPin = A6;
const int speakerPin = 9;
int songSpeedValue = 0;
int songChoiceValue = 0;
int buttonState = 0;
const int buttonPin = 3;
const int the_led1 = 5;
const int the_led2 = 6;
const int the_led3 = 7;
const int the_led4 = 8;

Music musicPlayerMario = Music(speakerPin,the_led2); //I could mofidy the library to be able to change the led, but it would be too easy ;)
Music musicPlayerUnderMario = Music(speakerPin,the_led2);
Music musicPlayerImperial = Music(speakerPin,the_led3);
Music musicPlayerGoT = Music(speakerPin,the_led4);


void setup() {
  pinMode(the_led1,OUTPUT);
  pinMode(the_led2,OUTPUT);
  pinMode(the_led3,OUTPUT);
  pinMode(the_led4,OUTPUT);
  pinMode(speakerPin,OUTPUT);
  pinMode(SongSelectPotPin,INPUT);
  pinMode(songSpeedPotPin,INPUT);
  pinMode(buttonPin,INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  songSpeedValue = analogRead(songSpeedPotPin);
  songSpeedValue = map(songSpeedValue, 0, 1023,25,500); //we stop a 500, over that serve no puposes as 5x speed is already fast
  songChoiceValue = analogRead(SongSelectPotPin);
  songChoiceValue = map(songChoiceValue, 0, 1023,0,3); // an array start at 0, we keep the logic, it could be 1, but the if/else would have to be modified
  selectionLightUpdate(songChoiceValue);
  if(buttonState==HIGH){
    if(songChoiceValue == 0){//There is a better way, called a switch/case method, but it is not relevent to the guide. Might be added in later versions
      musicPlayerMario.sing(songChoiceValue, songSpeedValue);
    }else if(songChoiceValue == 1){
      musicPlayerUnderMario.sing(songChoiceValue, songSpeedValue);
    }else if(songChoiceValue == 2){
      musicPlayerImperial.sing(songChoiceValue, songSpeedValue);
    }else if(songChoiceValue == 3){
      musicPlayerGoT.sing(songChoiceValue, songSpeedValue);
    }
  }
}

void selectionLightUpdate(int songChoice){ //this is not needed and not in the challenge, yet, but it can be a nice side challenge for interested ppl
  if(songChoiceValue == 0){//There is a better way, called a switch/case method, but it is not relevent to the guide. Might be added in later versions
    digitalWrite(the_led1,HIGH);
    digitalWrite(the_led2,LOW);
    digitalWrite(the_led3,LOW);
    digitalWrite(the_led4,LOW);
  }else if(songChoiceValue == 1){
    digitalWrite(the_led1,LOW);
    digitalWrite(the_led2,HIGH);
    digitalWrite(the_led3,LOW);
    digitalWrite(the_led4,LOW);
  }else if(songChoiceValue == 2){
    digitalWrite(the_led1,LOW);
    digitalWrite(the_led2,LOW);
    digitalWrite(the_led3,HIGH);
    digitalWrite(the_led4,LOW);
  }else if(songChoiceValue == 3){
    digitalWrite(the_led1,LOW);
    digitalWrite(the_led2,LOW);
    digitalWrite(the_led3,LOW);
    digitalWrite(the_led4,HIGH);
  }
}
