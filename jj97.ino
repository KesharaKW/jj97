#include <Servo.h>

Servo Servo1;

#define trig 2
#define echo 4

void setup() {

  //Servo
  Servo1.attach(3);

  //Ultra-Sonic
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);

  //Motor control pins
  pinMode(8, OUTPUT); //LEFT BACKWARDS
  pinMode(9, OUTPUT); //RIGHT FORWARD
  pinMode(10, OUTPUT); //RIGHT FORWARD
  pinMode(11, OUTPUT); //LEFT BACKWARDS

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
  long x = cm ;
  stopm();

  //Drivetrain
  if (x > 20) {
    forwardm();
  }
  else {
    stopm();
    delay(1000);
    backwardm();
    delay(500);
    stopm();

    Servo1.write(30);

    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    long t = pulseIn(echo, HIGH);
    long inches = t / 74 / 2;
    long cm = t / 29 / 2;
    Serial.print(inches);
    Serial.print("in2 \t");
    Serial.print(cm);
    Serial.println("cm2 \t");
    delay(100);

    int x1 = cm;
    if (x1 > 20) {
      turnRF();
      /*digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);*/
      delay(1000);
      forwardm();
      
    }
    else {
      stopm();
    }
  }




}
void stopm() {
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);

}
void forwardm() {
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);

}
void backwardm() {
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}
void turnRF() {
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}
void turnLF() {
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}
