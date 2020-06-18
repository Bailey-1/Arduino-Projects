/* 
 * Distance measuring thing using HCSR-04, I2C 1602 LCD and a button;
 * 
 * SCL = A5
 * SDA = A4
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int buttonPin = 2;
int buttonVal;
// LCD
LiquidCrystal_I2C myLcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// HCSR04
int trigPin = 12;
int echoPin = 11;
int pingTravelTime;
float inches, cm;

int numOfMeasurements = 50;
int i, average;
long total;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
    
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myLcd.clear();
  myLcd.begin(16, 2);
  myLcd.setCursor(2, 0);
  myLcd.print("Press Button");
  myLcd.setCursor(4, 1);
  myLcd.print("To Start");
  
  //Loop here when button is not pressed.
  while(digitalRead(buttonPin) == 1){
    
  }
  
  myLcd.clear();
  myLcd.setCursor(3,0);
  Serial.println("Measuring!");
  myLcd.print("Measuring!");
  total = 0;

  // Do the recording a bunch of times to create an average to make it more accurate.
  for(i=0; i<50; i++){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10); // 1000000 Microseconds = 1 Second
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    pingTravelTime = pulseIn(echoPin, HIGH);
    delay(25);
    total = total + pingTravelTime;
    Serial.println(total);
  }

  average = total / 50;
  Serial.print("Average: ");
  Serial.println(average);

  // Conversions
  inches = ((average*765.*5280.*12)/(3600.*1000000))/2;
  cm = (average * 0.0343)/2;

  myLcd.clear();
  
  myLcd.setCursor(0, 0);
  myLcd.print("CM:");
  myLcd.setCursor(3, 0);
  myLcd.print(cm);

  myLcd.setCursor(10, 0);
  myLcd.print("T:");
  myLcd.setCursor(12, 0);
  myLcd.print(average);

  myLcd.setCursor(0, 1);
  myLcd.print("Inches:");
  myLcd.setCursor(7, 1);
  myLcd.print(inches);

  delay(5000);
}
