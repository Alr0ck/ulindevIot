/***********************************
Please, don't remove this text!

Created by hcix_c0d3r
at 13 Oct 2016
Project name:
ESP-Arduino Internet Of Things
visit me : http://ulindev.com
************************************/

#include "ulindevIot.h"

SoftwareSerial esp(3,4);

void ulindevIot::begin(int baudrate){
	esp.begin(baudrate);
	Serial.println("==========================================");
	Serial.println("Created with Love by : HCIX_c0d3r");
	Serial.println("visit my blog : http://blog.ulindev.com");
	Serial.println("==========================================");
	delay(1000);
	Serial.print("ESP Baudrate set ");
	Serial.println(baudrate);
	delay(1000);
}

bool ulindevIot::connectTo(String SSID, String PASS){
	esp.println("AT+CWMODE=1");
	delay(2000);
	String cmd="AT+CWJAP=\"";
	cmd+=SSID;
	cmd+="\",\"";
	cmd+=PASS;
	cmd+="\"";
	sendDebug(cmd);
	delay(5000);
	if(esp.find("OK")){
	Serial.println("RECEIVED: OK");
	return true;
	}else{
	Serial.println("RECEIVED: Error");
	return false;
	}
}

void ulindevIot::sendDataTo(String GET, String IP){
	String cmd = "AT+CIPSTART=\"TCP\",\"";
	cmd += IP;
	cmd += "\",80";
	sendDebug(cmd);
	delay(2000);
	if(esp.find("Error")){
	Serial.print("RECEIVED: Error");
	return;
	}
	cmd = "GET ";
	cmd += GET;
	cmd += " HTTP/1.0\r\n\r\n";
	esp.print("AT+CIPSEND=");
	esp.println(cmd.length());

	if(esp.find(">")){
	Serial.print(">");
	Serial.print(cmd);
	esp.print(cmd);
	}else{
	sendDebug("AT+CIPCLOSE");
	}

	if(esp.find("OK")){
	Serial.println("RECEIVED: OK");
	}else{
	Serial.println("RECEIVED: Error");
	}
}

void ulindevIot::sendDebug(String cmd){
  Serial.print("SEND: ");
  Serial.println(cmd);
  esp.println(cmd);
} 

ulindevIot ul;
