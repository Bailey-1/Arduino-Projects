#include <Stepper.h>
int stepsPerRevolution = 2048;
int motSpeed = 10;


Stepper myStepper(stepsPerRevolution, 8,10,9,11);

void setup() {
  // put your setup code here, to run once:

  myStepper.setSpeed(motSpeed);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myStepper.step(2048);
  delay(500);
  myStepper.step(-2048);
  delay(500);

}
