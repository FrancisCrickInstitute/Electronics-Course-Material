#include <ESP_FlexyStepper.h>

// IO pin assignments
const int MOTOR_STEP_PIN = 18;
const int MOTOR_DIRECTION_PIN = 19;
const int POT_PIN = 15;
const unsigned speed_ = 1000; // Steps per second
const unsigned accel = 2000; // Steps per second square

// create the stepper motor object
ESP_FlexyStepper stepper;

void setup() 
{
  Serial.begin(9600);
  
  // connect and configure the stepper motor to its IO pins
  stepper.connectToPins(MOTOR_STEP_PIN, MOTOR_DIRECTION_PIN);
}

void loop() 
{
  // set the speed and acceleration rates for the stepper motor
  stepper.setSpeedInStepsPerSecond(speed_);
  stepper.setAccelerationInStepsPerSecondPerSecond(accel);
  
  // Read the Poterntiometer
  int val = analogRead(POT_PIN);
  
  // Establish a linear relationship between the potentiometer range and the number of steps per revolution
  int steps = map(val, 0, 3670, 0, 200);

  // Send that position to the stepper
  stepper.moveToPositionInSteps(steps);

  // The delay helps with small movements related with the noise
  delay(200);
}
