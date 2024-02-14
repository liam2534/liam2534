//loading in library for PIR
#include "PIR.h"
//loading in library for Servo Motor
#include <Servo.h>
//making PIR object P
PIR P;

//make brightness int
int brightness = 0;
//make checker int variable for PIR 
int lastVal;
//make checker int var for PIR
int currentVal;
//make brightness level array for PIR
int blvl[] = {25, 150, 255};


//setup code runs once upon startup
void setup() {
  //adding PIR to pin 10
  P.add(10);
  //set pin 10 to output mode
  pinMode(9, OUTPUT);

  Serial.begin(9600);
}

//loop runs repeatedly
void loop() {
  //checks if PIR detects movement
  currentVal = P.read();
    if(currentVal == 1 && currentVal != lastVal){
      analogWrite(9, blvl[brightness]);
      brightness++;
      delay(5000);
      analogWrite(9, 0);
      if(brightness >2){
        brightness = 0;
      }
    }
  Serial.println(currentVal);

  lastVal = currentVal;
}
