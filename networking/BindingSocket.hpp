
// This class implements a call to the bind()function of
// sockets as a definition of the connect_to_network virtual function from WbbSocket

#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>

#include "WebSocket.hpp"

namespace WEBSERVER
{
class BindingSocket: public WebSocket
{
public:
    // Constructor
    BindingSocket(int domain, int service, int protocol, int port, u_long interface);
         
    // Virtual function from parent
    int connect_to_network(int sock, struct sockaddr_in address);

};

} // namespace WEBSERVER

#endif /* BindingSocket_hpp */