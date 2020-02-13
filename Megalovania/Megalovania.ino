#include "pitches.h"

// notes in the melody:
int melody[] = {
  //First Bar
  NOTE_D4, NOTE_D4, NOTE_D5, NOTE_G5, NOTE_R, NOTE_R, NOTE_GS5, NOTE_R,NOTE_G5,NOTE_F5,NOTE_D5,NOTE_F5,NOTE_G5,
  //Second Bar
  NOTE_C4, NOTE_C4, NOTE_D5,NOTE_G5, NOTE_R, NOTE_R, NOTE_GS5,NOTE_R,NOTE_G5,NOTE_F5,NOTE_D5,NOTE_F5,NOTE_G5,
  //Third Bar
  NOTE_B3, NOTE_B3, NOTE_D5,NOTE_G5, NOTE_R, NOTE_R, NOTE_GS5,NOTE_R,NOTE_G5,NOTE_F5,NOTE_D5,NOTE_F5,NOTE_G5,
  //Fourth Bar
  NOTE_AS3, NOTE_AS3, NOTE_D5,NOTE_G5, NOTE_R, NOTE_R, NOTE_GS5,NOTE_R,NOTE_G5,NOTE_F5,NOTE_D5,NOTE_F5,NOTE_G5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  //First Bar
  4, 4, 2, 4, 4, 4, 4, 4,2,2,4,4,4, 
  //Second Bar
  4, 4, 2, 4, 4, 4, 4, 4,2,2,4,4,4,
  //Third Bar
  4, 4, 2, 4, 4, 4, 4, 4,2,2,4,4,4,
  //Fourth Bar
  4, 4, 2, 4, 4, 4, 4, 4,2,2,4,4,4
};

void setup() {
 for (int i=0;i<52;i++)
{
  noteDurations[i]= noteDurations[i]*2;
}
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 52; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(11, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(11);
  }
}

void loop() {
  // no need to repeat the melody.
}
