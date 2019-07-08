/*
    Copyright (c) 2019 Lorenzo Sarti. All right reserved.

    MKR 1010 WiFi RGB LED is a Library to manage in a simple way the RGB LED
    integrated in the MKR wifi 1010 board.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3.0 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/


#include "MKR1010WiFiRGBLed.h"

/*******************************************
 * Global variables                        *
 *******************************************/
int WL_STATUS = 0;


/******************************************* 
 * Constructor - Initilize variables       *
 *******************************************/
void WL_setup() {
    // Initialize Pins
    WiFiDrv::pinMode(WL_GREEN_PIN, OUTPUT);
    WiFiDrv::pinMode(WL_RED_PIN, OUTPUT);   
    WiFiDrv::pinMode(WL_BLUE_PIN, OUTPUT); 
}


/******************************************* 
 * Getter - Allows to check led status     *
 *******************************************/
int WL_getStatus() {
    return WL_STATUS;
}


/******************************************* 
 * shutOff - Shuts off the LED             *
 *******************************************/
void WL_shutOff() {
    WiFiDrv::digitalWrite(WL_RED_PIN, LOW);
    WiFiDrv::digitalWrite(WL_GREEN_PIN, LOW);
    WiFiDrv::digitalWrite(WL_BLUE_PIN, LOW);
    WL_STATUS = 0;
}


/*******************************************************************
 * setColor - Turns on the LED specifying the RGB values (0 - 255) *
 *******************************************************************/
void WL_setColor(int red, int green, int blue) {
    WiFiDrv::digitalWrite(WL_RED_PIN, WL_formatColorValue(red));
    WiFiDrv::digitalWrite(WL_GREEN_PIN, WL_formatColorValue(green));
    WiFiDrv::digitalWrite(WL_BLUE_PIN, WL_formatColorValue(blue));
    WL_STATUS = 1;
}


/********************************************************************
 * setDefaultColor - Turns on the LED using predefined color values *
 ********************************************************************/
void WL_setDefaultColor(DefaultColor clr) {
    switch(clr){
        case RED:   {WL_setColor(255,   0,   0); break;}
        case GREEN: {WL_setColor(  0, 255,   0); break;}
        case BLUE:  {WL_setColor(  0,   0, 255); break;}
        case YELLOW:{WL_setColor(255, 255,   0); break;}
        case ORANGE:{WL_setColor(255, 128,   0); break;}
        case WHITE: {WL_setColor(255, 255, 255); break;}
        case PURPLE:{WL_setColor(128,   0, 128); break;}
        case CYAN:  {WL_setColor(  0, 255, 255); break;}
        default: {WL_setColor(0, 0, 0);}
    }   
}


/*********************************************
 * formatColorValue - Format the given value *
 *                    to stay in the 0-255   *
 *                    interval               *
 *********************************************/
int WL_formatColorValue(int clr) {
    if(clr < LOW){
        return LOW;
    } else if(clr > HIGH){
        return HIGH;
    }else{
        return clr;
    }
}
