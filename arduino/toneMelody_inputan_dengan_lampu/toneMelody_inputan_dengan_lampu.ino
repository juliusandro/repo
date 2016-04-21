
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_A7, NOTE_B7, NOTE_C8
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  1, 2, 3, 1, 3, 1, 3
};

void setup() {
  // iterate over the notes of the melody:
  Serial.begin(9600);
 pinMode(2, OUTPUT);
 pinMode(1, OUTPUT);
  }


void loop() {
  // no need to repeat the melody.
 int a= Serial.parseInt();
 if(a>0){
 tone(8,melody[a]-1,200);
 }
 if(a%2==0){
  digitalWrite(2,LOW);
  digitalWrite(1,HIGH);
  
  }
  else{
     digitalWrite(1,LOW);
    digitalWrite(2,HIGH);
 
    }
 delay(100);
  
}
