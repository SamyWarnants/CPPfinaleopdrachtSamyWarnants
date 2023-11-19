// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "PlayerStrategy.h"

class Player {
private:
    std::vector<Card> hand;
    PlayerStrategy* strategy;

public:
    Player(PlayerStrategy* playerStrategy) : strategy(playerStrategy) {}

    void drawCard(Deck& deck);

    // Other member functions...

    void callUno();
    bool hasUno() const;
};

#endif
