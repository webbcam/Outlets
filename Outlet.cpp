/*********************************************************************
This is a library to control "Etekcity ZAP 5LX Remote Outlets"
with a 434MHz RF Transmitter and Arduino

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
                         Outlet Base Class
*********************************************************************/

#include "Outlet.h"
#include "Arduino.h"

//  SET BIT SIZE AND TIMINGS
//  unsigned long _BITSIZE = 0.735 * 1000;   //  milliseconds -> microseconds
//  one bit = 0.735     (16 bits per period)
//  1/2 period = 5.88 ms
unsigned long _BREAK = 5.745 * 1000;
unsigned long _HIGHLONG = 0.5 * 1000;
unsigned long _HIGHSHORT = 0.135 * 1000;
unsigned long _LOWSHORT = 0.235 * 1000;
unsigned long _LOWLONG = 0.60 * 1000;


Outlet::Outlet(int pin) {
    DATA_PIN = pin;     //  pin of MCU to send signal to transmitter
    pinMode(DATA_PIN, OUTPUT);
    digitalWrite(DATA_PIN, LOW);    // default state is low
}

/* ****** PUBLIC METHODS ******* */

/*  toggle:
*       used to switch outlets on a specific channel on/off
*       state:    true -> on    false -> off
*/
void Outlet::toggle(int channel, bool state) {
    //  send signal 5 times to cover for any loss of signal
    for (int i=0; i<8; i++) {   // x8 is a bit precautious, 6 should be the bare minimum
        preamble();
        switch(channel) {
            case 1:
                ch1();
                break;
            case 2:
                ch2();
                break;
            case 3:
                ch3();
                break;
            case 4:
                ch4();
                break;
            case 5:
                ch5();
                break;
            case 6:
                ch6();
                break;
            case 7:
                ch7();
                break;
            case 8:
                ch8();
                break;
            case 9:
                ch9();
                break;
            case 10:
                ch10();
                break;
        }
        state ? postambleOn() : postambleOff();
    }
}

/*  sync:
*       used to pair an outlet with a particular channel
*       each outlet can remember up to three unique channels
*/
void Outlet::sync(int channel) {
    toggle(channel, true);
    toggle(channel, true);
}


/*************************************************************
*************************************************************/


/* ****** PRIVATE METHODS ******* */
void Outlet::one() {
    digitalWrite(DATA_PIN, HIGH);
    delayMicroseconds(_HIGHLONG);
    digitalWrite(DATA_PIN, LOW);
    delayMicroseconds(_LOWSHORT);
}

void Outlet::zero() {
    digitalWrite(DATA_PIN, HIGH);
    delayMicroseconds(_HIGHSHORT);
    digitalWrite(DATA_PIN, LOW);
    delayMicroseconds(_LOWLONG);
}

//  every signal starts out with this preamble
//  to initiate communication with outlet

//  0101000101
void Outlet::preamble() {
    delayMicroseconds(_BREAK);

    zero();
    one();
    zero();
    one();
    zero();
    zero();
    zero();
    one();
    zero();
    one();
}

// every signal ends with a postamble to specify whether to turn the outlet on or off
//  ON:
//  00110
void Outlet::postambleOn() {
    zero();
    zero();
    one();
    one();
    zero();
}
//  OFF:
//  11000
void Outlet::postambleOff() {
    one();
    one();
    zero();
    zero();
    zero();
}

// 0b0000000000 <= addr <= 0b1111111111
void Outlet::toggleAddr(int addr, bool state)
{
	for (int j = 0; j < 8; j++)
	{
        preamble();
		for (int i = 9; i >= 0; i--)
		{
			if ((addr >> i) & 1) one();
			else zero();
		}
        state ? postambleOn() : postambleOff();
	}
}

/************     ETEKCITY CHANNELS     ************/
//  0101010011
void Outlet::ch1() {
    zero();
    one();
    zero();
    one();
    zero();
    one();
    zero();
    zero();
    one();
    one();
}
//  0101011100
void Outlet::ch2() {
    zero();
    one();
    zero();
    one();
    zero();
    one();
    one();
    one();
    zero();
    zero();
}

//  0101110000
void Outlet::ch3() {
    zero();
    one();
    zero();
    one();
    one();
    one();
    zero();
    zero();
    zero();
    zero();
}

//  0111010000
void Outlet::ch4() {
    zero();
    one();
    one();
    one();
    zero();
    one();
    zero();
    zero();
    zero();
    zero();
}

//  1101010000
void Outlet::ch5() {
    one();
    one();
    zero();
    one();
    zero();
    one();
    zero();
    zero();
    zero();
    zero();
}

/************     CUSTOM CHANNELS     ************/

//  1101010011
void Outlet::ch6() {
    one();
    one();
    zero();
    one();
    zero();
    one();
    zero();
    zero();
    one();
    one();
}

//  1101011100
void Outlet::ch7() {
    one();
    one();
    zero();
    one();
    zero();
    one();
    one();
    one();
    zero();
    zero();
}

//  1101110000
void Outlet::ch8() {
    one();
    one();
    zero();
    one();
    one();
    one();
    zero();
    zero();
    zero();
    zero();
}

//  1111010000
void Outlet::ch9() {
    one();
    one();
    one();
    one();
    zero();
    one();
    zero();
    zero();
    zero();
    zero();
}

//  1111010011
void Outlet::ch10() {
    one();
    one();
    one();
    one();
    zero();
    one();
    zero();
    zero();
    one();
    one();
}
