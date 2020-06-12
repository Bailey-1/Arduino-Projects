int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
int upButton = 10;
int downButton = 11;

int upButtonVal, downButtonVal;
int upButtonOld = 0;
int downButtonOld = 0; 

int motorSpeed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT); 
  pinMode(dir2, OUTPUT);
  
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  digitalWrite(upButton, HIGH);
  digitalWrite(downButton, HIGH);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  upButtonVal = digitalRead(upButton);
  downButtonVal = digitalRead(downButton);

  // Nest it to stop both buttons pushed together.
  if(upButtonVal == 0 and downButtonVal == 0){
    Serial.println("Please don't press both buttons at the same time!");
  } else {
    if (upButtonVal == 0 and upButtonOld == 1){
      // Increase speed
      if(motorSpeed == 0 or motorSpeed == -100){
        motorSpeed += 100;
      } else if ((motorSpeed >= 100 and motorSpeed < 250) or (motorSpeed < -100 and motorSpeed >= -250)){
        motorSpeed += 10;  
      } else if ((motorSpeed == 250) or (motorSpeed == -255)){
        motorSpeed += 5;
      } else {
        Serial.println("MAX SPEED");
      }
      Serial.println(motorSpeed);
    } else if (downButtonVal == 0 and downButtonOld == 1){
      // Decrease speed
      if(motorSpeed == 0 or motorSpeed == 100){
        motorSpeed -= 100;
      } else if ((motorSpeed <= -100 and motorSpeed > -250) or (motorSpeed > 100 and motorSpeed <= 250)){
        motorSpeed -= 10;  
      } else if ((motorSpeed == -250) or (motorSpeed == 255)){
        motorSpeed -= 5;
      } else {
        Serial.println("MAX SPEED");
      }
      Serial.println(motorSpeed);
    }
  }

  if(motorSpeed > 0){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
  } else {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
  }
  analogWrite(speedPin, abs(motorSpeed));
  
  upButtonOld = upButtonVal;
  downButtonOld = downButtonVal;
}
