#include <Servo.h>

int servoPin = 9;
int servoPos = 0;

int photoPin = A0;
int photoPinVal;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
  pinMode(photoPin, INPUT);
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myServo.write(servoPos);

  photoPinVal = analogRead(photoPin);

  //servoPos = (1./18.) * photoPinVal + 850./18.;
  servoPos = (-16./63.)* photoPinVal + 16. * 780. /63.;
  if (servoPos < 0) servoPos = 0;
  Serial.println(servoPos); 
  delay(100);
}
