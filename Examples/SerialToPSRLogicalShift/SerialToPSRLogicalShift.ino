int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte binNumber;

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  
  Serial.begin(9600);
}

void loop() {
  binNumber = 0b01011111;
  // put your main code here, to run repeatedly:

  for(int i=0; i<=8; i++){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, binNumber);
    digitalWrite(latchPin, HIGH);
    Serial.println(binNumber, BIN);
    delay(1000);
    binNumber = binNumber * 2;
  }

  binNumber = 0b11011011;

  for(int i=8; i>=0; i--){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, binNumber);
    digitalWrite(latchPin, HIGH);
    Serial.println(binNumber, BIN);
    delay(1000);
    binNumber = binNumber / 2;
  }
}
