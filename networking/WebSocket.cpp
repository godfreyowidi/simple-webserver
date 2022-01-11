#include "WebSocket.hpp"

// Default constructor
WEBSERVER::WebSocket::WebSocket(int domain, int service, int protocol, int port, u_long interface)
{
    // Define address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);
    // Establish socket
    sock = socket(domain, service, protocol);
    test_connection(sock);
    // Establish newtwork connection
    connection = connect_to_network(sock, address);
    test_connection(connection);
}

// Test connection virtual function

void WEBSERVER::WebSocket::test_connection(int item_to_test)
{
    // Confirm that the socket or connection has been properly established
    if (item_to_test < 0)
    {
        perror("Check your connection...");
        exit(EXIT_FAILURE);
    }
}

// Getter functions

struct sockaddr_in WEBSERVER::WebSocket::get_address()
{
    return address;
}

int WEBSERVER::WebSocket::get_sock()
{
    return sock;
}

int WEBSERVER::WebSocket::get_connection()
{
    return connection;
}