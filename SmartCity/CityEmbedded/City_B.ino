#include <Servo.h>

const int trigPin1 = 2; // Trigger pin for ultrasonic sensor 1
const int echoPin1 = 3; // Echo pin for ultrasonic sensor 1
const int trigPin2 = 4; // Trigger pin for ultrasonic sensor 2
const int echoPin2 = 5; // Echo pin for ultrasonic sensor 2
const int SERVO_PIN = 10; // Servo motor pin
const int R_LED = 11; // Red LED pin
const int G_LED = 12; // Green LED pin
const int B_LED = 13; // Blue LED pin

const float sensorDistance = 10.0; // Distance between ultrasonic sensors in cm

Servo servo;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(R_LED, OUTPUT); // Set pin mode to output
  pinMode(G_LED, OUTPUT); // Set pin mode to output
  pinMode(B_LED, OUTPUT); // Set pin mode to output
  
  servo.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  unsigned long startMillis1, startMillis2;
  float timeTaken;
  
  if (Serial.available() > 0) {
    String inputString = Serial.readStringUntil('\n'); // Read string until newline
    inputString.trim(); // Remove whitespace from beginning and end

    if (inputString.endsWith("d")) { // Check if string ends with "d"
      int pos = inputString.toInt(); // Convert string to integer
      if (pos >= 0 && pos <= 180) {
        servo.write(pos); // Rotate the servo motor to the specified angle
        Serial.print("Servo moved to ");
        Serial.print(pos);
        Serial.println(" degrees.");
      } else {
        Serial.println("Invalid degree input. Enter a value between 0 and 180.");
      }
    }
    else {
      // Existing RGB LED control code
      if (inputString == "0") {
        digitalWrite(R_LED, HIGH);
        digitalWrite(G_LED, LOW);
        digitalWrite(B_LED, HIGH);
        Serial.println("The trash can is empty.");
      }
      else if (inputString == "1") {
        digitalWrite(R_LED, LOW);
        digitalWrite(G_LED, LOW);
        digitalWrite(B_LED, HIGH);
        Serial.println("There is trash.");
      }
      else if (inputString == "2") {
        digitalWrite(R_LED, LOW);
        digitalWrite(G_LED, HIGH);
        digitalWrite(B_LED, HIGH);
        Serial.println("The trash can is full.");
      }
      else {
        Serial.println("Not a command !!");
      }
    }
  }
}
