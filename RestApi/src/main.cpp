#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <uri/UriBraces.h>
#include <uri/UriRegex.h>

const char *ssid = "Vodafone-FedeXu"; //  your network SSID (name)
const char *password = "NeverMind1";  // your network password

WebServer server(80);

void setup(void)
{
  Serial.begin(9600);
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

  server.on("/", HTTP_GET, []() {
    server.send(200, "text/plain", "hello from esp32!");
  });

  server.on(UriBraces("/users/{}"), HTTP_POST, []() {
    String user = server.pathArg(0);
    server.send(200, "text/plain", "User: '" + user + "'");
  });

  server.on(UriRegex("^\\/users\\/([0-9]+)\\/devices\\/([0-9]+)$"), HTTP_GET, []() {
    String user = server.pathArg(0);
    String device = server.pathArg(1);
    server.send(200, "text/plain", "User: '" + user + "' and Device: '" + device + "'");
  });

  server.on("/test", HTTP_POST, []() {
    //Deserializzo il body in un json
    DynamicJsonDocument request(1024);
    deserializeJson(request, server.arg("plain"));
    JsonObject requestObj = request.as<JsonObject>();

    //Accedo/manipolo il Json
    if (requestObj.containsKey("test")){
      Serial.println(requestObj["test"].as<String>());
    }

    //Serializzo il Json
    DynamicJsonDocument response(512);
    String buffer;
    response["status"] = "OK";
    serializeJson(response, buffer);

    server.send(200, "application/json", buffer);
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void)
{
  server.handleClient();
  delay(2); //allow the cpu to switch to other tasks
}