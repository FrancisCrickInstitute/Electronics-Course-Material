#include <Wire.h> // I2C library it comes from two-wire

#define I2C_SCL 21 // Clock pin
#define I2C_SDA 22 // Data pin
#define ADR 0x60 // Default adress for the device connected to GND is 0x60

int sig;
byte buffer [3];

void setup(void) 
{
  Wire.begin(I2C_SDA, I2C_SCL); // I2C Initialization 
  Serial.begin(9600);
    
}

void loop(void) 
{
    sig = analogRead(15);
    Serial.println(sig);
    sendI2C(ADR,sig);
}

void sendI2C(int busadress , unsigned int value)
{
   buffer[0] = 0b01000000; 
   buffer[1] = value >> 4;
   buffer[2] = value << 4;
   Wire.beginTransmission(busadress);
   Wire.write (buffer[0]);
   Wire.write (buffer[1]);
   Wire.write (buffer[2]);
   Wire.endTransmission();
}
