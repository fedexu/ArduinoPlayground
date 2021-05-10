#include "UserController.h"
#include "api/APIServer.h"

void UserController::printUser()
{
    APIServer &apiServer = APIServer::getInstance();
    String user = apiServer.server->pathArg(0);
    apiServer.server->send(200, "text/plain", "User: '" + user + "'");
}

void UserController::printUserAndDevice()
{
    APIServer &apiServer = APIServer::getInstance();
    String user = apiServer.server->pathArg(0);
    String device = apiServer.server->pathArg(1);
    apiServer.server->send(200, "text/plain", "User: '" + user + "' and Device: '" + device + "'");
}
