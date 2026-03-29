#include <AccelStepper.h>

// Define pins for the valve stepper
#define VALVE_STEP_PIN 8
#define VALVE_DIR_PIN 9

// Create AccelStepper object (DRIVER mode for step/dir)
AccelStepper valveStepper(AccelStepper::DRIVER, VALVE_STEP_PIN, VALVE_DIR_PIN);

void setup() {
  Serial.begin(9600);
  
  // Configure maximum speed and acceleration
  valveStepper.setMaxSpeed(2000);      // steps per second
  valveStepper.setAcceleration(500);   // steps per second^2

  Serial.println("Valve stepper test starting...");
}

void loop() {
  // Move forward 1000 steps
  Serial.println("Opening valve (forward 1000 steps)...");
  valveStepper.moveTo(1000);
  while (valveStepper.distanceToGo() != 0) {
    valveStepper.run();  // non-blocking step
  }
  delay(1000);

  // Move back to 0
  Serial.println("Closing valve (back to 0 steps)...");
  valveStepper.moveTo(0);
  while (valveStepper.distanceToGo() != 0) {
    valveStepper.run();
  }
  delay(1000);
}