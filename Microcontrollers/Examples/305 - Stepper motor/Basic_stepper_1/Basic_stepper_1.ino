
const int STEP_PIN = 18;
const int DIR_PIN = 19;
const int period = 5000;
//const int POT_PIN = 15;
//int val = 0;
int steps = 200;
//int old_mapped_val;

void setup() 
{
  Serial.begin(9600);

  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
}

void loop() 
{
 
  cw(period, steps);
  delay(1000);
  ccw(period, steps);
  delay(1000);

}

//Function to rotate the left motor CW
void cw (int pd, int steps)
{
  for(int i = 0; i<=steps; i++)
  {
   digitalWrite(DIR_PIN,1);
   digitalWrite(STEP_PIN,HIGH);
   delayMicroseconds(pd);
   digitalWrite(STEP_PIN,LOW);
   delayMicroseconds(pd);
  }
}

void ccw (int pd, int steps)
{
  for(int i = 0; i<=steps; i++)
  {
   digitalWrite(DIR_PIN,0);
   digitalWrite(STEP_PIN,HIGH);
   delayMicroseconds(pd);
   digitalWrite(STEP_PIN,LOW);
   delayMicroseconds(pd);
  }
}
////Function to rotate the right motor CW
//void ccw (int pd)
//{
//   digitalWrite(DIR_PIN,0);
//   digitalWrite(STEP_PIN,HIGH);
//   delayMicroseconds(pd);
//   digitalWrite(STEP_PIN,LOW);
//   delayMicroseconds(pd);
//}
