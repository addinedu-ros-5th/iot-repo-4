#include <DS1302.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initialize the LCD
DS1302 rtc(2, 4, 5);  // Initialize the RTC (Real Time Clock)

int lastSecond = -1;
int lastMinute = -1;
int lastHour = -1;
int lastDate = -1;
int lastMonth = -1;
int lastYear = -1;
int speakerPin = 7;
int numTones = 7;

// Shift register pins
int latch = 8;
int clock = 9;
int data = 10;

void setup() {
  Serial.begin(9600);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
  lcd.init();
  lcd.backlight();
  rtc.writeProtect(false);
  rtc.halt(false);
  Time datetime(2024, 4, 22, 19, 59, 57, 1);  // Set initial date and time
  rtc.time(datetime);
  lcd.clear();
}

void loop() {
  Time t = rtc.time();
  updateDateTime(t);
  if (t.sec == 0 && lastMinute != t.min) {  // Check if it's the top of the hour
    schoolBell();  // Ring the bell at the start of each hour
  }

  if (Serial.available() > 0) {
    char receivedChar = Serial.read();  // Read from serial input
    if (receivedChar == 's') {
      schoolBell();  // Ring the bell when 's' is entered
    }
  }

  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, B11111111);
  digitalWrite(latch, HIGH);
  delay(200);  // Delay to refresh time display
}

void schoolBell() {
  Serial.println("schoolBell started");  // Notify that the function has started
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
  noTone(speakerPin);
  Serial.println("schoolBell ended");  // Notify that the function has ended
}

void updateDateTime(const Time& t) {
  if (lastYear != t.yr || lastMonth != t.mon || lastDate != t.date) {
    lastYear = t.yr;
    lastMonth = t.mon;
    lastDate = t.date;
    char dateBuffer[11];
    sprintf(dateBuffer, "%04d-%02d-%02d", t.yr, t.mon, t.date);
    lcd.setCursor(0, 0);
    lcd.print(dateBuffer);
  }

  if (lastHour != t.hr || lastMinute != t.min || lastSecond != t.sec) {
    lastHour = t.hr;
    lastMinute = t.min;
    lastSecond = t.sec;
    char timeBuffer[9];
    sprintf(timeBuffer, "%02d:%02d:%02d", t.hr, t.min, t.sec);
    lcd.setCursor(0, 1);
    lcd.print(timeBuffer);
  }
  lastMinute = t.min;  // Update the last minute
}
