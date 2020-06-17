int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte binNumber = 0b00110011;
int loopedBit;

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  /*
   * Loops LEDs circularly right -> left
   */
//  digitalWrite(latchPin, LOW);
//  shiftOut(dataPin, clockPin, LSBFIRST, binNumber);
//  digitalWrite(latchPin, HIGH);
//  Serial.println(binNumber, BIN);
//  loopedBit = bitRead(binNumber, 7);
//  //Serial.println(loopedBit);
//  delay(1000); 
//  binNumber = binNumber * 2;
//  bitWrite(binNumber, 0, loopedBit);

  /*
   * Loops LEDs circularly left -> right
   */
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, binNumber);
  digitalWrite(latchPin, HIGH);
  Serial.println(binNumber, BIN);
  loopedBit = bitRead(binNumber, 0);
  //Serial.println(loopedBit);
  delay(1000); 
  binNumber = binNumber / 2;
  bitWrite(binNumber, 7, loopedBit);
}
