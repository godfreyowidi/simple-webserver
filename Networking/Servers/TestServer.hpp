#ifndef TestServer_hpp
#define TestServer_hpp
#include <stdio.h>
#include <string.h>

#include "WebServer.hpp"

namespace WEBSERVER
{
class TestServer: public WebServer
{
private:
    char buffer[30000] = {0};
    int new_socket;

    void acceptor();
    void handler();
    void responder();
public:
    TestServer();
    void launch();
};  
} // namespace WEBSERVER


#endif /* TestServer_hpp */