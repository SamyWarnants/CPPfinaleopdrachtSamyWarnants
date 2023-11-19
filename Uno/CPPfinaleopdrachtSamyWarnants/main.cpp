#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Card.h"
int main() {
    Deck deck;
    Player player1, player2, player3, player4;

    // Initial drawing of cards for players
    for (int i = 0; i < 8; ++i) {
        player1.drawCard(deck);
        player2.drawCard(deck);
        player3.drawCard(deck);
        player4.drawCard(deck);
    }

    // Display initial hands
    player1.displayHand();
    player2.displayHand();
    player3.displayHand();
    player4.displayHand();

    return 0;
}
