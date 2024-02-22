  //loading in library for Servo Motor
  #include <Servo.h>
  //making servo object S
  Servo S;
  //int for servo rotation value
  #include <CapacitiveSensor.h>

  int currentVal = 0;
  int lastVal = 0;
  

  CapacitiveSensor   C = CapacitiveSensor(4,2);    	// 1 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, metal thing

  
  //setup code runs once upon startup
  void setup() {
    C.set_CS_AutocaL_Millis(0xFFFFFFFF); 	// turn off autocalibrate on channel 1 - just as an example
    Serial.begin(9600);

    //adding servo motor to pin 11
    S.attach(9);
    S.write(0);
  }
  
  //loop runs repeatedly
  void loop() {
    currentVal = C.capacitiveSensor(30);

    
    if (currentVal > 2000 && lastVal < 2000){
      S.write(50);
      delay(100);
      S.write(0);
      delay(1000);
    }

    Serial.println(currentVal);

    lastVal = currentVal;
  }            