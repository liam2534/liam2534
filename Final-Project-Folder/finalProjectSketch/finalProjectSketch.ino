  //loading in library for Servo Motor
  #include <Servo.h>
  //making servo object S
  Servo S;
  //int for servo rotation value
  #include <CapacitiveSensor.h>

  //current value int to be used in loop section
  int currentVal = 0;
  //last value int to be compared to currentVal int later in loop section
  int lastVal = 0;
  
  //Making a capacitive sensor object C
  CapacitiveSensor   C = CapacitiveSensor(4,2);

  //setup code runs once upon startup
  void setup() {
    //starts the serial monitor
    Serial.begin(9600);

    //adding servo motor to pin 11
    S.attach(9);
    //sets the servo motor's position to 0 degrees
    S.write(0);
  }
  
  //loop runs repeatedly
  void loop() {
    //reads in the current value from the capactitiveSensor() function, takes in 30, which is the number of times the sensor is measured, the elapsed time is
    //returned in "arbitrary units" (according to the documentation) for this library. Generally speaking, the higher the number returned, the more contact is being made with the sensor
    currentVal = C.capacitiveSensor(30);

    //checks if currentVal is > 2000 and if lastVal is < 2000
    //if it is the case, the servo motor moves to dispense the treat
    if (currentVal > 2000 && lastVal < 2000){
      //moves the servo to 60 degrees
      S.write(60);
      //delays 100ms to give enough time for servo to move
      delay(100);
      //resets servo position to 0
      S.write(0);
      //delays one second
      delay(1000);
    }
    //sets lastVal = currentVal to ensure the if statement works properly
    lastVal = currentVal;
  }            