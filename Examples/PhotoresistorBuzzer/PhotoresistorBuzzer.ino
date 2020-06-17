/*
 * Get the light level from the photoresistor and turn a green light 
 * on if it is light or a red light if it is dark.
 */
int lightPin = A0;
int lightVal;

int buzzPin = 8;
int delayTime;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  delayTime = (9./550.)*lightVal - (9.*200./550.)+1;

  Serial.println(delayTime);
  
//  digitalWrite(buzzPin, HIGH);
//  delayMicroseconds(delayTime);
//  digitalWrite(buzzPin, LOW);
//  delayMicroseconds(delayTime);
}
