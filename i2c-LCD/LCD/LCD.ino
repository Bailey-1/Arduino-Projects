/*
 * 16*2 LCD I2C Display Example
 * 
 * Simple Pins for Single I2C Device - Will have issues if more are added or required.
 * SCL = A4
 * SDA = A5
 * VCC = 5V
 * GND = GND
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C myLcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  // put your setup code here, to run once:
  myLcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  myLcd.setCursor(0, 0);
  myLcd.print("  Hello World!");
  delay(1000);
  myLcd.clear();
  myLcd.setCursor(0, 1);
  myLcd.print("  Hello World!");
  delay(1000);
  myLcd.clear();
}
