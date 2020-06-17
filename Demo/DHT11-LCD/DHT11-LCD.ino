#include <LiquidCrystal.h>
#include <DHT.h>

#define Type DHT11
int sensePin = 2;

DHT myDHT(sensePin, Type);

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal myLcd(rs, en, d4, d5, d6, d7);

float humidity, tempC, tempF;

void setup() {
  // put your setup code here, to run once:
  myLcd.begin(16, 2);
  myDHT.begin();  
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myLcd.clear();
  
  humidity = myDHT.readHumidity();
  tempC = myDHT.readTemperature();
  tempF = myDHT.readTemperature(true);
  
  myLcd.setCursor(0, 0);
  myLcd.print("Humidity:  ");
  myLcd.print(humidity);
  myLcd.setCursor(0, 1);
  myLcd.print("C:");
  myLcd.print(tempC);
  myLcd.print("  F:");
  myLcd.print(tempF);
  delay(1500);
}
