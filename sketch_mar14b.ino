#include "PololuDriver.h"
#include "Ramps.h"
#include <SoftwareSerial.h>

Ramps ramps = Ramps();
int microseconds = 100;
bool on = false;
void setup() {
  Serial.begin(9600);

  
}

/*
Serial input key
1 - step x motor
2 - step y motor
3 - step z motor
4 - step e motor
5 - step q motor
*/
void loop() {
  

  while (Serial.available()) {

    char in_char = Serial.read();
    if (in_char != "-1") {
      Serial.println(in_char);
      if (in_char == '1') {
        on = true;
        Serial.println("turning on");
      } else {
        Serial.println("turning off");
        on = false;
      }
    }
  }
  if (on == true) {
    ramps.motorE.stepOn();
  }

  delayMicroseconds(microseconds);


  ramps.motorE.stepOff();
}