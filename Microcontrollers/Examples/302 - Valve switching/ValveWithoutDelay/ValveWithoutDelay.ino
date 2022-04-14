
// Equivalent to Blink without Delay with valve

// constants won't change. Used here to set a pin number:
const int valvePin =  19;// the number of the LED pin

// Variables will change:
int valveState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 5000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(valvePin, OUTPUT);
}

void loop() 
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) 
  {
    // save the last time you actuated the valve
    previousMillis = currentMillis;

    // if the valve is off turn it on and vice-versa:
    if (valveState == LOW) 
    {
      valveState = HIGH;
    } else 
    {
      valveState = LOW;
    }

    digitalWrite(valvePin, valveState);
  }
}
