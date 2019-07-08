#include "MKR1010WiFiRGBLed.h"

void setup() {
  WL_setup();   // Setup the library
  WL_setDefaultColor(GREEN);  // Just to have a feedback
  delay(2000);  
}

void loop() {
  // loops through all the default colors
  for(int i=0; i<7; i++){
    WL_setDefaultColor((DefaultColor)i);
    delay(1500);
    WL_shutOff();
    delay(1500); 
  }
}
