
#ifndef MY_PROJECTS_FOLDCOMMAND_H
#define MY_PROJECTS_FOLDCOMMAND_H


#include "../ClientCommand.h"
#include "../../../Game/DeckMaster.h"
#include "../../../Game/Game.h"

class FoldCommand : public ClientCommand {

private:
    DeckMaster *deckMaster;
    Game *game;

    MoveInfo exactExecute() override;

public:
    explicit FoldCommand(
            ServerGameController *server,
            const ParsedMessage &parsedMessage,
            GameServiceCommandController *gameService
    );
};


#endif //MY_PROJECTS_FOLDCOMMAND_H
