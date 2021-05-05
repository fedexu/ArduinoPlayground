#include <Arduino.h>
#include <WiFi.h>
#include <BlinkLed2.h>

char ssid[] = "Vodafone-FedeXu";     //  your network SSID (name)
char pass[] = "NeverMind1";    // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status


void blinkLed2(int seconds);

void setup() {
  // initialize serial:
  Serial.begin(9600);
  BlinkLed2::setupLed();
  // attempt to connect using WPA2 encryption:
  Serial.println("Attempting to connect to WPA network...");
  status = WiFi.begin(ssid, pass);
  // if you're not connected, stop here:
  if ( status != WL_CONNECTED) {
    Serial.println("Couldn't get a wifi connection");
  }
  // if you are connected, print out info about the connection:
  else {
    Serial.println("Connected to network");
  }
}

void loop() {
  BlinkLed2::blinkLed(1000, 1000);
}


