
#include "ServerCommandFactory.h"

Command *ServerCommandFactory::createCommand(
        ServerCommandController *server,
        const std::string &command
) {
    if (command == "/info") { return new ServerInfoCommand(server); }
    else if (command == "/stop") { return new StopCommand(server); }
    else { return new ServerInvalidCommand(server); }
}
