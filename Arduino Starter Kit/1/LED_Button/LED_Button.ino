void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int switchState = digitalRead(2);
  bool repeat = false;

  if (switchState == LOW) {
    repeat = false;
  }
  else {
    repeat = true;
  }

  if (repeat == false) {
    digitalWrite(3, HIGH); //GREEN
    digitalWrite(4, LOW); //RED
    digitalWrite(5, LOW); //RED
    repeat = true;
  }
  else {
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
  
      delay(100);
  
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      delay(100);
  }
}
