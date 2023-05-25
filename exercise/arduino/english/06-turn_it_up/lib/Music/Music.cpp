/*
This play predetermined music with a led blinking to the beat
Songs are :
1-->Mario main theme
2-->Mario underworld
3-->Star wars imperial march
*/
#include <Music.h>
#include <Arduino.h>

int _buzzerPin;
int _ledPin;
//Mario main theme melody
int mainMelody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int mainTempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

int imperial_march_melody[]= {
  NOTE_G4,NOTE_G4, NOTE_G4, NOTE_DS4,
  NOTE_AS4, NOTE_G4, NOTE_DS4,NOTE_AS4,
  NOTE_G4, NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_DS5, NOTE_AS4, NOTE_FS4, NOTE_DS4,
  NOTE_AS4, NOTE_G4, NOTE_G5,NOTE_G4,NOTE_G4,
  NOTE_G5,NOTE_FS5, NOTE_F5,NOTE_E5,
  NOTE_DS5,NOTE_E5, 0, NOTE_G4, 0,
  NOTE_CS5,NOTE_C5,NOTE_B4,NOTE_AS4,
  NOTE_A4,NOTE_AS4, 0, NOTE_DS4, 0,
  NOTE_FS4, NOTE_DS4,NOTE_AS4, NOTE_G4 ,
  NOTE_DS4,NOTE_AS4, NOTE_G4
};

 int imperial_tempo[] = {
   4, 4, 4, 8,
   14, 4, 10 , 10 ,
   2 , 4, 4, 4,
   8, 14, 4, 10,
   14, 2,4,10,
   14,4,10,14,14,
   14, 14,10,14,14,
   4,10,14,14,14,
   14,10,14,14,7,
   10,14,4,14,14,2
 };

 int game_of_throne_melody[] ={
   NOTE_G4,NOTE_C4,NOTE_DS4,NOTE_F4,
   NOTE_G4,NOTE_C4,NOTE_DS4,NOTE_F4,
   NOTE_G4,NOTE_C4,NOTE_DS4,NOTE_F4,
   NOTE_G4,NOTE_C4,NOTE_DS4,NOTE_F4,
   NOTE_G4,NOTE_C4,NOTE_E4,NOTE_F4,
   NOTE_G4,NOTE_C4,NOTE_E4,NOTE_F4,
   NOTE_G4,NOTE_C4,NOTE_E4,NOTE_F4,
   NOTE_G4,NOTE_C4,NOTE_E4,NOTE_F4,
   NOTE_G4,NOTE_C4,NOTE_E4,NOTE_F4,
   NOTE_G4,NOTE_C4,NOTE_DS4,NOTE_F4,
   NOTE_D4,NOTE_G3,NOTE_AS3,NOTE_C4,
   NOTE_D4,NOTE_G3,NOTE_AS3,NOTE_C4,
   NOTE_D4,NOTE_G3,NOTE_AS3,NOTE_C4,
   NOTE_D4,NOTE_F4,NOTE_AS3,NOTE_DS4,
   NOTE_D4,NOTE_F4,NOTE_AS3,NOTE_DS4,
   NOTE_D4,NOTE_C4,
   NOTE_G3,NOTE_AS3,NOTE_C4,NOTE_F3,
   NOTE_G3,NOTE_AS3,NOTE_C4,NOTE_F3,
   NOTE_G3,NOTE_AS3,NOTE_C4,NOTE_F3,
   NOTE_G4,NOTE_C4,NOTE_DS4,NOTE_F4,
   NOTE_G4,NOTE_C4,NOTE_DS4,NOTE_F4,
   NOTE_D4,
   NOTE_G3,NOTE_AS3,NOTE_C4,NOTE_D4,
   NOTE_G3,NOTE_AS3,NOTE_C4,NOTE_D4,
   NOTE_G3,NOTE_AS3,NOTE_C4,NOTE_D4,
   NOTE_G3,NOTE_AS3,NOTE_C4,NOTE_D4
};

int game_of_throne_tempo[] ={
  10,10,14,14,
  10,10,14,14,
  10,10,14,14,
  10,10,14,14,
  10,10,14,14,
  10,10,14,14,
  10,10,14,14,
  10,10,14,14,
  2,2,14,14,
  6,6,14,14,
  10,10,14,14,
  10,10,14,14,
  10,10,14,14,
  2,2,6,14,
  14,6,6,14,
  14,10,
  14,14,10,10,
  14,14,10,10,
  14,14,10,10,
  6,6,14,14,
  6,6,14,14,
  10,
  10,14,14,10,
  10,14,14,10,
  10,14,14,10,
  10,14,14,10
};

Music::Music(int buzzPin,int ledPin){
    _ledPin = ledPin;
    _buzzerPin=buzzPin;
}

void Music::buzz(long frequency, long length) {
  digitalWrite(_ledPin, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(_buzzerPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(_buzzerPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(_ledPin, LOW);

}

void Music::play(int melody[],int tempo[], int size, int speedModifier){
  //int size = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = (10*speedModifier) / tempo[thisNote];

    buzz(melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    buzz(0, noteDuration);

  }
}

void Music::sing(int song, int speedModifier) {
  switch (song) {
    case 1:
      play(mainMelody, mainTempo,sizeof(mainMelody) / sizeof(int),speedModifier);
      break;
    case 2:
      play(underworld_melody, underworld_tempo,sizeof(underworld_melody) / sizeof(int),speedModifier);
      break;
    case 3 :
      play(imperial_march_melody, imperial_tempo,sizeof(imperial_march_melody) / sizeof(int),speedModifier);
      break;
    case 4 :
      play(game_of_throne_melody, game_of_throne_tempo,sizeof(game_of_throne_melody) / sizeof(int),speedModifier);
      break;
    default:
      play(mainMelody, mainTempo,sizeof(mainMelody) / sizeof(int),speedModifier);
      break;
  }
}
