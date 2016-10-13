/***********************************
Please, don't remove this text!

Created by hcix_c0d3r
at 13 Oct 2016
Project name:
ESP-Arduino Internet Of Things
visit me : http://ulindev.com
************************************/

#ifndef ulindevIot_H
#define ulindevIot_H

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SoftwareSerial.h>

class ulindevIot{
	public:
	void begin(int baudrate);
	bool connectTo(String SSID, String PASS);
	void sendDataTo(String GET, String IP);
	void sendDebug(String cmd);
};

extern ulindevIot ul;

#endif
