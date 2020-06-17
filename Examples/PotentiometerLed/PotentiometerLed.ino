/*
 * Use a potentionmeter to change the brightness of an LED.
 * It also checks if the value is low enough to register to count as 0 or high enough to count as 5v.
 * This is because the potentiometer is cheap and doesnt recognise edge cases accurately or consistantly.
 */
int readPin = A2;
int readValue; 
float v2;

int redLed = 9;
int redLedVal;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(readPin, INPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readValue = analogRead(readPin);
  v2 = (5./1023.) * readValue;
  redLedVal = readValue /4;

  if(redLedVal <= 10){
    analogWrite(redLed, 0);
    v2 = 0;
  } else if (redLedVal >= 245){
    analogWrite(redLed, 255);
    v2 = 5;
  } else {
    analogWrite(redLed, redLedVal);  
  }

  Serial.print("V=");
  Serial.print(v2);
  Serial.print(" Value=");
  Serial.println(redLedVal);
  
  delay(50);
}
