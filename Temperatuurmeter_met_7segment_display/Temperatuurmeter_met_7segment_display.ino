#include "SevSeg.h"
SevSeg sevseg; 



void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
  }
 
void loop() {

  // meet de spanning analoog en converteerd het naar een numeriek nummer tussen 0 en 1024
  int sensorValue = analogRead(A0);
  
 
  // converteerd de numerieke waarde in spanning
  float tension = (sensorValue / 204.6 );
  Serial.print(tension); // toont de berekende spanning
  Serial.print(" volts");
  Serial.print(" -----------> ");
 
  // converteerd de spanning naar graden celsius
  float temperature = ((tension * 100) - 273);
  Serial.print(temperature);
  Serial.println(" DEGRES");
  Serial.println();
  // 7segment display
    sevseg.setNumber(temperature,3);
    sevseg.refreshDisplay(); 
 
  delay(1000);
}
