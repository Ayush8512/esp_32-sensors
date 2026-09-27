#include <ESP32Servo.h>

Servo myServo;

const int servoPin = 13;

void setup() {
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  
  myServo.setPeriodHertz(50);
  myServo.attach(servoPin, 500, 2400);
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);
    delay(15);
  }
  
  for (int pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);
    delay(15);
  }
}
