#include <Servo.h>
#include "SR04.h"
Servo servo;
#define trigPin=3;
#define echoPin = 2;
int servoPin = 9;
SR04 sr04 = SR04 8ECHO_PIN,TRIG_PIN;
long a;

void setup () {
   servo.attach(servoPin);
   servo.write(0);
   delay(1000);
   servo.detach();
}

void loop (){
   a=sr04.Distance();
   if(a<20){
   servo.attach(servoPin);
   delay(10);
   servo.write(150);
   delay(1000);
   servo.write(0);
   delay(1000);
   servo.detach();
}

