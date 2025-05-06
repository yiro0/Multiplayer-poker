
#include "ClientConnection.h"
#include "ConnectionManager.h"

ClientConnection::ClientConnection(int socket, sockaddr_in address, std::string name)
        : socket(socket), address(address), name(std::move(name)) {}
