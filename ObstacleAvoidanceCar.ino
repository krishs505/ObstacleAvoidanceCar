#include <Servo.h> 

// left motors
int in3 = 8;
int in4 = 7;
int enB = 6;
// right motors
int enA = 3;
int in1 = 4;
int in2 = 5;

const int trigPin = A0;
const int echoPin = A1;

int distance;
bool goingForward = false;
int speedSet = 0;

Servo servo1;

void setup() {
  Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo1.attach(9);
  servo1.write(90);

  delay(2000);
  distance = findDistance();
  Serial.println(distance);

}

void loop() {
  int distL = 0;
  int distR = 0;
  
  // obstacle detected!
  if (distance <= 18) {
    // stop and move backward a bit
    stopMotors();
    delay(100);
    backward();
    delay(300);
    stopMotors();
    delay(200);

    // turn ultrasonic sensor left and right, measuring distance both ways
    distL = lookLeft();
    delay(200);
    distR = lookRight();
    delay(200);

    // go toward side with more distance ahead
    if (distR >= distL) {
      right();
      delay(750);
      stopMotors();
    } else {
      left();
      delay(750);
      stopMotors();
    }
  } else {
    // there is >18 cm in front of it, keep going
    forward();
  }

  // constantly measure distance ahead
  distance = findDistance();
  
  delay(10);
}

void forward() {
  if (goingForward == false) {
    goingForward = true;
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    // slowly bring the speed up to avoid loading down the batteries too quickly
    for (speedSet = 0; speedSet < 255; speedSet += 5) {
      analogWrite(enA, speedSet);
      analogWrite(enB, speedSet);
      delay(3);
    }
  }
  
}
void backward() {
  goingForward = false;
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // slowly bring the speed up to avoid loading down the batteries too quickly
  for (speedSet = 0; speedSet < 255; speedSet += 5) {
    analogWrite(enA, speedSet);
    analogWrite(enB, speedSet);
    delay(3);
  }
}
void left() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void right() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
int findDistance() {
  long duration;

  // reset trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // send an ultrasound by setting trigPin to HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // read the travel time of the sound save
  duration = pulseIn(echoPin, HIGH);

  // calculate distance based on speed of sound (0.034 cm/microsec)
  int dist = duration * 0.034 / 2;
  if (dist == 0) dist = 250;
  return dist;
}
int lookLeft() {
  servo1.write(180);
  delay(100);
  int d = findDistance();
  delay(100);
  servo1.write(90);
  delay(100);
  return d;
}
int lookRight() {
  servo1.write(0);
  delay(100);
  int d = findDistance();
  delay(100);
  servo1.write(90);
  delay(100);
  return d;
}
void motorTest() {
  delay(5000);

  forward();
  delay(2000);
  stopMotors();
  delay(500);

  backward();
  delay(2000);
  stopMotors();
  delay(500);

  left();
  delay(2000);
  stopMotors();
  delay(500);

  right();
  delay(2000);
  stopMotors();
  delay(500);

}
