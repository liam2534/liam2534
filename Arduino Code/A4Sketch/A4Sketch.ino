//loading in library for PIR
#include "PIR.h"
//loading in library for Servo Motor
#include <Servo.h>
//making PIR object P
PIR P;
//making servo object S
Servo S;
//int for servo rotation value
int servoInt = 0;

//setup code runs once upon startup
void setup() {
  //adding PIR to pin 10
  P.add(10);
  //adding servo motor to pin 11
  S.attach(11);
}

//loop runs repeatedly
void loop() {
  //checks if PIR detects movement
  if(P.read() == 1){
    //rotates servo motor to position servoInt
    S.write(servoInt);
    //makes servo int higher by 15 degrees
    servoInt += 15;
    //checks if servoInt is greater than 180 degrees
    if(servoInt > 180){
      //resets servo int to reset servo motor position
      servoInt = 0;
   }
  }
  //delays for 200ms 
  delay(200);
}
