/*
 * Use a RGB Led to fade between colours. 
 */
 
int redLed = 11;
int greenLed = 9;
int blueLed = 10;

String option;

int x,y,z;
int delayTime = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //UP
  
  for(y=0; y<=255; y++){
    analogWrite(greenLed, y);
    Serial.print("GREEN: ");
    Serial.println(y);
    delay(delayTime);
  }
  
  for(x=0; x<=255; x++){
    analogWrite(redLed, x);
    Serial.print("RED: ");
    Serial.println(x);
    delay(delayTime);
  }

  for(z=0; z<=255; z++){
    analogWrite(blueLed, z);
    Serial.print("BLUE: ");
    Serial.println(z);
    delay(delayTime);
  }

  // DOWN

  for(z=255; 0<=z; z--){
    analogWrite(blueLed, z);
    Serial.print("BLUE: ");
    Serial.println(z);
    delay(delayTime);
  }
  
  for(x=255; 0<=x; x--){
    analogWrite(redLed, x);
    Serial.print("RED: ");
    Serial.println(x);
    delay(delayTime);
  }
  
  for(y=255; 0<=y; y--){
    analogWrite(greenLed, y);
    Serial.print("GREEN: ");
    Serial.println(y);
    delay(delayTime);
  }
}
