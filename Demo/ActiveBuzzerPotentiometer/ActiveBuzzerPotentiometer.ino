/*
 * Set a active buzzer off when the potentiometer reads over 1020;
 */
int myNumb;
int buzzPin=8;
int readPin=A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myNumb = analogRead(readPin);
  Serial.println(myNumb);
  
  if(myNumb>1000){
    digitalWrite(buzzPin, HIGH);  
  } else {
    digitalWrite(buzzPin, LOW);
  }
}
