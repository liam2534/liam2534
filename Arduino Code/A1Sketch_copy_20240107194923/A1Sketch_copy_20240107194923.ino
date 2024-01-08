void setup() {
  //Set up for loop to initialize pins
  for(int i=10; i <= 12; i++){
    //i corresponds to pin #, output is so the pin voltage is set to 5V or 0V
    pinMode(i, OUTPUT);
  }
}

void loop() {
  //introduce int "time" so that if someone wanted to change the delay,
  //they would only have to change one number instead of two.
  int time = 1000;

  //introduce for loop, i represents each pin #. It will cycle through each pin: 10-12.
  for(int i=10; i <= 12; i++){
    //sets pin i's voltage to HIGH (5V)
    digitalWrite(i, HIGH);
    //delays for "time" ms to keep light on for a moment
    delay(time);
    //sets pin i's voltage to LOW (OV), turning it off.
    digitalWrite(i, LOW);
    //delays for "time" ms to keep light off for a moment
    delay(time);
  }
}
