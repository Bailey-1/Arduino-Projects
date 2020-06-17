 /*
Pulse an LED with analogWrite. analogWrite changes the voltage from 0v - 5v over 0 - 255.
*/

int redLed = 9;

void setup() {
  pinMode(redLed, OUTPUT);
  
  Serial.begin(9600);  
}

void loop() {
  analogWrite(redLed, 0);
  
  Serial.print("Lowest Brightness"); 
  delay(5000);
  
  for(int i=0; i<=255; i++){
        analogWrite(redLed, i);
        Serial.println(i); 
        delay(10);
  }

  Serial.println("Max Brightness"); 
  delay(5000);

  for(int i=255; i>=0; i--){
        analogWrite(redLed, i);
        Serial.println(i);
        delay(10);
  }
}
