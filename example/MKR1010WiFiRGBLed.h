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


#ifndef MKR1010WiFiRGBLed_h
#define MKR1010WiFiRGBLed_h

#include <WiFiNINA.h>
#include <utility/wifi_drv.h>

/****************************************************
 * Defines Pins according to WiFiNINA documentation *
 *  (WL stands for WiFi Led)                        *
 ****************************************************/
#define WL_GREEN_PIN 25 
#define WL_RED_PIN 26
#define WL_BLUE_PIN 27


enum DefaultColor {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE,
    WHITE,
    PURPLE,
    CYAN,
};


//Public
void WL_setup();
int  WL_getStatus();
void WL_shutOff();
void WL_setColor(int red, int green, int blue);
void WL_setDefaultColor(DefaultColor clr);

//Private
int WL_formatColorValue(int clr);


#endif

