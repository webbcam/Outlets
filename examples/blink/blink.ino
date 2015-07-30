/*********************************************************************
This is an example sketch that controls "Etekcity ZAP 5LX 
Remote Outlets" with a 434MHz RF Transmitter and Arduino
You can pick up a set of outlets here:   
    http://www.etekcity.com/product/100058.html
Along with a transmitter to talk to it:
    http://amzn.com/B00M2CUALS 
Please see http://www.webbhacks.com/Outlets
for more detailed information on this project
Written by Cameron J. Webb  (cam@webbhacks.com)
Copyright (c) 2015 Cameron J. Webb  
MIT License, check LICENSE for more information
All text above must be included in any redistribution
**********************************************************************
                         Simple Blink Sketch
  This sketch will cycle through each of the 5 channels for the 
  outlets turning each one on and then each one off
*********************************************************************/


#include "Outlet.h"  //  include all channels

const int DATA_PIN = 4;
Outlet outlet(DATA_PIN); //  make a new outlet instance with
const bool ON = true;
const bool OFF = false;
void setup() {
  //  nothing to set up
}

void loop() {
  //  turn each minor channel of outlet set on
  outlet.toggle(1, ON); //  turn ch1 on
  delay(500);
  outlet.toggle(2, ON); //  turn ch2 on
  delay(500);
  outlet.toggle(3, ON); //  turn ch3 on
  delay(500);
  outlet.toggle(4, ON);  //  turn ch4 on
  delay(500);
  outlet.toggle(5, ON);  //  turn ch5 on 
  delay(500);
  outlet.toggle(1, OFF);  //  turn ch1 off
  delay(500);
  outlet.toggle(2, OFF);  //  turn ch2 off
  delay(500);
  outlet.toggle(3, OFF);  //  turn ch3 off
  delay(500);
  outlet.toggle(4, OFF);  //  turn ch4 off
  delay(500);
  outlet.toggle(5, OFF);  //  turn ch5 off
  delay(500);
  
}
