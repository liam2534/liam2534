//runs setup once
void setup() {
  //sets pin 5 to output for LED
  pinMode(5, OUTPUT);
  //Starts the serial monitor
  Serial.begin(9600);
}

//loop runs repeatedly
void loop() {
  //if there is available serial from p5
  if (Serial.available()){
    //if it reads 0, turns light off. Otherwise, turns it off.
    if(Serial.read() == 0){
      //turns light on
      digitalWrite(5, HIGH);
      //enters this branch when Serial.read != 0
    } else{
      //if Serial.read() != 0, turns LED off
      digitalWrite(5, LOW);
    }
  }
  
  //prints X value (from joystick) from A0 to serial monitor
  Serial.print(analogRead(A0));
  //prints a comma to separate X and Y value (see below) 
  Serial.print(",");
  //prints Y value (from joystick) from A1 to the same line after the comma and then makes a new line
  Serial.println(analogRead(A1));
  //add 50ms delay
  delay(50);
}
