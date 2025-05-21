#include <Encoder.h>  
// attach to correct pin outs when Ultrasonic sensor is added onto frame
#define echoPin 9
#define trigPin 8

int state = 0;

int encoderA = 0;
int encoderB = 0;

int motorA = 5;
int motorB = 6;
int motorE = 0;
//variables for motor2
int encoder2A = 0;
int encoder2B = 0;
int motor2A = 10;
int motor2B = 11;
int motor2E = 0;
//variable for back motors
int motorNA = 3;
int motorNB = 2;
int motorNE = 0;
int motor2NA = 13;
int motor2NB = 12;
int motor2NE = 0;

int ultrasonicFront;

//variable for threshold distance of ultrasonic sensor readings
int setDist = 43;
int usDuration;
int usSpeed;
int usDistance;

// tilt counter variables
int tiltCounter;
int firstTilt;
int secondTilt;
unsigned long second = 0;
unsigned long timer = 0;

int tiltPin = 2;

Encoder wheelSet1(encoderA, encoderB);
Encoder wheelSet2(encoder2A, encoder2B);

void setup() {
  //set the pin modes of the motor pins and encoder pins
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(motorE, OUTPUT);
  pinMode(encoderA, INPUT);
  pinMode(encoderB, INPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor2E, OUTPUT);
  pinMode(encoder2A, INPUT);
  pinMode(encoder2B, INPUT);
  pinMode(motorNA, OUTPUT);
  pinMode(motorNB, OUTPUT);
  pinMode(motor2NA, OUTPUT);
  pinMode(motor2NB, OUTPUT);
  firstTilt = digitalRead(tiltPin);
  Serial.begin(9600);
}
void motorDriving(int speed, int motorA, int motorB, int motorE){
 //ensure speed is within bounds
  if (speed < -255){
    speed = -255;
  }
  if (speed > 255){
    speed = 255;
  }
  
  //sets motors to spin forward, backwards or not at all
  if(speed > 0){
    digitalWrite(motorA, HIGH);
    digitalWrite(motorB, LOW);
  }
   if(speed < 0){
    digitalWrite(motorA, LOW);
    digitalWrite(motorB, HIGH);
  }
   if(speed == 0){
    digitalWrite(motorA, LOW);
    digitalWrite(motorB, LOW);
  }
  
}
void movingUpward() {  
  motorDriving(-255, motorA, motorB, motorE);
  motorDriving(100, motor2A, motor2B, motor2E);
  digitalWrite( motorNA, HIGH);
  digitalWrite( motorNB, LOW);
  digitalWrite( motor2NA, HIGH);
  digitalWrite( motor2NB, LOW);
  
}
void motorStop() {  //stops all the motors
  motorDriving(0, motorA, motorB, motorE);
  motorDriving(0, motor2A, motor2B, motor2E);
  digitalWrite(motorNA, LOW);
  digitalWrite(motorNB, LOW);
  digitalWrite(motor2NA, LOW);
  digitalWrite(motor2NB, LOW);
}
void turnRight90() {  //moves backwards while turning right when below threshold distance

  motorDriving(160, motorA, motorB, motorE);
  motorDriving(90, motor2A, motor2B, motor2E);
  digitalWrite(motorNA, LOW);
  digitalWrite(motorNB, HIGH);
  digitalWrite(motor2NA, LOW);
  digitalWrite(motor2NB, HIGH);
  // change to time it takes to turn 90 degrees
  delay(3000);
}
void ultrasonicTest() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  usDuration = pulseIn(echoPin, HIGH);  //time
  usSpeed = 0.034;
  usDistance = usSpeed * usDuration / 2;  //distance = speed x time / 2
  Serial.println(usDistance);
}

void loop() {
  // going up stairs
  if (state == 0) {
    Serial.println("Climbing stairs!");
    movingUpward();
    //Checks to see if the current state of the tilt counter is the same as the inital state, it does this every 500 miliseconds for 2.5 seconds
    if (millis() - timer > 2500) {
      timer = millis();
    } else if (millis() - second > 500) {
      second = millis();
      if (secondTilt != firstTilt) {
        secondTilt = digitalRead(tiltPin);
        tiltCounter += 1;
      } else {
        tiltCounter = 0;
      }
    }
    if (tiltCounter >= 1) {
      state += 1;
    }
  }
  // if flat surface detected
  if (state == 1) {

    Serial.println("Robot flat! Searching for wall..");
    Serial.print("closest wall ");
    Serial.print(usDistance);
    Serial.println(" cm away!");
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    usDuration = pulseIn(echoPin, HIGH);  //time
    usSpeed = 0.034;
    usDistance = usSpeed * usDuration / 2;  //distance = speed x time / 2
    Serial.print("closest wall ");
    Serial.print(usDistance);
    Serial.println(" cm away!");
    // 43cms away from wall, turn
    if (analogRead(usDistance) < setDist) {
      Serial.println("wall detected! Turning right");
      motorStop();
      turnRight90();
    }
  }
}
