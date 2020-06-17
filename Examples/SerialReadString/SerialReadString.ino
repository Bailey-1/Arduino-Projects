/*
 * Get a int from the user and then blink the LED that number of times.
 */

String option;

int greenLed = 4;
int blueLed = 5;
int redLed = 6;
int yellowLed = 7;

int i;

int blinkTime = 250;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("What colour LED do you want to flash?");
  Serial.println("Green");
  Serial.println("Blue");
  Serial.println("Red");
  Serial.println("Yellow");
  while(Serial.available()==0){
    
  }

  option = Serial.readString();

  if(option == "green"){
    digitalWrite(greenLed, HIGH);
    delay(250);
    digitalWrite(greenLed, LOW);
  } else if (option == "blue"){
    digitalWrite(blueLed, HIGH);
    delay(250);
    digitalWrite(blueLed, LOW);
  } else if (option == "red"){
    digitalWrite(redLed, HIGH);
    delay(250);
    digitalWrite(redLed, LOW);
  } else if (option == "yellow"){
    digitalWrite(yellowLed, HIGH);
    delay(250);
    digitalWrite(yellowLed, LOW);

  } 
}
