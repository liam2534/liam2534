//runs this code once at the start
void setup() {
  //Sets bit rate for serial data transmission (matches baud in menu)
  Serial.begin(9600);
  //sets pin 5 to output
  pinMode(5, OUTPUT);
  //sets pin 6 to output
  pinMode(6, OUTPUT);
}

//loops this code repeatedly forever
void loop() {
  //prints the value that analogRead(A0) gives us to the Serial Monitor
  Serial.println(analogRead(A0));
  //I make an int fiveVoltage and map it to a value between 0 and 255 (inclusive)
  //so it can be passed into analogWrite() later. I chose the lower limits to be 
  //250 and 900 because those were the best bounds for the most obvious changes in lighting
  //for the room that I was in.
  int fiveVoltage = map(analogRead(A0), 250, 900, 0, 255);
  //made int sixCondition and mapped it to a value between 0 and 2 (inclusive)
  //so I could pass sixCondition into an if-else statement late to see if 
  //the photoresistor was covered or not
  int sixCondition = map(analogRead(A0), 250, 900, 0, 2);
  //prints value for fiveVoltage to the Serial Monitor
  Serial.println(fiveVoltage);
  //prints value for sixCondition to the Seiral Monitor
  Serial.println(sixCondition);
  //Prints a new line for readability purposes
  Serial.println();
  //Makes pin 5 output voltage proportional to what analogRead(A0) reads
  analogWrite(5, fiveVoltage);
  //checks to see if the sixCondition is 0, 1, or 2.
  //1 would be halfway between 250 and 900 on analogRead
  if(sixCondition < 1){
    //sets pin 6 to output 5V if condition is met (covered)
    digitalWrite(6, HIGH);
    //else statement for when sixCondition is !< 1
    //(when the photoresistor is uncovered)
  } else{
    //turns pin 6 to output 0V
    digitalWrite(6, LOW);
  }
  //delays 100ms for readability purposes on the Serial Monitor
  delay(100);
}