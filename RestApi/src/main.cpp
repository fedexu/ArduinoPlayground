#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ESPmDNS.h>
#include <BlinkLed2.h>

#include "api/APIServer.h"

const char *ssid = "Vodafone-FedeXu"; //  your network SSID (name)
const char *password = "NeverMind1";  // your network password

// WebServer server(80);
APIServer &apiServer = APIServer::getInstance();

void connectToWifi();

void setup(void)
{
  Serial.begin(9600);
  connectToWifi();
  apiServer.initialize(80);
  BlinkLed2::setupLed();
}

void loop(void)
{
  apiServer.server->handleClient();
  delay(2); //allow the cpu to switch to other tasks
}

void connectToWifi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32"))
  {
    Serial.println("MDNS responder started");
  }
}
