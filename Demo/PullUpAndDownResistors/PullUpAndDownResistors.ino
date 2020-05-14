int ledPin = 8;
int upRead = 12;
int downRead = 11;

int upReadVal;
int downReadVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(upRead, INPUT);
  pinMode(downRead, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  upReadVal = digitalRead(upRead);
  Serial.print("Up Read: ");
  Serial.println(upReadVal);
  
  downReadVal = digitalRead(downRead);
  Serial.print("Down Read: ");
  Serial.println(downReadVal);
  
//  if(buttonRead ==0){
//    digitalWrite(ledPin, HIGH);
//  } else {
//    digitalWrite(ledPin, LOW);
//  }
  
  delay(250);
}
