#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set LCD address and size

const int trigPin1 = 2; // Trigger pin for ultrasonic sensor 1
const int echoPin1 = 3; // Echo pin for ultrasonic sensor 1
const int trigPin2 = 4; // Trigger pin for ultrasonic sensor 2
const int echoPin2 = 5; // Echo pin for ultrasonic sensor 2
const float sensorDistance = 10.0; // Distance between ultrasonic sensors in cm

void setup() 
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() 
{
  unsigned long startMillis1, startMillis2;
  float timeTaken;

  // Measure time taken for object detection by ultrasonic sensor 1
  startMillis1 = millis();
  while (get_distance(trigPin1, echoPin1) >= 5) {
    // Wait until object is detected
  }

  // Measure time taken for object detection by ultrasonic sensor 2
  startMillis2 = millis();
  while (get_distance(trigPin2, echoPin2) >= 5) {
    // Wait until object is detected
  }

  // Calculate time taken until both sensors detect an object
  timeTaken = (millis() - startMillis1) / 1000.0; // Convert to seconds

  // Calculate velocity
  float velocity = sensorDistance / timeTaken;

  // Display velocity on LCD
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Velocity");
  lcd.setCursor(0, 1);
  lcd.print(velocity);
  lcd.print("m/s");
}

float get_distance(int trigPin, int echoPin)
{
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.017; // Calculate distance in cm
  return distance;
}