int redLed = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(redLed, 0);

  for(int i=0; i<=255; i++){
        analogWrite(redLed, i);
        delay(5);
  }
  
  
  for(int i=255; i>=0; i--){
        analogWrite(redLed, i);
        delay(5);
  }
}
