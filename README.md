#Outlets

This is an Arduino library for controlling "Etekcity ZAP 5LX Remote Outlets"

HARDWARE:

    HARDWARE REQUIREMENTS:
        Etekcity Wireless Outlets:    http://www.etekcity.com/product/100058.html
        434MHz Transmitter:     http://amzn.com/B00M2CUALS
        9V or 12V DC Power Supply
        Arduino (or similar MCU)

    CONNECTIONS:
        Arduino: PIN 4  ->  434MHz-Module: DATA PIN
        12V powersupply + -> 434MHz-Module: VCC
        12V powersupply - -> 434MHz-Module: GND & Arduino: GND

    SETUP:
        12V Powersupply to power the 434MHz-Module
        * Make sure to use common ground with Arduino

        Connect an Arduino pin (here we use pin 4) to DATA PIN of Transmitter


SOFTWARE:
    
    SETUP:
        Create a new sketch
        To include the library you simply place at the top of program:
                #include "Outlet.h"


        Before the void setup() method, create an Outlet instance and specifiy the DATA_PIN:
                Outlet outlet(DATA_PIN);

    USE:
        You can toggle the outlet's state by calling its toggle function
        and passing it the channel (1-5) and power state 
        (true->on or false->off)

            i.e.
            outlet_name.toggle(1, true);


Please see the examples for more information!

*NOTE: Currently there are 10 different channels available and more to come! Remember every outlet can work on up to three different channels.
Since these outlets have the special learning feature, the amount of possible unique channels are (*almost) limitless! 
(*at least up to 2^10 = 1024 different channels)


