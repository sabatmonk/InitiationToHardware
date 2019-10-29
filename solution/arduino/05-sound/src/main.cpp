#include <Arduino.h>
#include <Music.h>
const int speakerPin = 6;
const int ledPin = 2;
Music musicPlayer = Music(speakerPin,ledPin); // This is a home made library to play some tunes, i added the syncing of the led with the music, so its easier for you
void setup() {
    pinMode(ledPin,OUTPUT);
    pinMode(speakerPin,OUTPUT);
}

void loop() {
    musicPlayer.sing(4,100); //this start a song (the first parameter is the song number) at the given spped (the second parameter is the speed in percent of regular play)
}
