/*
 * Create a bit flipper using bitwise not 
 * https://www.arduino.cc/reference/en/language/structure/bitwise-operators/bitwisenot/
 */
int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte binNumber = 0b11000011;
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
  // Write the byte to the LEDs
  Serial.println(binNumber, BIN);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, binNumber);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  // Write the not of the byte to the LEDs
  Serial.println(~binNumber, BIN);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, ~binNumber);
  digitalWrite(latchPin, HIGH);
  delay(1000);
}
