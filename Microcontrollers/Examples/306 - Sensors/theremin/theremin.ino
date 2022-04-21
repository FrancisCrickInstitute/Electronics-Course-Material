#include <Tone32.hpp>
#include "Adafruit_VL53L0X.h"
#define I2C_SCL 21 // Clock pin
#define I2C_SDA 22 // Data pin
const int NUM_NOTES_IN_SCALE = 8;
const note_t C_SCALE[NUM_NOTES_IN_SCALE] = { NOTE_C, NOTE_D, NOTE_E, NOTE_F, NOTE_G, NOTE_A, NOTE_B, NOTE_C }; 
const int C_SCALE_OCTAVES[NUM_NOTES_IN_SCALE]  = { 4, 4, 4, 4, 4, 4, 4, 5 };
const char C_SCALE_CHARS[NUM_NOTES_IN_SCALE] = { 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C' }; 
note_t _lastNote = NOTE_C;

// Change this depending on where you connect your piezo buzzer
const int TONE_OUTPUT_PIN = 26;

// Change this depending on where you connect your input
const int SENSOR_INPUT_PIN = 14;

// The ESP32 has 16 channels which can generate 16 independent waveforms
// We'll just choose PWM channel 0 here
const int TONE_PWM_CHANNEL = 0; 

// Play each note for 500 ms
const int PLAY_NOTE_DURATION_MS = 500;

// The ESP32 has a 12-bit ADC, so our max analog value is 4095
const int MAX_ANALOG_VAL = 4095;

// Create our Tone32 object
Tone32 _tone32(TONE_OUTPUT_PIN, TONE_PWM_CHANNEL);
int dist;

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

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
    dist=lox.readRange();
  }
  int scaleIndex = map(dist, 0, 400, 0, NUM_NOTES_IN_SCALE - 1);
      Serial.println(scaleIndex);

  // Just walk up or down scale based on sensorVal position
  note_t note = C_SCALE[scaleIndex];
  int octave = C_SCALE_OCTAVES[scaleIndex];
  if(_lastNote != note){
     _tone32.playNote(note, octave, PLAY_NOTE_DURATION_MS);
  }

  // IMPORTANT: Unlike the regular Arduino tone function, which uses timer interrupts
  // for tracking time and automatically turning off PWM waves after the duration
  // interval passes, we use "polling". So, you must call update() to turn off
  // the sound automatically after the play duration expires
  _tone32.update();

  // Track the last note (we only play a note on a note change)
  // Yes, that means in this simple demo that we can't repeat the same
  // note twice consecutively!
  _lastNote = note;
}
