/*
USING THE TONE LIBRARY
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 A fancier Tone library is also available; download and details here:
 http://code.google.com/p/rogue-code/wiki/ToneLibraryDocumentation
 
 You may have to add the following line to the Tone.cpp file in the
 library to get it to work with Arduino 1.0:
   #include <Arduino.h>
   
 */


void setup() {
  // nothing here!
}

void loop() {
  if (millis() % 500 == 0) {
    tone(13, NOTE_C4, 250);
  }
}
