#include <Servo.h>
Servo first;
int trigPin = 9;
int echoPin = 8;
int distance;
void setup() {
Serial.begin(9600);
first.attach(5);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
distance = (pulseIn(echoPin,HIGH) / 58.2) ;
Serial.println(distance);
}
