/*
 * Set a active buzzer off when the potentiometer reads over 1020;
 * Don't use print or println with the buzzers since is slows the timing down significantly.
 */
int myNumb;
int buzzPin=8;
int i, x;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() { 
  for(x=1; x<=1000; x++){
    for(i=1; i<=50; i++){
      digitalWrite(buzzPin, HIGH);
      delayMicroseconds(x);
      digitalWrite(buzzPin, LOW);
      delayMicroseconds(x);
    }
  }
}
