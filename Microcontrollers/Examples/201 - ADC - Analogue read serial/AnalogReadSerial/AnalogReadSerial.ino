// Declare  a global variable to read the sensor
int sensorValue = analogRead(15);

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() 
{
  //Prin the Sensor value on the serial port
  Serial.println(sensorValue);      
}
