#ifndef WebServer_hpp
#define WebServer_hpp
#include <stdio.h>
#include <unistd.h>

#include "../webserver-networking.hpp"

namespace WEBSERVER
{
class WebServer
{
private:
    ListeningSocket * socket;
    virtual void acceptor() = 0;
    virtual void handler() = 0;
    virtual void responder() = 0;
public:
    WebServer(int domain, int service, int protocol, int port, u_long interface, int bklg);
    virtual void launch() = 0;
    ListeningSocket * get_socket();
};    
} // namespace WEBSERVER


#endif /* WebServer_hpp */