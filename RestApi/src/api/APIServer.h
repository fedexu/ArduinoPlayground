#include <Arduino.h>
#include <WebServer.h>
#include <uri/UriBraces.h>
#include <uri/UriRegex.h>

#ifndef APIServer_h
#define APIServer_h

class APIServer
{
public:
    static APIServer &getInstance()
    {
        static APIServer instance; // Guaranteed to be destroyed.
                                   // Instantiated on first use.
        return instance;
    }

    void initialize(int port);
    WebServer *server;

private:
    APIServer() {} 
    APIServer(APIServer const &);      // Don't Implement
    void operator=(APIServer const &); // Don't implement

public:
    ~APIServer()
    {
        delete server;
    }
};

#endif // APIServer_h
