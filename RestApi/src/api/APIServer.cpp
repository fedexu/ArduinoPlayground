#include "APIServer.h"
#include "./api/user/UserController.h"
#include "./api/test/TestController.h"

void APIServer::initialize(int port)
{
    server = new WebServer(port);

    server->on("/", HTTP_GET, []() {
        APIServer &apiServer = APIServer::getInstance();
        apiServer.server->send(200, "text/plain", "hello from Arduino!");
    });

    server->on(UriBraces("/users/{}"), HTTP_GET, []() { UserController::printUser(); });
    server->on(UriRegex("^\\/users\\/([0-9]+)\\/devices\\/([0-9]+)$"), HTTP_GET, []() { UserController::printUserAndDevice(); });

    server->on("/test", HTTP_POST, []() { TestController::test(); });

    server->begin();
    Serial.println("HTTP server started");
}