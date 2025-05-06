
#include "ByeCommand.h"


ByeCommand::ByeCommand(
        ServerGameController *server,
        const ParsedMessage &parsedMessage,
        GameServiceCommandController *gameService
) : ClientCommand(server, parsedMessage, gameService) {

}

void ByeCommand::execute() {
    server->sendToClient(MessagePrinter::byeMessage(), parsedMessage.senderName);
    server->disconnectClient(parsedMessage.senderName);
}
