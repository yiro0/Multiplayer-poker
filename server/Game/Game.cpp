
#include <numeric>
#include "Game.h"
#include "../Server/MessagePrinter.h"

Game Game::createGame(int maxNumOfPlayers) {
    return Game(maxNumOfPlayers);
}

Game::Game(int maxNumOfPlayers)
        : maxNumOfPlayers(maxNumOfPlayers), cards({}), players({}), playingPlayers({}), winners({}),
          last(nullptr), current(nullptr), next(nullptr), started(false),
          allIn(false), bid(0), bank(0), part{0} {}

Game::Game()
        : Game(0) {
}

bool Game::isStarted() const {
    return started;
}

void Game::removePlayer(const std::string &playerName) {
    players.erase(std::remove_if(
                          players.begin(), players.end(),
                          [&playerName](const Player &player) { return player.getName() == playerName; }
                  ),
                  players.end()
    );
}

void Game::addPlayer(const Player &player) {
    players.push_back(player);
}

void Game::setStarted(bool toSet) {
    started = toSet;
}

int Game::getMaxNumOfPlayers() const {
    return maxNumOfPlayers;
}

void Game::addToBank(int toAdd) {
    bank += toAdd;
}

Player &Game::firstPlayer() {
    return players[0];
}

void Game::setFirstPart() {
    part = 1;
}

std::vector<Player> Game::getPlayersCopy() {
    return players;
}

void Game::setPlayingPlayers(std::vector<Player> toSet) {
    playingPlayers = std::deque<Player>(toSet.begin(), toSet.end());
}

Player &Game::firstPlayingPlayer() {
    return playingPlayers.at(0);
}

Player &Game::secondPlayingPlayer() {
    return playingPlayers.at(1);
}

void Game::setCurrent(Player &player) {
    current = &player;
}

void Game::setNext(Player &player) {
    next = &player;
}

std::vector<Card> &Game::getCardsRef() {
    return cards;
}

std::deque<Player> &Game::getPlayingPlayersRef() {
    return playingPlayers;
}

void Game::setBid(int toSet) {
    bid = toSet;
}

int Game::getBankValue() const {
    return bank;
}

std::vector<Player *> &Game::getWinnersRef() {
    return winners;
}

void Game::setBank(int toSet) {
    bank = toSet;
}

void Game::resetWinners() {
    winners = {};
}

int Game::getNumOfPlayingPlayers() {
    return (int) playingPlayers.size();
}

void Game::setLast(Player *player) {
    last = player;
}

std::deque<Player> Game::getPlayingPlayers() {
    return playingPlayers;
}

Player &Game::currentPlayer() {
    return *current;
}

Player &Game::lastPlayer() {
    return *last;
}

void Game::resetCards(std::vector<Card> cardsToSet) {
    cards = std::move(cardsToSet);
}

const Player &Game::playingPlayer(const std::string &playerName) {
    return *std::find_if(
            playingPlayers.begin(), playingPlayers.end(),
            [&playerName](const Player &player) { return player.getName() == playerName; }
    );
}

std::string Game::toString() const {
    std::string cardList;
    if (!cards.empty()) {
        cardList = "\ncards in deck=";
        cardList += std::accumulate(cards.begin(), cards.end(), std::string(),
                                    [](const std::string &acc, const Card &card) {
                                        return acc + (acc.empty() ? "" : ", ") + card.toString();
                                    });
    }

    return "maxNumOfPlayers=" + std::to_string(maxNumOfPlayers) +
           cardList +
           (!players.empty() ? "\nplayers=" + getPlayersNames() : "") +
           (!playingPlayers.empty() ? "\nplayingPlayers=\n" + getPlayingPlayerInfo() : "") +
           (!winners.empty() ? "\nwinners=" + getWinnersNames() : "") +
           (last != nullptr ? "\nlast=" + last->getName() : "") +
           (current != nullptr ? "\ncurrent=" + current->getName() : "") +
           (next != nullptr ? "\nnext=" + next->getName() : "") +
           "\nstarted=" + (started ? "true" : "false") +
           "\nallIn=" + (allIn ? "true" : "false") +
           "\nbid=" + std::to_string(bid) +
           "\nbank=" + std::to_string(bank) +
           "\npart=" + std::to_string(part);
}

std::string Game::getWinnersNames() const {
    std::string winnersNames;
    for (const auto &winner: winners) {
        winnersNames += winner->getName() + ", ";
    }
    return winnersNames;
}

std::string Game::getPlayersNames() const {
    std::string playersNames;
    for (const auto &player: players) {
        playersNames += player.getName() + ", ";
    }
    return playersNames;
}

std::string Game::getPlayingPlayerInfo() const {
    std::string playingPlayersInfo;
    for (const Player& player: playingPlayers) {
        playingPlayersInfo += player.toString() + "\n\n";
    }
    return  MessagePrinter::addIndentation(playingPlayersInfo, "\t");
}

bool Game::isInLobby(const std::string &playerName) {
    return std::find_if(
            players.begin(), players.end(),
            [&playerName](const Player &player) { return player.getName() == playerName; }
    ) != players.end();
}

int Game::getNumOfPlayers() {
    return (int) players.size();
}

int Game::getPart() const {
    return part;
}

void Game::removeFirstFromPlayingPlayers() {
    playingPlayers.pop_front();
}

void Game::setLastPlayer(Player &player) {
    last = &player;
}

void Game::addToPlayingPlayers(Player &player) {
    playingPlayers.push_back(player);
}

void Game::adjustPart() {
    part++;
}

bool Game::isAllIn() const {
    return allIn;
}

int Game::getBid() const {
    return bid;
}

void Game::setAllIn(bool toSet) {
    allIn = toSet;
}

Player &Game::getPlayer(const std::string &playerName) {
    return *std::find_if(
            players.begin(), players.end(),
            [&playerName](const Player &player) { return player.getName() == playerName; }
    );
}

void Game::setPlayerKicked(const std::string& playerName) {
    getPlayer(playerName).setKicked(true);
}
