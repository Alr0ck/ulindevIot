#include <ulindevIot.h>

#define address "YOUR_DOMAIN_ADDRESS"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  /* ---------------------------------------------  
    Change this baudrate value to fixed
    your communication between Arduino and ESP8266.
    The default value of ESP8266 is 115200.
    Ex : ul.begin(115200);
  ----------------------------------------------- */
  ul.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ul.connectTo("YOUR_SSID","YOUR_PASSWORD");

  delay(3000);

  String url = "YOUR_URL_TO_SENDING_DATA";
 
  ul.sendDataTo(url,address);

  delay(5000);
}
