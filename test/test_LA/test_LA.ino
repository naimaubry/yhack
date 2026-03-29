// Linear actuator test using Step/Dir pins for 42HD stepper
const int stepPin = 6;
const int dirPin  = 7;

// How many steps you want to move
const long stepsForward = 2000;  // change based on actuator travel
const long stepsBackward = 2000;

// Delay between steps (controls speed, in microseconds)
const int stepDelay = 400; // smaller = faster, larger = slower

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Linear actuator test starting...");
}

void loop() {
  Serial.println("Moving forward...");
  digitalWrite(dirPin, HIGH); // set direction forward
  for (long i = 0; i < stepsForward; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelay);
  }

  delay(1000); // pause at end

  Serial.println("Moving backward...");
  digitalWrite(dirPin, LOW); // reverse direction
  for (long i = 0; i < stepsBackward; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelay);
  }

  delay(2000); // pause before repeating
}