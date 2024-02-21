void setup() {
  pinMode(5, OUTPUT);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    if(Serial.read() == 0){
      digitalWrite(5, HIGH);
    } else{
      digitalWrite(5, LOW);
    }
  }

  Serial.println(analogRead(A0)); //X Value
  Serial.println(analogRead(A1)); //Y Value
  
  delay(500);
}
