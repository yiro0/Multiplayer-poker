
#ifndef MY_PROJECTS_SERVERGAMECONTROLLER_H
#define MY_PROJECTS_SERVERGAMECONTROLLER_H


#include "ServerMessageSender.h"

class ServerGameController : public ServerMessageSender {

public:
    virtual void disconnectClient(const std::string &clientName) = 0;
};


#endif //MY_PROJECTS_SERVERGAMECONTROLLER_H
