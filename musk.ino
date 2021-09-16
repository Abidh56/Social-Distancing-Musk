//social distancing mask by Abid Hossain
//

#include "Adafruit_VL53L0X.h"

int green = 5;
int red = 3;
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  pinMode ( green, OUTPUT);
  pinMode ( red, OUTPUT);

  delay(1000);
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }
  // power
  Serial.println(F("VL53L0X API Simple Ranging example\n\n"));
}


void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  /*
      if (measure.RangeStatus != 4) {  // phase failures have incorrect data
       Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
      } else {
       Serial.println(" out of range ");

      }
  */


  if (measure.RangeMilliMeter >= 500 & measure.RangeMilliMeter < 1000) {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    delay(1000);
  }



  else if (measure.RangeMilliMeter < 500) {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    delay(50);
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    delay(50);

  }

  else {
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
  }

  delay(100);
}
