/*
 * Runs the stepper motor forwards until the button is pressed and then
 * moves the other way until the button is pressed again.
 * It doesnt change between the two quickly when the button is held down.
 */
#include <Stepper.h>

int stepsPerRevolution = 2048;
int motSpeed = 10;

int button = 2;
int buttonVal;
int stepperForwards = true;
int recent = 1;

//Stepper myStepper(stepsPerRevolution, 8,10,9,11);
Stepper myStepper(stepsPerRevolution, 8,10,9,11);

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  digitalWrite(button, HIGH);
  myStepper.setSpeed(motSpeed);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal = digitalRead(button);

  // Recent must be 1 to show that the button has just been
  // pushed down and to ignore when held down.
  if(buttonVal == 0 && recent == 1){
    stepperForwards = !stepperForwards;
  }
  //Serial.println(stepperForwards);

  if (stepperForwards == 0){
    myStepper.step(6);
    Serial.println("Forwards");
  } else {
    myStepper.step(-6);
    Serial.println("Backwards");
  }
  
  recent = buttonVal;
}
