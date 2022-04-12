#include <Arduino.h>
#include <analogWrite.h>

const int IA = 19;  // Motor A pins
const int IB = 18;

int incomingByte = 0; // for incoming serial data
int  input = 0;

void setup() 
{

  pinMode(IA, OUTPUT);
  pinMode(IB, OUTPUT);

  digitalWrite(IA, LOW);
  digitalWrite(IB, LOW);

  analogWriteResolution(IA, 12);
  analogWriteResolution(IB, 12);
  
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

  Serial.println("select direction of movement");
  Serial.println("1.forward");
  Serial.println("2.backward");
  Serial.println("3.stop");
  Serial.println("4.start slowly");
  Serial.println("5.stop slowly");
}


void loop() 
{

  // send data only when you receive data:
  if (Serial.available() > 0) 
  {
    // read the incoming byte:
    incomingByte = Serial.read();
    input = incomingByte - 48; //convert ASCII code of numbers to 1,2,3

    switch (input) 
    { 
      case 1:         // if input=1 ....... motors turn forward
        Serial.println("Forward");
        forward();
        break;
      case 2:         // if input=2 ....... motors turn backward
        Serial.println("Backward");
        backward();
        break;
      case 3:         // if input=1 ....... motors turn stop
        Serial.println("Start slowly");
        Start_slowly();
        break;
      case 4:         // if input=1 ....... motors turn stop
        Serial.println("Stop slowly");
        Stop_slowly();
        break;
       case 5:         // if input=1 ....... motors turn stop
        Serial.println("Stop");
        Stop();
        break;
      default : Serial.println("Non existing case");
    }
  delay(200);
  
  input=0; // restart the input
  }

}

//function of forward 
void forward() 
{          
  analogWrite(IA, 255);
  analogWrite(IB, 0);
}

 //function of backward
void backward() 
{        
  analogWrite(IA, 0);
  analogWrite(IB, 210);
}

 //function of backward
void Stop() 
{        
  analogWrite(IA, 0);
  analogWrite(IB, 0);
}

//function of Stop_slowly
void Start_slowly() 
{              
  for(int i = 0; i <= 255; i++)
  {            
    analogWrite(IA, i);
    analogWrite(IB, 0);
    delay(50);
  }
}

//function of Start_slowly
void Stop_slowly() 
{  
  for(int i = 255; i >= 0; i--)
  {            
    analogWrite(IA, i);
    analogWrite(IB, 0);
    delay(50);
  }
}
