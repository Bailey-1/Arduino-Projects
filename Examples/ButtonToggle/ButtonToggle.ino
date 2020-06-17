int ledPin = 8;
int buttonPin = 12;

int buttonPinVal;
int recent = 1;
bool ledOn = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonPinVal = digitalRead(buttonPin);
  Serial.print("ButtonPin: ");
  Serial.println(buttonPinVal);

  // Decide if the LED should change value
  // this is because you only want to change the LED if the recent was the opposite
  // Meaning the button has been pushed and not held down.
  if(buttonPinVal == 1 && recent == 0){
    ledOn = !ledOn;
  } else {
    //Nothing
  }

  // Change the LED value based on the value of ledOn
  if(ledOn == true){
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // Use recent to see what the previous value was and to see
  // if there has been a change e.g. off to on or if it is the same
  // as on to on. - this stops the LED flashing.
  recent = buttonPinVal;
  
  //delay(250);
}
