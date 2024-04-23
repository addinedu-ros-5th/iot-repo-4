#include <Servo.h> 

// Pin definitions
const int trigPin1 = 2; // Trigger pin of ultrasonic sensor 1
const int echoPin1 = 3; // Echo pin of ultrasonic sensor 1
const int trigPin2 = 4; // Trigger pin of ultrasonic sensor 2
const int echoPin2 = 5; // Echo pin of ultrasonic sensor 2
const int SERVO_PIN = 10; // Servo motor pin
const int R_LED = 11; // Red LED pin
const int G_LED = 12; // Green LED pin
const int B_LED = 13; // Blue LED pin

const float sensorDistance = 10.0; // Distance between ultrasonic sensors in cm
Servo servo; // Servo object

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(R_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(B_LED, OUTPUT);
  
  servo.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String inputString = Serial.readStringUntil('\n'); // Read the input until newline
    inputString.trim(); // Remove any whitespace

    if (inputString.endsWith("d")) { // Check if the string ends with 'd'
      int pos = inputString.toInt(); // Extract the number from the string
      if (pos >= 0 && pos <= 180) {
        servo.write(pos); // Move servo to the specified angle
        Serial.print("Servo moved to ");
        Serial.print(pos);
        Serial.println(" degrees.");
      } else {
        Serial.println("Invalid degree input. Enter a value between 0 and 180.");
      }
    } else {
      controlLED(inputString);
    }
  }

  measureSpeed(); // Measure speed
}

void controlLED(String command) {
  if (command == "0") {
    digitalWrite(R_LED, HIGH);
    digitalWrite(G_LED, LOW);
    digitalWrite(B_LED, HIGH);
    Serial.println("The trash can is empty.");
  } else if (command == "1") {
    digitalWrite(R_LED, LOW);
    digitalWrite(G_LED, LOW);
    digitalWrite(B_LED, HIGH);
    Serial.println("There is trash.");
  } else if (command == "2") {
    digitalWrite(R_LED, LOW);
    digitalWrite(G_LED, HIGH);
    digitalWrite(B_LED, HIGH);
    Serial.println("The trash can is full.");
  } else {
    Serial.println("Not a command !!");
  }
}

void measureSpeed() {
  float distance1 = get_distance(trigPin1, echoPin1);
  float distance2 = get_distance(trigPin2, echoPin2);

  if (distance1 < 5 && distance2 < 5) { // Both sensors detect an object
    unsigned long startMillis = millis();
    while (get_distance(trigPin2, echoPin2) < 5) {} // Wait until the object passes
    float timeTaken = (millis() - startMillis) / 1000.0; // Time measurement

    float velocity = sensorDistance / timeTaken; // Calculate velocity
    Serial.print("Velocity: ");
    Serial.print(velocity, 2);
    Serial.println(" m/s");
  }
}

float get_distance(int trigPin, int echoPin) {
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  float distance = duration * 17 / 1000; // Calculate the distance
  return distance;
}