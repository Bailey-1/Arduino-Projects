/*
 * Get the light level from the photoresistor and turn a green light 
 * on if it is light or a red light if it is dark.
 */
int lightPin = A0;
int lightVal;

int greenLed = 11;
int redLed = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  delay(50);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);

  if(lightVal <= 500){
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
  }
}
