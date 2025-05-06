
#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

class Client {
private:

    const char *hostname;
    int port;
    int client_socket;
    sockaddr_in server{};

    Client(const char *hostname, int port);
    void createSocket();
    void createServer();
    void connectToServer();
    void startThreads();
    static void *receive_message(void *arg);
    static void *send_message(void *arg);

public:

    static Client createClient(const char *hostname, int port);
    void start();

};


#endif //CLIENT_CLIENT_H
