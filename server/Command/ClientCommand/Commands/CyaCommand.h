
#ifndef MY_PROJECTS_CYACOMMAND_H
#define MY_PROJECTS_CYACOMMAND_H


#include "../ClientCommand.h"
#include "../../../Game/Game.h"
#include "../../../Game/DeckMaster.h"

class CyaCommand : public ClientCommand{

private:
    DeckMaster *deckMaster;
    Game *game;

    MoveInfo exactExecute() override;

public:
    explicit CyaCommand(
            ServerGameController *server,
            const ParsedMessage &parsedMessage,
            GameServiceCommandController *gameService
    );
};


#endif //MY_PROJECTS_CYACOMMAND_H
