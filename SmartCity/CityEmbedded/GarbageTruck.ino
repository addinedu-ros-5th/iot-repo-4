#include <SoftwareSerial.h>

const int L_MOTOR_CW = 5;
const int L_MOTOR_CCW = 6;
const int R_MOTOR_CW = 9;
const int R_MOTOR_CCW = 10;

const int L_LINESENS = 12;
const int R_LINESENS = 13;

const int RX = 3;
const int TX = 2;

int speed = 150;

SoftwareSerial Bluetooth(RX, TX);

void move(int leftCw, int leftCcw, int rightCw, int rightCcw)
{
  analogWrite(L_MOTOR_CW, leftCw);
  analogWrite(L_MOTOR_CCW, leftCcw);
  analogWrite(R_MOTOR_CW, rightCw);
  analogWrite(R_MOTOR_CCW, rightCcw);
}

void setup() 
{
  Serial.begin(9600);
  Bluetooth.begin(9600);
  pinMode(L_MOTOR_CW, OUTPUT);
  pinMode(L_MOTOR_CCW, OUTPUT);
  pinMode(R_MOTOR_CW, OUTPUT);
  pinMode(R_MOTOR_CCW, OUTPUT);
}

void loop() 
{
  int leftSensor = digitalRead(L_LINESENS);
  int rightSensor = digitalRead(R_LINESENS);

  if (Bluetooth.available()) { Serial.write(Bluetooth.read()); }
  if (Serial.available()) {Bluetooth.write(Serial.read()); }

  if (leftSensor == LOW && rightSensor == LOW)
  {
    move(speed, 0, speed, 0);
  }
  else if (leftSensor == HIGH && rightSensor == LOW)
  {
    move(0, speed, speed, 0);
  }
  else if (leftSensor == LOW && rightSensor == HIGH)
  {
    move(speed, 0, 0, speed);
  }
  else // leftSensor == HIGH && rightSensor == HIGH
  {
    move(0, 0, 0, 0);
  }
}