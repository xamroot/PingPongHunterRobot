#import <Servo.h>

int servoPin = 10;
int trigPin = 11;
int echoPin = 12;
int duration = 0;
int distance = 0;
int ballInCacheDistance = 5;
Servo servoLeft;
Servo servoRight;

int pinOut1 = 6;
int pinForward1 = 8;
int pinBackward1 = 7;
int pinOut2 = 3;
int pinForward2 = 4;
int pinBackward2 = 5;
int Speed = 75;

void setup() {
  Serial.begin(9600);
  // set pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // set servos
  servoLeft.attach(9);
  servoRight.attach(0);
}

void loop() {
  analogWrite(pinOut1, Speed);
  analogWrite(pinOut2, Speed);
  flushInput();
  
  duration = pulseIn(echoPin, HIGH); // read input from echo
  
  distance = getDistance(duration); // convert time -> distance in cm
  Serial.println(distance);
  // handle distances
  if (distance <= ballInCacheDistance) {
    // there is a ball in cache
    Serial.println("Ball in cache");
    servoShoot();
  } else {
    Serial.println("Cache empty");
    digitalWrite(pinForward2, HIGH);
    digitalWrite(pinForward1, HIGH);
    servoCapture();
  } 
}

void servoStop () {
  servoLeft.write(0);
  servoRight.write(0);  
}

void servoShoot () {
  servoLeft.write(180);
  servoRight.write(180);
}

void servoCapture() {
  servoLeft.write(-180);
  servoRight.write(-180);
}


void flushInput() {
  // flush analog pulse measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);  

  // output trigPin for 10 ms
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
 
}

long getDistance(int dur) {
  int d = (dur / 2) / 29.1;  
  return d;
}
