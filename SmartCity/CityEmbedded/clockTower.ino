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

  delay(200);  // Delay to refresh time display
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
