# Table-bot-challenge-
//this code will make a robot do all of the table bot challenges// 
//More programs will be added to this//
#define PWMA 3
#define PWMB 11

#define DIRA 12
#define DIRB 13

#define BRKA 9
#define BRKB 8

int echoPin = 10;
int trigPin = 7;
int echoPin2 = 6;
int trigPin2 = 4; 
int echoPin3 = 5;
int trigPin3 = 2;


int getDistance(){
  
  long duration;
  int distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = ((duration/2) / 29.1);
  return(distance);
}

int getDistance2(){
  
  long duration2;
  int distance2;
  digitalWrite(trigPin2,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);
  duration2 = pulseIn(echoPin2,HIGH);
  distance2 = ((duration2/2) / 29.1);
  return(distance2);
}

int getDistance3(){
  
  long duration3;
  int distance3;
  digitalWrite(trigPin3,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3,LOW);
  duration3 = pulseIn(echoPin3,HIGH);
  distance3 = ((duration3/2) / 29.1);
  return(distance3);
}

void forward(int speed){
  digitalWrite(DIRA, LOW);  //Establishes forward direction of Channel A
  digitalWrite(BRKA, LOW);  //Disengage the Brake for Channel A
  analogWrite(PWMA,  255);   //Spins the motor on Channel A at full speed
  
  digitalWrite(DIRB, LOW);  //Establishes forward direction of Channel B
  digitalWrite(BRKB, LOW);  //Disengage the Brake for Channel B
  analogWrite(PWMB,  255);   //Spins the motor on Channel B at full speed
}

void backward(int speed){
  digitalWrite(DIRA, HIGH); //Establishes backward direction of Channel A
  digitalWrite(BRKA, LOW);  //Disengage the Brake for Channel A
  analogWrite(PWMA,  255);   //Spins the motor on Channel A at full speed

  digitalWrite(DIRB, HIGH); //Establishes backward direction of Channel B
  digitalWrite(BRKB, LOW);  //Disengage the Brake for Channel B
  analogWrite(PWMB,  255);   //Spins the motor on Channel B at full speed
}

void right(int speed){
  digitalWrite(DIRA, HIGH); //Establishes backward direction of Channel A
  digitalWrite(BRKA, LOW);  //Disengage the Brake for Channel A
  analogWrite(PWMA,  255);   //Spins the motor on Channel A at full speed

  digitalWrite(DIRB, LOW); //Establishes backward direction of Channel B
  digitalWrite(BRKB, LOW);  //Disengage the Brake for Channel B
  analogWrite(PWMB,  255);   //Spins the motor on Channel B at full speed
}

void left(int speed){
  digitalWrite(DIRA, LOW); //Establishes backward direction of Channel A
  digitalWrite(BRKA, LOW);  //Disengage the Brake for Channel A
  analogWrite(PWMA,  255);   //Spins the motor on Channel A at full speed

  digitalWrite(DIRB, HIGH); //Establishes backward direction of Channel B
  digitalWrite(BRKB, LOW);  //Disengage the Brake for Channel B
  analogWrite(PWMB,  255);   //Spins the motor on Channel B at full speed
}

void setup() {

//Setup Channel A
pinMode(DIRA, OUTPUT); //Initiates Motor Channel A pin
pinMode(BRKA, OUTPUT); //Initiates Brake Channel A pin

//Setup Channel B
pinMode(DIRB, OUTPUT); //Initiates Motor Channel B pin
pinMode(BRKB, OUTPUT);  //Initiates Brake Channel B pin

pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(115200);
pinMode(trigPin2,OUTPUT);
pinMode(echoPin2,INPUT);
Serial.begin(115200);
}


void loop(){

if((getDistance2())||(getDistance3()) > 15){
  backward(225);
  delay(2000);
  right(225);
  delay(2000);
  forward(225);
}

if(getDistance() < 15){
  right(225);
  delay(2000);
  forward(225);
}

}
 
