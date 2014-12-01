#include <Servo.h>

int leftMotorForward = 13;
int leftMotorBackward = 12;
int rightMotorForward = 11;
int rightMotorBackward;
int servoPin;
int switchPin;
int ultraPin1;
int ultraPin2;



void setup() {
  pinMode (leftMotorForward, OUTPUT);
  pinMode (leftMotorBackward, OUTPUT);
  pinMode (rightMotorForward, OUTPUT);
  pinMode (rightMotorBackward, OUTPUT);
  pinMode (servoPin, OUTPUT);
  pinMode (switchPin, OUTPUT);
  pinMode (ultraPin1, OUTPUT);
  pinMode (ultraPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long time = millis();
  unsigned long lastChomp;
  if (ping(ultraPin1) <  5){
    if (ping(ultraPin2) <  10) {
      lastChomp = chomp(time, lastChomp);
    }
  } else {
    moveFunc();
  }
}
 
void moveFunc() {
  forward();
}

void forward() {
  digitalWrite(leftMotorForward,HIGH);
  digitalWrite(leftMotorBackward,LOW);
  digitalWrite(rightMotorForward,HIGH);
  digitalWrite(rightMotorBackward,LOW);
}

unsigned long ping(int ultraPin){
   unsigned long echo = 0;
   unsigned long ultrasoundValue = 0;
   pinMode(ultraPin, OUTPUT); // Switch signalpin to output
   digitalWrite(ultraPin, LOW); // Send low pulse
   delayMicroseconds(2); // Wait for 2 microseconds
   digitalWrite(ultraPin, HIGH); // Send high pulse
   delayMicroseconds(5); // Wait for 5 microseconds
   digitalWrite(ultraPin, LOW); // Holdoff
   pinMode(ultraPin, INPUT); // Switch signalpin to input
   digitalWrite(ultraPin, HIGH); // Turn on pullup resistor
  // please note that pulseIn has a 1sec timeout, which may
  // not be desirable. Depending on your sensor specs, you
  // can likely bound the time like this -- marcmerlin
  // echo = pulseIn(ultraPin, HIGH, 38000)
  echo = pulseIn(ultraPin, HIGH); //Listen for echo
  ultrasoundValue = (echo / 58.138);
  Serial.println(ultrasoundValue);
  return ultrasoundValue;
}

unsigned long chomp(unsigned long currentTime,unsigned long previousTime){
  Servo servo;
  unsigned long timeDif = currentTime - previousTime;
  unsigned long up = 200;
  unsigned long down = 200;
  
  if(timeDif > up) {
    if(timeDif > (up + down)) {
      servo.write(0);
      return currentTime;
    } else {
      servo.write(180);
      return currentTime;
    }
  } 
}

