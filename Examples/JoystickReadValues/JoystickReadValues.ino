int xpin = A0;
int ypin = A1;
int spin = 2;

int xval;
int yval;
int sval;

void setup() {
  // put your setup code here, to run once:
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(spin, INPUT);
  digitalWrite(spin, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  xval = analogRead(xpin);
  yval = analogRead(ypin); 
  sval = digitalRead(spin);
  delay(200 );

  Serial.print("X: ");
  Serial.print(xval);

  Serial.print(" Y: ");
  Serial.print(yval);

  Serial.print(" Switch: ");
  Serial.println(sval);
}
