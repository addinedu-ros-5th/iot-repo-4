#include <Stepper.h>
#include <SoftwareSerial.h>

int Tx = 7;
int Rx = 6;
SoftwareSerial BTSerial(Tx,Rx);

const int TRIG = 3; // 초음파 센서 TRIG 핀
const int ECHO = 2; // 초음파 센서 ECHO 핀

const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 11, 9, 10, 8);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);

  pinMode(TRIG, OUTPUT); // TRIG 핀 출력 설정
  pinMode(ECHO, INPUT); // ECHO 핀 출력 설정
  myStepper.setSpeed(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available())
  {
   Serial.write(BTSerial.read());
  }
  if (Serial.available())
  {
    BTSerial.write(Serial.read());
  }

  long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH); // 초음파를 받는 시간 (LOW 에서 HIGH 로)
  distance = duration * 0.034 / 2; // cm 로 환산

  Serial.println(duration);
  Serial.print("\nDIstance : ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);

  if (distance <= 7)
  {
    myStepper.step(-2 * stepsPerRevolution); // 정방향으로 1회전
    delay(3000); // 3초 대기
    myStepper.step(2 * stepsPerRevolution); // 역방향으로 1회전
  }
}
