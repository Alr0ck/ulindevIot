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
