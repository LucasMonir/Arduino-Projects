#include "pitches.h"

int melody[]{
  NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5, 
  NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5, 
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5, 
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5
};

int durations[] = {
  8, 8, 8, 4, 4, 4, 
  4, 5, 8, 8, 8, 8, 
  8, 8, 8, 4, 4, 4, 
  4, 5, 8, 8, 8, 8
};


int songLength=sizeof(melody)/sizeof(melody[0]);

void setup() {
  // put your setup code here, to run once:

}


void loop() {
  
  for(int notaAtual=0; notaAtual<songLength;notaAtual++){
    int duration = 1000/durations[notaAtual];
    tone(8,melody[notaAtual],duration);
    int pause=duration * 1.3;
    delay(pause);
    noTone(8);
  }
}
