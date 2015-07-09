
// Project 5 LED Chases Effect

byte ledpin[]={4,5,6,7,8,9,10,11,12,13}; //Create array for LED pins
int leddelay;
int direction=1; // Direction of LED's starting from the LEFT side
int currentled=0; // For LEFT half of LED's
unsigned long changetime;
int potpin=2;


void setup() {
  for (int x=0; x<10; x++){
    pinMode(ledpin[x],OUTPUT);
  }  
  changetime=millis();  
}

void loop() {
  leddelay=analogRead(potpin);
  if(millis()-changetime >leddelay){
    changeled();
    changetime=millis();
  }
}

void changeled(){
  for(int x=0; x<10; x++){    //Tunr off all the LED's
    digitalWrite(ledpin[x], LOW);
  }
  digitalWrite(ledpin[currentled], HIGH);   //Turn on the current LED
  currentled += direction;          // increment by the direction value
  
  //change direction if we reach the end
  if(currentled == 9){direction = -1;}
  if(currentled == 0) {direction =1;}
}
  
  
