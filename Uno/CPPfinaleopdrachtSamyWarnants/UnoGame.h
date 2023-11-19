// UnoGame.h
#ifndef UNO_GAME_H
#define UNO_GAME_H

#include "Deck.h"
#include "Player.h"

class UnoGame {
private:
    Deck deck;
    std::vector<Player> players;
    int currentPlayerIndex;

public:
    UnoGame(const std::vector<Player>& players);

    void playGame();
};

#endif
