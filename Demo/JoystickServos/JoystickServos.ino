#include <Servo.h>

Servo xservo;
Servo yservo;

int xpin = A0;
int ypin = A1;
int spin = 2;
int xspin = 9; // X Servo Pin
int yspin = 10; // Y Servo Pin

int wvx;
int wvy;

int xval;
int yval;
int sval;
int dt = 200;
void setup() {
  // put your setup code here, to run once:
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(spin, INPUT);

  pinMode(xspin, OUTPUT);
  pinMode(yspin, OUTPUT);

  digitalWrite(spin, HIGH);

  xservo.attach(xspin);
  yservo.attach(yspin);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  xval = analogRead(xpin);
  wvx = (180./1023.)* xval; 

  yval = analogRead(ypin);
  wvy = (180./1023.)* yval;
  
  xval = analogRead(xpin);
  yval = analogRead(ypin); 
  sval = digitalRead(spin);

  xservo.write(wvx);
  yservo.write(wvy);

  Serial.print("X: ");
  Serial.print(xval);

  Serial.print(" Y: ");
  Serial.print(yval);

  Serial.print(" Switch: ");
  Serial.println(sval);
  delay(200 );

}
