const int irPin = 14;

void setup() {
  Serial.begin(115200);
  pinMode(irPin, INPUT);
}

void loop() {
  Serial.println(digitalRead(irPin));
  delay(100);
}
