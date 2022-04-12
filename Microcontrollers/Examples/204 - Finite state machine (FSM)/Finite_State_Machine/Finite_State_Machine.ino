// Declare constants
const int DELAY = 5000; //milliseconds
const int BUTTON_PIN = 18;
const int LED_PIN = 19;

//Declare variables
bool state = 0; // In this case we can only have 2 states 0 or 1
bool button;
unsigned long time_; // Time always will be positive

void setup()
{
    
  Serial.begin(9600); // Initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // The Button will be by default connected to 3.3V on HIGH or 1 logic
  pinMode(LED_PIN, OUTPUT); 
  digitalWrite(LED_PIN, LOW); // Initial state of the LED (LOW)
  
}

void loop()
{
    button = digitalRead(BUTTON_PIN); // Read the button value (High or Low)
    Serial.println(state);
    
    if(state == 0)
    {
        digitalWrite(LED_PIN, LOW); // If the state is 0 the LED is also LOW
        Serial.println(state);
        
        if(button == LOW) 
        { 
          // enter next state
          state = 1; // Chenge the state to 1
          Serial.println(state);
        }
    }
    if(state == 1)
    {
        Serial.print(state);
        Serial.print(" ");
        Serial.println(millis() - time_);
        if(button == LOW) // reset timer
        {
          time_ = millis();// Asign the variable time the value of the milliseconds in that instant
          digitalWrite(LED_PIN, HIGH);
          Serial.print(state);
          Serial.print(" ");
          Serial.println(millis() - time_);
        }
        if(millis() - time_  > DELAY) //check if time has passed
        {
          state = 0;
          Serial.println(state);
        }
    }
}
