const int R_LED = 11; // Red LED pin
const int G_LED = 12; // Green LED pin
const int B_LED = 13; // Blue LED pin

void setup() {
  pinMode(R_LED, OUTPUT); // Set pin mode to output
  pinMode(G_LED, OUTPUT); // Set pin mode to output
  pinMode(B_LED, OUTPUT); // Set pin mode to output

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read(); // Read serial data

    // Ignore newline ('\n') and carriage return ('\r')
    if (input == '\n' || input == '\r') {
      return; // Move to the next loop iteration
    }

    Serial.print("Received command: ");
    Serial.println(input); // Print the read data

    switch (input) {
      case '0':
        digitalWrite(R_LED, LOW);
        digitalWrite(G_LED, HIGH);
        digitalWrite(B_LED, LOW);
        Serial.println("The trash can is empty.");
        break;
      case '1':
        digitalWrite(R_LED, HIGH);
        digitalWrite(G_LED, HIGH);
        digitalWrite(B_LED, LOW);
        Serial.println("There is trash.");
        break;
      case '2':
        digitalWrite(R_LED, HIGH);
        digitalWrite(G_LED, LOW);
        digitalWrite(B_LED, LOW);
        Serial.println("The trash can is full.");
        break;
      default:
        Serial.println("Not a command !!");
        break;
    }
  }
}
