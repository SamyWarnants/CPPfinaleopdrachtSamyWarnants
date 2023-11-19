// Deck.h
#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck();

    void initializeDeck();
    void shuffleDeck();
    Card drawCard();

    // Other member functions...
};

#endif
