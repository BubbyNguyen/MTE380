#include <TinyStepper_28BYJ_48.h>


// pin assignments, any digital pins can be used
const int LED_PIN = 13;
const int MOTOR_IN1_PIN = 11;
const int MOTOR_IN2_PIN = 10;
const int MOTOR_IN3_PIN = 6;
const int MOTOR_IN4_PIN = 5;


const int STEPS_PER_REVOLUTION = 2048;


// create the stepper motor object
TinyStepper_28BYJ_48 stepper;

int encoder = 0;


void setup() 
{
  // setup the LED pin and enable print statements
  pinMode(LED_PIN, OUTPUT);   
  Serial.begin(9600);

  // connect and configure the stepper motor to its IO pins
  stepper.connectToPins(MOTOR_IN1_PIN, MOTOR_IN2_PIN, MOTOR_IN3_PIN, MOTOR_IN4_PIN);
}



void loop() 
{
  // Note: This example uses "absolute" motions, meaning the values
  // sent to the move commands use a coordinate system where 0 is the
  // initial position of the motor when it is first turned on.
  
  // set the speed and acceleration rates for the stepper motor
  stepper.setSpeedInStepsPerSecond(650);
  stepper.setAccelerationInStepsPerSecondPerSecond(1500);

if(Serial.available()>0)
{
  char input = Serial.read();
  if (input=='w')
  {
  encoder+=500;
  //Serial.print("Encoder:" + encoder);
  }
 if (input=='e')
  {
  encoder = 0;
   }
  stepper.moveToPositionInSteps(encoder);
}
}
