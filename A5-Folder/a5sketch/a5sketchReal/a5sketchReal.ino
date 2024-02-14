//loading in library for PIR
#include "PIR.h"
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
}

//loop runs repeatedly
void loop() {
  //checks if PIR detects movement
  currentVal = P.read();
    //check to make sure light only turns on per each time the PIR detects movement, not necessarily as long as the PIR reads "HIGH/1"
    if(currentVal == 1 && currentVal != lastVal){
      //makes pin 9 output "brightness" amount of voltage. This goes to the transistor, which makes the LEDs
      //proportionally bright
      analogWrite(9, blvl[brightness]);
      //brightness int increases to cycle through the array blvl
      brightness++;
      //light stays on for 5000ms
      delay(5000);
      //turns light off after delay
      analogWrite(9, 0);
      //checks if brightness is greater than max of blvl array
      if(brightness >2){
        //resets to avoid error
        brightness = 0;
      }
    }
  //makes currentVal lastVal to ensure if statement works
  lastVal = currentVal;
}
