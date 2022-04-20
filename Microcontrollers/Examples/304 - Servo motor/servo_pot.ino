#include <ESP32Servo.h> 

Servo myservo;  // create servo object to control a servo

int servoPin = 18;      // GPIO pin used to connect the servo control (digital out)
int potPin = 14;// GPIO pin used to connect the potentiometer (analog in)

int ADC_Max = 4096;     // This is the default ADC max value on the ESP32 (12 bit ADC width);
                        // this width can be set (in low-level oode) from 9-12 bits, for a
                        // a range of max values of 512-4096
  
int val;    // variable to read the value from the analog pin
int oldval; // variable to store previous value in order to check if change is big enough.

void setup()
{
	// Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
  myservo.setPeriodHertz(50);// Standard 50hz servo
  myservo.attach(servoPin, 500, 2400);   // attaches the servo on pin 18 to the servo object
                                         // using SG90 servo min/max of 500us and 2400us
                                         // for MG995 large servo, use 1000us and 2000us,
                                         // which are the defaults, so this line could be
                                         // "myservo.attach(servoPin);"
   Serial.begin(9600);
}

void loop() {
  oldval=val;
  val = analogRead(potPin);            // read the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, ADC_Max, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  if (abs(val-oldval)<2){
    val=oldval;
  }
  else{
    myservo.write(val);       // set the servo position according to the scaled value
    Serial.println(val);
  } 
}
