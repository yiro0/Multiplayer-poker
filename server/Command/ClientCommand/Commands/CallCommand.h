
#ifndef MY_PROJECTS_CALLCOMMAND_H
#define MY_PROJECTS_CALLCOMMAND_H


#include "../ClientCommand.h"
#include "../../../Game/Game.h"
#include "../../../Game/DeckMaster.h"

class CallCommand : public ClientCommand{

private:
    DeckMaster *deckMaster;
    Game *game;

    MoveInfo exactExecute() override;

public:
    explicit CallCommand(
            ServerGameController *server,
            const ParsedMessage &parsedMessage,
            GameServiceCommandController *gameService
    );
};


#endif //MY_PROJECTS_CALLCOMMAND_H
