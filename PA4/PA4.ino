#include <Wire.h>
#define uchar unsigned char
#define M_PI 3.14159265358979323846

// initialize line sensor
uchar t;
int linevalue = 243;
uchar data[16];

// initialize first motor
int pinOut1 = 3;
int pinForward1 = 9;
int pinBackward1 = 8;

// initialize second motor
int pinOut2 = 6;
int pinForward2 = 4;
int pinBackward2 = 5;

void setup() {
  // set up motors
  pinMode(pinOut1, OUTPUT);
  pinMode(pinForward1, OUTPUT);
  pinMode(pinBackward1, OUTPUT);
  pinMode(pinOut2, OUTPUT);
  pinMode(pinForward2, OUTPUT);
  pinMode(pinBackward2, OUTPUT);

  // set up line sensor
  Wire.begin();
  t = 0;
  Serial.begin(9600);  // start serial for output
}


void loop() { 
  Serial.println("hello");
}

/*
void handleFreeState() {
  runLineSensor();
  for (int i=0; i<16; i+){
    if (data[i] <= linevalue) state = TRIGGERED;
  }
}


void handleTriggeredState() {
  // check for QTR sensors being centered
  if (data[6] <= linevalue || data[8] <= linevalue)
    state = CENTERED;
  else {
    
    // check left QTR sensors
    int i = 0;
    while (i < 6) {
      if (data[i] <= linevalue) {
        state = SHIFTLEFT;
        break;
      }
    }
  
    // check right QTR sensors
    i = 14
    while (i > 8) {
      if (data[i] <= linevalue) {
        state = SHIFTRIGHT;
      }
    }
}


void runLineSensor() {
  Wire.requestFrom(9, 16);
  
  while (Wire.available()) {
    data[t] = Wire.read();
    if (t < 15) t++;
    else t = 0;
  }
  Serial.println("FUCK");
}
*/


void moveForward() {
  digitalWrite(pinForward1, HIGH);
  digitalWrite(pinBackward1, LOW);
  digitalWrite(pinForward2, HIGH);
  digitalWrite(pinBackward2, LOW);
}

void turnRight() {
  digitalWrite(pinForward1, HIGH);
  digitalWrite(pinBackward1, LOW);
  digitalWrite(pinForward2, LOW);
  digitalWrite(pinBackward2, HIGH);
}

void turnLeft() {
  digitalWrite(pinForward1, LOW);
  digitalWrite(pinBackward1, HIGH);
  digitalWrite(pinForward2, HIGH);
  digitalWrite(pinBackward2, LOW);
}

void stopMotors() {
  digitalWrite(pinForward1, LOW);
  digitalWrite(pinBackward1, LOW);
  digitalWrite(pinForward2, LOW);
  digitalWrite(pinBackward2, LOW);
}
