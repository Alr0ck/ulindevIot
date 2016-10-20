# ulindevIot
ESP8266 and Arduino Libraries to Monitoring your Internet of Things Projects.
Simple and easy to use beginners.

//-----------------------------------------------------------------------------//

example to use this code with arduino (mega, uno, nano, etc) :

#include <ulindevIot.h>
#define address "YOUR_DOMAIN_ADDRESS"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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

//-----------------------------------------------------------------------------//

Wiring between Arduino and Esp8266 :

Arduino ---------- Esp8266
   D3   ----------   tx
   D4   ----------   rx
 3.3V   ----------   3.3V
  GND   ----------   GND
  
//-----------------------------------------------------------------------------//

Visit Me,
my website : ulindev.com
my blog    : blog.ulindev.com

Regreads, hcix
