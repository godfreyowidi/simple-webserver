
// This class implements a call to the connect()function of
// sockets as a definition of the connect_to_network virtual function from WbbSocket

#ifndef ConnectingSocket_hpp
#define ConnectingSocket_hpp

#include <stdio.h>

#include "WebSocket.hpp"

namespace WEBSERVER
{
class ConnectingSocket: public WebSocket
{
public:
    // Constructor
    ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);
         
    // Virtual function from parent
    int connect_to_network(int sock, struct sockaddr_in address);

};

} // namespace WEBSERVER

#endif /* BindingSocket_hpp */