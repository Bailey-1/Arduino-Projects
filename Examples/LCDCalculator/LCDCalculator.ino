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

int num1, num2, op, result;
char opChar;

void setup() {
  // put your setup code here, to run once:
  myLcd.begin(16, 2); // Columns, Rows
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myLcd.clear();
  myLcd.setCursor(0, 0);
  myLcd.print("First Number:");
  Serial.println("First Number:");
  while(Serial.available() == 0){
    
  }
  num1 = Serial.parseInt();
  Serial.println(num1);
  
  myLcd.clear();
  myLcd.setCursor(0, 0);
  myLcd.print("Second Number:");
  Serial.println("Second Number:");
  while(Serial.available() == 0){
    
  }
  num2 = Serial.parseInt();
  Serial.println(num2);
  
  myLcd.clear();
  myLcd.setCursor(0, 0);
  myLcd.print("Operation:");
  myLcd.setCursor(0, 1);
  myLcd.print("1+ 2- 3* 4/");
  while(Serial.available() == 0){
    
  }
  op = Serial.parseInt();
  Serial.println(op);
  switch(op){
    case 1:
      result = num1 + num2;
      opChar = '+';
      break;
    case 2:
      result = num1 - num2;
      opChar = '-';
      break;
    case 3:
      result = num1 * num2;
      opChar = '*';
      break;
    case 4:
      result = num1 / num2;
      opChar = '/';
      break;
  }

  myLcd.clear();
  myLcd.setCursor(0, 0);
  myLcd.print("Result:");
  myLcd.setCursor(0, 1);
  myLcd.print(num1);
  myLcd.print(opChar);
  myLcd.print(num2);
  myLcd.print("=");
  myLcd.print(result);
  
  delay(5000);
}
