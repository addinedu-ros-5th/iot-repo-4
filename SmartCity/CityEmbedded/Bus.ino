const int LEFT_MOTOR_PIN1 = 5;
const int LEFT_MOTOR_PIN2 = 6;
const int RIGHT_MOTOR_PIN1 = 9;  
const int RIGHT_MOTOR_PIN2 = 10;

const int LINESENS_R = 3;
const int LINESENS_L = 2;

bool busStatus = false;

void move(int L_MOTOR1, int L_MOTOR2, int R_MOTOR1, int R_MOTOR2) 
{
  analogWrite(LEFT_MOTOR_PIN1, L_MOTOR1);
  analogWrite(LEFT_MOTOR_PIN2, L_MOTOR2);
  analogWrite(RIGHT_MOTOR_PIN1, R_MOTOR1);
  analogWrite(RIGHT_MOTOR_PIN2, R_MOTOR2);
}

void setup() 
{
  pinMode(LEFT_MOTOR_PIN1, OUTPUT);
  pinMode(LEFT_MOTOR_PIN2, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN2, OUTPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  int leftSensor = digitalRead(LINESENS_L);
  int rightSensor = digitalRead(LINESENS_R);

  if(!busStatus)
  {
    if (leftSensor == LOW && rightSensor == LOW) 
    {
      move(150, 0, 150, 0);  // 전진
    } else if (leftSensor == HIGH && rightSensor == LOW) 
    {
      move(150, 0, 0, 150);  // 우회전
    } else if (leftSensor == LOW && rightSensor == HIGH) 
    {
      move(0, 150, 0, 150);  // 좌회전
    } else 
    {
      move(0,0,0,0);
    }
  }
  if(Serial.available())
  {
    char data = (char)Serial.read();
    if(data == '0')
    {
      busStatus = true;
      move(0,0,0,0);
    }
    if(data == '1')
    {
      busStatus = false;
    }
  } 
}