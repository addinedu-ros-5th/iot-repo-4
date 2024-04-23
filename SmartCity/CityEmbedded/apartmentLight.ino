//shift register
int latch = 8;
int clock = 9;
int data = 10;

//initialization
void setup() {
  Serial.begin(9600);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
}

void loop() {
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, B11111111);
  digitalWrite(latch, HIGH);
}