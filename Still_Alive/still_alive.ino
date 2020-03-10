#include "pitches.h"
int melody[] = {
   //key:sharpC and sharp f
  //First Bar two beat pickup
  NOTE_R,NOTE_R,NOTE_R,NOTE_R,NOTE_G4,NOTE_F4, NOTE_E4, NOTE_E4,
  //second bar
  NOTE_,NOTE_R,NOTE_R,
  //third bar
  NOTE_R,NOTE_R,NOTE_A4,NOTE_G4,NOTE_F4, NOTE_E4, NOTE_E4
  //
 
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  //First Bar
 8,8,8,8,8,8,8,8,
//second bar
 4,4,2,
 //third bar
 4,8,8,8,8,8,8
};

void setup() {

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 12; thisNote++) {

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
