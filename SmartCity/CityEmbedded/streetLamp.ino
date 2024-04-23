//shift register
byte LED_patterns[] = {
  B11111111,
  B00000000
};
int latch = 8;
int clock = 9;
int data = 10;

void updateShiftRegister(byte pattern) {
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, pattern);
  digitalWrite(latch, HIGH);
}

//button
const int lampSwitch = 11;

//button toggle
bool current = LOW;
bool last = LOW;
bool On = false;

//button state
void handleButtonPress(int buttonIndex, bool &buttonState, bool &lastButtonState) {
  bool currentButtonState = digitalRead(buttonIndex);
  
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    buttonState = !buttonState;
    // Update shift register pattern
    if (buttonState) {
      updateShiftRegister(LED_patterns[0]); // Turn on all LEDs
    } else {
      updateShiftRegister(LED_patterns[1]); // Turn off all LEDs
    }
  }
  lastButtonState = currentButtonState;
}

//initialization
void setup() {
  Serial.begin(9600);
  pinMode(lampSwitch, INPUT);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
  updateShiftRegister(LED_patterns[1]); // Initially turn off all LEDs
}

void loop() {
  handleButtonPress(lampSwitch, current, last);
}