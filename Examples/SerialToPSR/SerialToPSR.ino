int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

/* Hex
 * 0x00 = 0000 0000
 * 0x11 = 0001 0001
 * 0xFF = 1111 1111
 * 
 * Binary
 * 0b01010101 = 0101 0101
 * 0b11011011 = 1101 1011
 */

byte LED1s = 0b01010101;
byte LED2s = 0b10101010;

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED1s);
  digitalWrite(latchPin, HIGH);
  delay(250);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED2s);
  digitalWrite(latchPin, HIGH);
  delay(250);
}
