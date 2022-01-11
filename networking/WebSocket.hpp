#ifndef WebSocket_hpp
#define WebSocket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>>

namespace WEBSERVER
{
class WebSocket
{
private:
    struct sockaddr_in address; 
    int sock;
    int connection;
public:
// Constructor
    WebSocket(int domain, int service, int protocol, int port, u_long interface);
// Virtual function to connect to a network
    virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;
// Function to test sockets and connections
    void test_connection(int);
// Getter functions
    struct sockaddr_in get_address();
    int get_sock();
    int get_connection();

    // Setter function
    void set_connection(int con);
};
} // namespace WEBSERVER


#endif /* WebSocket_hpp */