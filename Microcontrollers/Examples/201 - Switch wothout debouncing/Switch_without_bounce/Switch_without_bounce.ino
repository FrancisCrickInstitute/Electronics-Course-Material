const int buttonPin = 19;
byte previousState = HIGH;         // what state was the button last time
unsigned int count;

void setup() 
{
  pinMode(buttonPin, INPUT_PULLUP); // It will be pulled high by default (Connected to 3.3V or logic HIGH) 
  Serial.begin(9600);
  Serial.println("Pushbutton bounce test:");
}

void loop() 
{
  byte buttonState = digitalRead(buttonPin);
  
  if (buttonState != previousState) // If the button state is different than the previous State
  {
    if (buttonState == LOW) // If the button state is == to low
    {
      count = count + 1;
      //delay(500);   // If our project can afford a delay we can use it to avoid problems
    }
    Serial.print("count: ");
    Serial.println(count);
  } 
}
