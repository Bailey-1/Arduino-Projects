/*
 * Change the brightness of an LED with two pushbuttons.
 */
int ledPin = 9;
int upButton = 12;
int downButton = 11;

int ledBrightness = 0;
int upVal;
int downVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  upVal = digitalRead(upButton);
  downVal = digitalRead(downButton);

  if(upVal == 0){
    if(ledBrightness < 255){
      ledBrightness += 1;
    } else {
      Serial.println("MAX BRIGHTNESS ALREADY");
    }
  }

  if(downVal == 0){
    if(ledBrightness > 0){
      ledBrightness -= 1;
    } else {
      Serial.println("MAX DIMMNESS ALREADY");
    }
  }

  Serial.println(ledBrightness);
  analogWrite(ledPin, ledBrightness);
  
  delay(20);
}
