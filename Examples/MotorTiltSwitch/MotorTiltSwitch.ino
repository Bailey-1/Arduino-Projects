int speedPin = 5;
int dir1 = 4;
int dir2 = 3;

int tiltPin = 11;
int tiltPinVal;

int mSpeed = 255; // 0 - 255 speed

void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);

  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  tiltPinVal = digitalRead(tiltPin);
  Serial.println(tiltPinVal);

  if(tiltPinVal == 0){
    analogWrite(speedPin, mSpeed);
  } else {
    analogWrite(speedPin, 0);
  }
}
