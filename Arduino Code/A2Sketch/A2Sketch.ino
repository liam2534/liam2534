void setup() {
  /*
  what I want it to do:

  WHEN BUTTON IS PUSHED, THUS PIN READS HIGH

  11 goes from always on to pulsing,
  10 goes from pulsing to on
  9 goes from off to blinking

  0 is my dig

  */

  for(int i = 9; i <12; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(2, INPUT);
}

void loop() {
  //put your main code here, to run repeatedly:
  if(digitalRead(2) == LOW){
    digitalWrite(11, HIGH);
    for(int i =0; i<=255; i+=5){

      analogWrite(10,i);
      delay(50);
      if(digitalRead(2) != LOW){
        break;
      }
    }
    for(int i = 255; i>=0; i-=5){
      analogWrite(10,i);
      delay(50);
      if(digitalRead(2) != LOW){
        break;
      }
    }
    digitalWrite(9, LOW);
  } else{
      digitalWrite(10, LOW);
      for(int i =0; i<=255; i+=5){
        analogWrite(11,i);
        if(i%2==0){
          digitalWrite(9,HIGH);
        } else{
          digitalWrite(9,LOW);
        }
        delay(50);
        if(digitalRead(2) != HIGH){
          digitalWrite(9,LOW);
          break;
        }
      }
      for(int i = 255; i>=0; i-=5){
        analogWrite(11,i);
        if(i%2==0){
          digitalWrite(9,HIGH);
        } else{
          digitalWrite(9,LOW);
        }
        delay(50);
      if(digitalRead(2) != HIGH){
        digitalWrite(9,LOW);
        break;
      }
      }
    }
}












