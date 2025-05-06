
#include "ServerInvalidCommand.h"

ServerInvalidCommand::ServerInvalidCommand(ServerCommandController *pController) : ServerCommand(pController) {
}

void ServerInvalidCommand::execute() {
    std::cout << MessagePrinter::invalidServerCommand() << std::endl;
}

