#include <Servo.h>

const int L_MOTOR_CW = 2;
const int L_MOTOR_CCW = 4;
const int R_MOTOR_CW = 7;
const int R_MOTOR_CCW = 8;

const int L_LINESENS = 12;
const int R_LINESENS = 13;

const int SERVO = 10;

int speed = 150;
char cmd;

Servo servo;

typedef enum
{
  WAIT,
  MOVING,
  THROW,
  STOP
} STATUS;

STATUS status;

void setMotorAngle(int angle, int status)
{
  servo.attach(SERVO);
  if (servo.attached())
  {
    if (status == 0)
    {
      servo.write(angle);
      delay(100);
      servo.detach();
    }
    else if (status == 1)
    {
      for (int i = angle; i >= 0; i--)
      {
        servo.write(i);
        delay(2);
      }
      for (int i = 0; i <= angle; i++)
      {
        servo.write(i);
        delay(2);
      }
      servo.detach();
    }
  }
}

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
  while (!Serial);

  setMotorAngle(100, 0);

  pinMode(L_MOTOR_CW, OUTPUT);
  pinMode(L_MOTOR_CCW, OUTPUT);
  pinMode(R_MOTOR_CW, OUTPUT);
  pinMode(R_MOTOR_CCW, OUTPUT);

  status = STATUS::WAIT;
}

void loop() 
{
  int leftSensor = digitalRead(L_LINESENS);
  int rightSensor = digitalRead(R_LINESENS);

  if(Serial.available())
  {
    char cmd = Serial.read();

    switch(cmd)
    {
      case '1':
        status = STATUS::MOVING;
        Serial.println("move to trash can");
        break;
      case '2':
        status = STATUS::STOP;
        Serial.println(status);
        break;
      case '3':
        status = STATUS::THROW;
        Serial.println(status);
        break;
      default:
        break;
    }
    cmd = "";
  }

  if (status == STATUS::MOVING)
  {
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
  }

  if (status == STATUS::STOP)
  {
    move(0, 0, 0, 0);
  }

  if (status == STATUS::THROW)
  {
    status = STATUS::WAIT;
    setMotorAngle(100, 1);
  }
}