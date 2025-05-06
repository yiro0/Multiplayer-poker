
#ifndef MY_PROJECTS_GAMESERVICECOMMANDCONTROLLER_H
#define MY_PROJECTS_GAMESERVICECOMMANDCONTROLLER_H

#include "MoveInfo.h"
#include "DeckMaster.h"
#include "Game.h"

class GameServiceCommandController {
public:
    virtual void removeCreditFromPlayerAndPlayingPlayer(Player &player, int value) = 0;
    virtual MoveInfo moveAccepted() = 0;
    virtual MoveInfo exchangeMoveAcceptedInAllInCase() = 0;
    virtual void updateQueue() = 0;
    virtual void finishRound() = 0;
    virtual void finishGame() = 0;
    virtual bool isPlayerTurn(const std::string &senderName) = 0;
    virtual void sendInfoToAllPlayingPlayers() = 0;

    virtual DeckMaster *getDeckMaster() = 0;
    virtual Game *getGame() = 0;
    virtual std::string currentPlayerName() = 0;
    virtual std::string lastPlayerName() = 0;
    virtual bool isGameStarted() = 0;
    virtual int numOfPlayers() = 0;
    virtual std::string playingPlayerInfo(const std::string &senderName) = 0;
};

#endif //MY_PROJECTS_GAMESERVICECOMMANDCONTROLLER_H
