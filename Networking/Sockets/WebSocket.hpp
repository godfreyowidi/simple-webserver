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
    /* MEMBER VARIABLES */
    // Once instantiated, sock contains the address of a socket object on the network
    // This should be a non-negative number
    int sock;
    // The address variable is a struct that contains information about the protocol, type, and interface
    // of a given socket, These parameters are specified and set in the constructor.
    struct sockaddr_in address;

public:
    /* CONSTRUCTOR */
    // A paramererized constructor is required in to instantiate the class
    WebSocket(int domain, int service, int protocol, int port, u_long interface);

    /* VIRTUAL FUNCTION */
    // This function connects to the network using either bind() or connect() from sys/socket.h
    virtual void connect_to_network(int sock, struct sockaddr_in address) = 0;

    /* TESTERS */
    // This function ends the program if the connection is not properly established.
    // This should be checked frequently.
    void test_connection(int);

    /* GETTERS */
    int get_sock();
    struct sockaddr_in get_address();
};
} // namespace WEBSERVER


#endif /* WebSocket_hpp */