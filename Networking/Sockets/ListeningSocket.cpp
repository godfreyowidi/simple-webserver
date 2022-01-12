#include "ListeningSocket.hpp"

WEBSERVER::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklg): BindingSocket(domain, service, protocol, port, interface)
{
    // Set backlog variable
    backlog = bklg;
    // Start listening to the network using listen() from sys/socket.h
    start_listening();
    // Confirm the connection was successful
    test_connection(listening);
}

/* MUTATORS */
void WEBSERVER::ListeningSocket::start_listening()
{
    // Start listening on the network
    listening = listen(get_sock(), backlog);
}

/* GETTERS */
int WEBSERVER::ListeningSocket::get_listening()
{
    return listening;
}

int WEBSERVER::ListeningSocket::get_backlog()
{
    return backlog;
}