#include "WebServer.hpp"

WEBSERVER::WebServer::WebServer(int domain, int service, int protocol, int port, u_long interface, int bklg)
{
    socket = new ListeningSocket(domain, service, protocol, port, interface, bklg);
}

WEBSERVER::ListeningSocket * WEBSERVER::WebServer::get_socket()
{
    return socket;
}