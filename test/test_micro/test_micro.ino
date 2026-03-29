#include <Servo.h>

const int soyServoPin = 10;
Servo soyServo;

void setup() {
  Serial.begin(9600);
  soyServo.attach(soyServoPin);  // attach servo to pin
  Serial.println("Microservo test starting...");
}

void loop() {
  // Move from 0° to 180°
  Serial.println("Moving servo 0° → 180°");
  for (int pos = 0; pos <= 180; pos += 1) { // increment by 1 degree
    soyServo.write(pos);
    delay(15); // wait 15ms for servo to reach position
  }

  delay(1000); // pause at 180°

  // Move back from 180° to 0°
  Serial.println("Moving servo 180° → 0°");
  for (int pos = 180; pos >= 0; pos -= 1) {
    soyServo.write(pos);
    delay(15);
  }

  delay(1000); // pause at 0°
}