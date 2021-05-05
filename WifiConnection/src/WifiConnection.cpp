#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <BlinkLed2.h>

int wifiStatus = WL_IDLE_STATUS; // the Wifi radio's status
#define MAX_SRV_CLIENTS 1
const char *ssid = "Vodafone-FedeXu"; //  your network SSID (name)
const char *password = "NeverMind1";  // your network password
WiFiMulti wifiMulti;

void blinkLed2(int seconds);

void setup()
{
  // initialize serial:
  Serial.begin(9600);
  BlinkLed2::setupLed();
  // attempt to connect using WPA2 encryption:
  Serial.println("Attempting to connect to WPA network...");
  wifiMulti.addAP(ssid, password);
  // if you are connected, print out info about the connection:
  wifiStatus = wifiMulti.run();
  if (wifiStatus == WL_CONNECTED)
  {
    Serial.println("Connected to network");
    Serial.println("");
    Serial.print("WiFi connected ");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  // if you're not connected, stop here:
  if (wifiStatus != WL_CONNECTED)
  {
    Serial.println("WiFi connect failed");
    delay(1000);
    ESP.restart();
  }
}

void loop()
{
  BlinkLed2::blinkLed(1000, 1000);
}
