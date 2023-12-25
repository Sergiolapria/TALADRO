//PRACTICA DEL TALADRO
#include <Arduino.h>
const int dirPin=6;
const int stepPin=3;
const int FCC_1=9; //BAJAR
const int FCC_2=10; //SUBIR
const int FCC_3=11; //HOME
const int FCC_4=12; 
const int Relay=13;
const int stepper_EN=8;
const int steps=200;
bool HOME=true;
bool SUBIR=true;
bool BAJAR=true;

int stepDelay;
void setup() {
 Serial.begin(9600);
 //Marcar pines como salida
 pinMode(dirPin,OUTPUT);
 pinMode(stepPin,OUTPUT);
 pinMode(stepper_EN,OUTPUT);
 pinMode(Relay,OUTPUT);

 //Marcar pines como entrada
 pinMode(FCC_1,INPUT);
 pinMode(FCC_2,INPUT);
 pinMode(FCC_3,INPUT);
 pinMode(FCC_4,INPUT);
}
void turn(int speed){
  for(int x=0;x<steps*1;x++){
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(speed);
    digitalWrite(stepPin,LOW);
  }
}
void loop() {
 HOME=digitalRead(FCC_3);
 BAJAR=digitalRead(FCC_1);
 SUBIR=digitalRead(FCC_2);
 while(HOME==0 && BAJAR==1 && SUBIR==1){
  //Va casa
  digitalWrite(dirPin,HIGH);
  turn(150);
  digitalWrite(Relay,LOW);
 }
 while(HOME==1 && BAJAR==0 && SUBIR==1){
  digitalWrite(dirPin,LOW);
  turn(250);
  digitalWrite(Relay,HIGH);
 }
 while(HOME==1 && BAJAR==1 && SUBIR==0){
  digitalWrite(dirPin,HIGH);
  turn(150);
  digitalWrite(Relay,HIGH);
 }
}
