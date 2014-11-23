int leftMotorForward = 13;
int leftMotorBackward = 12;
int rightMotorForward;
int rightMotorBackward;
int LEDpin;
int switchPin;
int ultraPin1;
int ultraPin2;

void setup() {
  pinMode (leftMotorForward, OUTPUT);
  pinMode (leftMotorBackward, OUTPUT);
  pinMode (rightMotorForward, OUTPUT);
  pinMode (rightMotorBackward, OUTPUT);
  pinMode (LEDpin, OUTPUT);
  pinMode (switchPin, OUTPUT);
  pinMode (ultraPin1, OUTPUT);
  pinMode (ultraPin2, OUTPUT);
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  if (analogRead(ultraPin1) <  500){
    if (analogRead(ultraPin2) <  100) {
      // chomp();
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


