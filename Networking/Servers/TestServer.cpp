#include "TestServer.hpp"

WEBSERVER::TestServer::TestServer() : WebServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10)
{
    launch();
}

void WEBSERVER::TestServer::acceptor()
{
    struct sockaddr_in address = get_socket()->get_address();
    int addrlen = sizeof(address);
    new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);
    read(new_socket, buffer, 30000);
}

void WEBSERVER::TestServer::handler()
{
    std::cout << buffer << std::endl;
}

void WEBSERVER::TestServer::responder()
{
    char *hello = "HTTP/1.1 200 OK\nDate: Mon, 27 Jul 2009 12:28:53 GMT\nServer: Apache/2.2.14 (Win32)\nLast-Modified: Wed, 22 Jul 2009 19:15:56 GMT\nContent-Length: 88\nContent-Type: text/html\nConnection: Closed\n<html><body><h1>Hello, World!</h1></body></html>";
    write(new_socket, hello, strlen(hello));
    close(new_socket);
}

void WEBSERVER::TestServer::launch()
{
    while (true)
    {
        std::cout << "==== WAITING ====" << std::endl;
        acceptor();
        handler();
        responder();
        std::cout << "==== DONE ====" << std::endl;
    }
}