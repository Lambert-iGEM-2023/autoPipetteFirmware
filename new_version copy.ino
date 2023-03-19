#include "PololuDriver.h"
#include "Ramps.h"
#include <SoftwareSerial.h>

Ramps ramps = Ramps();
int microseconds = 10000;
int on = 0;
int speed = 0;
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
// char in_char;

void loop() {
  

  while (Serial.available()) {

    char in_char = Serial.read();
    Serial.println("beginning of if");
    if (in_char != '0') {
      Serial.println(in_char);
      switch (in_char) {
        case '1' :
          on = 1;
          Serial.println("turning on");
         continue;  
        case '5' : 
          on = 2;
          Serial.println("i'm going fast!");
          break;
        default: 
        Serial.println("turning off");
        on = 0;

      }
      }
    }

switch (on) {
    case 1 : 
      //Serial.println("i'm moving slow");
     ramps.motorE.stepOn();
     delayMicroseconds(microseconds);
     ramps.motorE.stepOff();

     break;
    case 2 :
      ramps.motorE.stepOn();
      delayMicroseconds(microseconds - 9900); 
      ramps.motorE.stepOff(); 
      break;
    default: 
    ramps.motorE.stepOff();
    //Serial.println ("turning motor off");
    
  }

    
  }

  
   
