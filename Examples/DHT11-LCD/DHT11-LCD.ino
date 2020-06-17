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

LiquidCrystal myLCD(rs, en, d4, d5, d6, d7);

float humidity, tempC, tempF;

void setup() {
  // put your setup code here, to run once:
  myLCD.begin(16, 2);
  myDHT.begin();  

  myLCD.clear();

  // Writing this once and only updating the number positions stops it flashing each time it is updated.
  myLCD.setCursor(0, 0);
  myLCD.print("Humidity:  ");
  myLCD.setCursor(0, 1);
  myLCD.print("C:");
  myLCD.setCursor(9, 1);
  myLCD.print("F:");
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = myDHT.readHumidity();
  tempC = myDHT.readTemperature();
  tempF = myDHT.readTemperature(true);
  
  myLCD.setCursor(11, 0);
  myLCD.print(humidity);
  
  myLCD.setCursor(2, 1);
  myLCD.print(tempC);
  
  myLCD.setCursor(11, 1);
  myLCD.print(tempF);
  delay(1500);
}
