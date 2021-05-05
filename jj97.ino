#include <Servo.h>

Servo Servo1;

#define trig 2
#define echo 4

void setup() {
  
  //Servo
  Servo1.attach(1);

  //Ultra-Sonic
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);

  //Motor control pins
  pinMode(8,OUTPUT); //LEFT BACKWARDS
  pinMode(9,OUTPUT); //RIGHT FORWARD
  pinMode(10,OUTPUT); //RIGHT FORWARD
  pinMode(11,OUTPUT); //LEFT BACKWARDS
}

void loop() {
  
  //Ultra-Sonis
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long inches = t / 74 / 2;
  long cm = t / 29 / 2;
  Serial.print(inches);
  Serial.print("in \t");
  Serial.print(cm);
  Serial.println("cm \t");
  delay(100);

  //Initializing
  Servo1.write(90);
  long x = cm;
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);

  //Drivetrain
  if (x>20) {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
  }
  else {
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);

      
  }
  



}
