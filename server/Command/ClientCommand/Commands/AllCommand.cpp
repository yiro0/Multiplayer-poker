
#include "AllCommand.h"

AllCommand::AllCommand(
        ServerGameController *server,
        const ParsedMessage &parsedMessage,
        GameServiceCommandController *gameService
) : ClientCommand(server, parsedMessage, gameService) {
    deckMaster = gameService->getDeckMaster();
    game = gameService->getGame();
}

MoveInfo AllCommand::exactExecute() {
    deckMaster->evaluatePlayingPlayersCards(game->getPlayingPlayersRef());
    Player &player = game->currentPlayer();
    int bid = game->getBid();
    if (player.getCredit() > bid || bid == 0 || player.isExchange() || player.getCredit() <= 0) { return MoveInfo::NOT_ALLOWED; }

    player.setTurn(false);
    game->addToBank(player.getCredit());
    gameService->removeCreditFromPlayerAndPlayingPlayer(player, player.getCredit());
    player.setDiff(0);
    game->setAllIn(true);

    return gameService->moveAccepted();
}