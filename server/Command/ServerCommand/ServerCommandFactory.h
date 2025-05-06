
#ifndef MY_PROJECTS_SERVERCOMMANDFACTORY_H
#define MY_PROJECTS_SERVERCOMMANDFACTORY_H

#include "ServerCommand.h"
#include "Commands/ServerInvalidCommand.h"
#include "Commands/StopCommand.h"
#include "Commands/ServerInfoCommand.h"

class ServerCommandFactory {
public:
    static Command *createCommand(
            ServerCommandController *server,
            const std::string &command
    );
};


#endif //MY_PROJECTS_SERVERCOMMANDFACTORY_H
