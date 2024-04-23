int speakerPin = 13;
int numTones = 13;

void setup() {
  tone(speakerPin, 261); delay(800);
  tone(speakerPin, 329); delay(300);
  tone(speakerPin, 391); delay(800);
  tone(speakerPin, 440); delay(250);
  tone(speakerPin, 391); delay(300);
  tone(speakerPin, 349); delay(300);
  tone(speakerPin, 440); delay(300);
  tone(speakerPin, 391); delay(800);
  tone(speakerPin, 349); delay(800);
  tone(speakerPin, 391); delay(300);
  tone(speakerPin, 329); delay(800);
  tone(speakerPin, 261); delay(300);
  tone(speakerPin, 294); delay(500);
  tone(speakerPin, 329); delay(500);
  tone(speakerPin, 261); delay(300);
}

void loop() {
  noTone(speakerPin); // Turn off the speaker
  while (1); // Stop the loop from running indefinitely
}
