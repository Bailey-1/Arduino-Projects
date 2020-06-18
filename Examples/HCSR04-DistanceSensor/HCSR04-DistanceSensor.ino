/*
 * Distance sensor in both inches and cm;
 * Not very accurate but cheap.
 */
int trigPin = 12;
int echoPin = 11;
int pingTravelTime;
float inches, cm;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10); // 1000000 Microseconds = 1 Second
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTravelTime = pulseIn(echoPin, HIGH);
  delay(250);
  inches = ((pingTravelTime*765.*5280.*12)/(3600.*1000000))/2;
  cm = (pingTravelTime * 0.0343)/2;
  Serial.print("Time: ");
  Serial.println(pingTravelTime);
  Serial.print("CM: ");
  Serial.println(cm);
  Serial.print("Inches: ");
  Serial.println(inches);

}
