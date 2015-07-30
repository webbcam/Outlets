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

                         Sync Sketch
  This sketch will link an outlet to a particular channel

  - Change the CHANNEL value to the channel you'd like to sync your outlet to
  - Plug your Etekcity outlet into a wall outlet, and hold down the sync
    button until the red LED on the outlet begins to blink continuously
  - While the LED is still blinking, run this sketch on an arduino
    hooked up to a 434MHz transmitter (circuit described in README.md)
  
  If the outlet was synced correctly, after about 5 seconds (at most) 
  you should see your outlet toggle on and off repeatedly.

  Your outlet is now set to be controlled on the specified channel!
*********************************************************************/

#include "Outlet.h"  //  include all channels

const int DATA_PIN = 5;
Outlet outlet(DATA_PIN); //  make a new outlet instance with
const int CHANNEL_MAX = 10; // max range of channels
const bool ON = true;
const bool OFF = false;

const int CHANNEL = 1;  // change this to the channel you'd like to
                        //  sync your outlet to (1-10)

void setup() {
    Serial.begin(9600);
    Serial.println("Attempting to set outlet to channel ");
    Serial.print(CHANNEL);
    Serial.println("...");
    for (int i=0; i<3; i++) {
        outlet.sync(CHANNEL);
    }
    Serial.println("If outlet was sucessfully synced,");
    Serial.println(" it should currently be toggling on and off...");
}

void loop() {
    outlet.toggle(CHANNEL, ON);
    delay(500);
    outlet.toggle(CHANNEL, OFF);
}
