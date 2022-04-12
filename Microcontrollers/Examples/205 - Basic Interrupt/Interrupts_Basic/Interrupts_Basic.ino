// Declare constants
const int BUTTON_PIN = 18;
const int LED_PIN = 19;

//Declare variables
volatile bool state = 0;

void setup()
{
    
  Serial.begin(9600); // Initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // The Button will be by default connected to 3.3V on HIGH or 1 logic
  pinMode(LED_PIN, OUTPUT); 
  digitalWrite(LED_PIN, LOW);
  
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), toogle, FALLING);// The Interrupt calls the function toogle
  
}

void loop()
{
    Serial.println(state); // Print the state in every condition so we can see where we are
    digitalWrite(LED_PIN, state);
}

void toogle() 
{
  state = !state;
}
