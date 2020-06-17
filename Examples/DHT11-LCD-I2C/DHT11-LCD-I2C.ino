/*
 * 16*2 LCD I2C Display Example
 * fun fact this was a thing i wanted to make at the start.
 * 
 * SCL = A4
 * SDA = A5
 * VCC = 5V
 * GND = GND
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define Type DHT11
int sensePin = 2;

DHT myDHT(sensePin, Type);
LiquidCrystal_I2C myLCD(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

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
