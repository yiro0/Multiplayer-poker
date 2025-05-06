
#ifndef SERVER_CLIENTCONNECTION_H
#define SERVER_CLIENTCONNECTION_H


#include <netinet/in.h>
#include <string>

class ClientConnection {

private:
    int socket;
    sockaddr_in address;
    std::string name;

public:
    ClientConnection(int socket, sockaddr_in address, std::string name);

    int getSocket() const { return socket; }
    sockaddr_in getAddress() const { return address; }
    std::string getName() const { return name; }
};


#endif //SERVER_CLIENTCONNECTION_H
