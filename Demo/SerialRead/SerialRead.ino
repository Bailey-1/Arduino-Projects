/*
 * Get a int from the user and then blink the LED that number of times.
 */

int num;
int ledPin = 12;
int i;

int blinkTime = 250;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Enter a number: ");

  while(Serial.available()==0){
    
  }
  num = Serial.parseInt();
  Serial.println(num);

  for(i=1; i<=num; i++){
    digitalWrite(ledPin, HIGH);
    delay(blinkTime);
    digitalWrite(ledPin, LOW);
    delay(blinkTime);
    Serial.print("Blink no. ");
    Serial.println(i);
  }
}
