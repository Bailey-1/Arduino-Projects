int redLed = 11;
int greenLed = 9;
int blueLed = 10;

String option;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("What colour do you want?");

  while(Serial.available()==0){
    
  }
  option = Serial.readString();
  
  Serial.print("Choice: ");
  Serial.println(option);

  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, LOW);
  digitalWrite(greenLed, LOW);  
  
  if(option == "red"){
    digitalWrite(redLed, HIGH);
    digitalWrite(blueLed, LOW);
    digitalWrite(greenLed, LOW);
  } else if (option == "blue"){
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, HIGH);
    digitalWrite(greenLed, LOW);
  } else if (option == "green"){
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, LOW);
    digitalWrite(greenLed, HIGH);
  } else if (option == "all"){
    digitalWrite(redLed, HIGH);
    digitalWrite(blueLed, HIGH);
    digitalWrite(greenLed, HIGH);
  } else if (option == "none"){
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, LOW);
    digitalWrite(greenLed, LOW);
  }
}
