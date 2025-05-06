
#include "StopCommand.h"

StopCommand::StopCommand(ServerCommandController *pController) : ServerCommand(pController) {
}

void StopCommand::execute() {
    server->stop();
}
