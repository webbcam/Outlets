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

#ifndef Outlet_h
#define Outlet_h
#include "Arduino.h"

class Outlet {
    public:
        Outlet(int pin);
        // toggles all outlets on the specified channel on(true) or off(false)
        void toggle(int channel, bool state);
        //  use to sync an outlet with a specific channel
        void sync(int channel); //   each outlet can remember up to 3 different channels
        
    private:
        int DATA_PIN;
        void preamble();
        void postambleOn();
        void postambleOff();

        void one();
        void zero();

        /************     ETEKCITY CHANNELS     ************/
        void ch1();
        void ch2();
        void ch3();
        void ch4();
        void ch5();

        /************     CUSTOM CHANNELS     ************/
        void ch6();
        void ch7();
        void ch8();
        void ch9();
        void ch10();


};

#endif
