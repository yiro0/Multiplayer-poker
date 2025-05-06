
#include "ServerInfoCommand.h"

ServerInfoCommand::ServerInfoCommand(ServerCommandController *pController)
        : ServerCommand(pController) {
}

void ServerInfoCommand::execute() {
    server->printGameInfo();
}

