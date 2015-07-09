// SOS morse code.

const int ledpin = 2; //Define LED pin number
int dits=150;
int dahs=400;
int sil=100;
int let=200;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT); // Set ledpin to output mode
  

}

void loop() {
  for (int x=7; x<10; x++){
    digitalWrite(ledpin,HIGH);
    delay(dits);
    digitalWrite(ledpin,LOW);
    delay(sil);
  }
  delay(let);
  for (int x=1;x<4; x++){
    digitalWrite(ledpin,HIGH);
    delay(dahs);
    digitalWrite(ledpin,LOW);
    delay(sil);
  }
  delay(let);
  for (int x=-3; x<0; x++){
    digitalWrite(ledpin,HIGH);
    delay(dits);
    digitalWrite(ledpin,LOW);
    delay(sil);
  }
  delay(5000);
}
