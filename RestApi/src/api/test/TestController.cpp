#include "TestController.h"
#include "api/APIServer.h"
#include <BlinkLed2.h>

void TestController::test(){
    APIServer &apiServer = APIServer::getInstance();
    // Deserializzo il body in un json
    DynamicJsonDocument request(1024);
    deserializeJson(request, apiServer.server->arg("plain"));
    JsonObject requestObj = request.as<JsonObject>();

    //Accedo/manipolo il Json
    if (requestObj.containsKey("test"))
    {
      Serial.println(requestObj["test"].as<String>());
    }

    if (requestObj.containsKey("blink") && requestObj["blink"].as<boolean>()){
      Serial.println(requestObj["blink"].as<boolean>());
      BlinkLed2::blinkLed(1000, 1000);
    }

    //Serializzo il Json
    DynamicJsonDocument response(512);
    String buffer;
    response["status"] = "OK";
    serializeJson(response, buffer);

    apiServer.server->send(200, "application/json", buffer);
}