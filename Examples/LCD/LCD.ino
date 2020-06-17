/*
 * 16*2 LCD Display
 */
#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal myLcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  myLcd.begin(16, 2); // Columns, Rows
}

void loop() {
  // put your main code here, to run repeatedly:
  myLcd.setCursor(0, 0);
  myLcd.print("My name is bailey");
  delay(1000);
  myLcd.clear();
  myLcd.setCursor(0, 0);
  myLcd.print("Hello World");
  delay(1000);
  myLcd.clear();
}
