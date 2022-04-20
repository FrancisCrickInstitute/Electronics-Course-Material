#include "Adafruit_VL53L0X.h"
#define I2C_SCL 21 // Clock pin
#define I2C_SDA 22 // Data pin
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
int dist;

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);
  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test.");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power
  Serial.println(F("VL53L0X API Continuous Ranging example\n\n"));

  // start continuous ranging
  lox.startRangeContinuous();
}

void loop() {
  if (lox.isRangeComplete()) {
    Serial.print("Distance in mm: ");
    dist=lox.readRange();
    Serial.println(dist);
  }

}
