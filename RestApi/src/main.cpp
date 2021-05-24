#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ESPmDNS.h>
#include <BlinkLed2.h>

#include "api/APIServer.h"

const char *ssid = "Vodafone-FedeXu"; //  your network SSID (name)
const char *password = "NeverMind1";  // your network password

APIServer &apiServer = APIServer::getInstance();

uint8_t dis_count = 0;

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

  //Reboot ESP32 if Wi-fi connection is lost (fixes some issues)
  delay(1000);
  if (WiFi.status() != WL_CONNECTED)
  {
    dis_count++;
    Serial.println("Not Connected to Wi-Fi | " + String(dis_count));
  }
  else
  {
    dis_count = 0;
  }

  if (dis_count > 60)
  {
    Serial.println("Restarting ESP");
    delay(1000);
    ESP.restart();
  }
}

void connectToWifi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
    dis_count++;
    if (dis_count > 60)
    {
      Serial.println();
      Serial.println("Restarting ESP");
      delay(1000);
      ESP.restart();
    }
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
