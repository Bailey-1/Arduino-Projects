/*
 * Set a active buzzer off when the potentiometer reads over 1020;
 */
int myNumb;
int buzzPin=8;

int delay1 = 1;
int delay2 = 2;
int i, x;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  for(i=1; i<=100; i++){
//    digitalWrite(buzzPin, HIGH);
//    delay(delay1);
//    digitalWrite(buzzPin, LOW);
//    delay(delay1);
//  }
//
//  for(i=1; i<=100; i++){
//    digitalWrite(buzzPin, HIGH);
//    delay(delay2);
//    digitalWrite(buzzPin, LOW);
//    delay(delay2);
//  }

  for(x=1; x<=100; x=x+2){
    for(i=1; i<=50; i++){
    digitalWrite(buzzPin, HIGH);
    delay(x);
    digitalWrite(buzzPin, LOW);
    delay(x);

    Serial.print("x: ");
    Serial.print(x);
    Serial.print(" i: ");
    Serial.println(i);
    }
  }
}
