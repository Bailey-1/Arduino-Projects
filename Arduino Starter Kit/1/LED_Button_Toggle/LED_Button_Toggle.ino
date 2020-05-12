bool oldButtonState = LOW;
int x = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int newButtonState = digitalRead(2);

  if (newButtonState == HIGH && oldButtonState == LOW) {

    if (x == 0) {
      // Toggle on
      digitalWrite(3, HIGH); //GREEN
      digitalWrite(4, LOW); //RED
      digitalWrite(5, LOW); //RED
      
      x = 1;

    } else {
      // Toggle off
      digitalWrite(3, LOW); //GREEN
      digitalWrite(4, HIGH); //RED
      digitalWrite(5, HIGH); //RED
      
      x = 0;
    }
    delay(250);
  }
}
