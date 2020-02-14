#include "pitches.h"
int melody[] = {
  //First Bar
  NOTE_D3, NOTE_C3, NOTE_E3, NOTE_G3,NOTE_E3,NOTE_C3,NOTE_D3
 
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  //First Bar
 8,8,8,8,4,8,1
};

void setup() {

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 7; thisNote++) {

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
void loop(){}
