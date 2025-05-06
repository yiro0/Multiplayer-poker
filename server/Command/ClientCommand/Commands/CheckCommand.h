
#ifndef MY_PROJECTS_CHECKCOMMAND_H
#define MY_PROJECTS_CHECKCOMMAND_H


#include "../ClientCommand.h"
#include "../../../Game/Game.h"
#include "../../../Game/DeckMaster.h"

class CheckCommand : public ClientCommand {

private:
    DeckMaster *deckMaster;
    Game *game;

    MoveInfo exactExecute() override;

public:
    explicit CheckCommand(
            ServerGameController *server,
            const ParsedMessage &parsedMessage,
            GameServiceCommandController *gameService
    );
};


#endif //MY_PROJECTS_CHECKCOMMAND_H
