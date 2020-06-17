#include <DHT.h>

#define Type DHT11
int sensePin = 2;

DHT myDHT(sensePin, Type);
float humidity, tempC, tempF;

void setup() {
  // put your setup code here, to run once:
  myDHT.begin();  
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = myDHT.readHumidity();
  tempC = myDHT.readTemperature();
  tempF = myDHT.readTemperature(true); // True to read in F

  Serial.print("Humidity: ");
  Serial.print(humidity);

  Serial.print(" Temperature C: ");
  Serial.print(tempC);

  Serial.print(" Temperature F: ");
  Serial.println(tempF);

  delay(1000);
}
