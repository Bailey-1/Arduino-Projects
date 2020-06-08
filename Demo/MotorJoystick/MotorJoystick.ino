int speedPin = 5;
int dir1 = 4;
int dir2 = 3;

int mSpeed = 255;

int xpin = A0;
int ypin = A1;

int xpinval;
int ypinval;

void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT); 
  pinMode(dir2, OUTPUT);
  
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  xpinval = analogRead(xpin);
  ypinval = analogRead(ypin);

  Serial.print(xpinval);
  Serial.print(" ");
  Serial.println(ypinval);

  if (ypinval > 582 and ypinval < 542){
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
    analogWrite(speedPin, 0 );
  } else if(ypinval >= 512){
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    mSpeed = (255./512.)* ypinval - 255;
    analogWrite(speedPin, mSpeed);
  } else if (ypinval <= 512){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    mSpeed = (-255./512.)* ypinval + 255;
    analogWrite(speedPin, mSpeed);
  }
  delay(10);
}
