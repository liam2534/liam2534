void setup() {
  // put your setup code here, to run once:
  for(int i = 9; i <12; i++){
    //i represents each pin, and it gets set to output
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(11,64);
  analogWrite(10,128);
  analogWrite(9,255);

}
