
#ifndef MY_PROJECTS_CLIENTCOMMANDFACTORY_H
#define MY_PROJECTS_CLIENTCOMMANDFACTORY_H

#include "ClientCommand.h"

class ClientCommandFactory {
public:
    static Command *createCommand(
            ServerGameController *server,
            const ParsedMessage &parsedMessage,
            GameServiceCommandController *gameService
    );
};


#endif //MY_PROJECTS_CLIENTCOMMANDFACTORY_H
