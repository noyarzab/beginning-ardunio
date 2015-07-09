//Stop light with pedestrian light

int carred = 12; //Traffic lights pin number
int caryellow=11;
int cargreen =10;

int pedred = 9; //Pedestrian walk pin number
int pedgreen=8;

int button = 3; //Push for walk pin

int crosstime= 5000; //Time for pedestrians to walk
unsigned long changetime=0; // Time last pedestrian cycle completed;

boolean pushed = 0;

void setup() {
  // put your setup code here, to run once:
  
pinMode(carred, OUTPUT);
pinMode(caryellow, OUTPUT);
pinMode(cargreen, OUTPUT);

pinMode(pedred, OUTPUT);
pinMode(pedgreen, OUTPUT);

pinMode(button, OUTPUT);

//Turn on stop lights

digitalWrite(cargreen, HIGH);
digitalWrite(pedred, HIGH);

}

void loop() {
  
  int state =digitalRead(button);
  if(state==HIGH){
    pushed=1;
  }
    
  
  //Check if the button is pressed and 5s have passed since the last ped cycle
  
  if(pushed==1 && (millis()-changetime)>5000) {
    changelights(); // Call changelights function
  }
}
  
void changelights(){
    
    digitalWrite(caryellow, HIGH);
    digitalWrite(cargreen, LOW);
    delay(1000);
    
     //Cars stop
    digitalWrite(caryellow, LOW);    
    digitalWrite(carred, HIGH);
    delay(1000);
    
    digitalWrite(pedred, LOW); //Peds go
    digitalWrite(pedgreen, HIGH);
    delay(crosstime);
    
    digitalWrite(pedgreen, LOW);
    
    for(int x=0; x<10; x++){
      digitalWrite(pedred, HIGH);
      delay(250);
      digitalWrite(pedred,LOW);
      delay(250);
    }
    
    digitalWrite(pedred, HIGH);
    delay(500);    
    digitalWrite(caryellow, HIGH);
    delay (500);
    digitalWrite(carred, LOW);
    digitalWrite(caryellow, LOW);
    digitalWrite(cargreen, HIGH);
    changetime = millis();
    pushed=0;
  }
  

