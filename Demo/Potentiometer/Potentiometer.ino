int readPin = A2;
int readValue; 
float v2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readValue = analogRead(readPin);
  v2 = (5./1023.) * readValue;
  Serial.println(v2);
}
