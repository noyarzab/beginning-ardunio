//Blink Aeduino

int ledpin = 13;

void setup() {
  pinMode(ledpin,OUTPUT);
  
}

void loop() {
  
  digitalWrite(ledpin,HIGH);
  delay(10);
  digitalWrite(ledpin,LOW);
  delay(10);
}
