#define CARD_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

enum Color { RED, GREEN, BLUE, YELLOW };
enum Value { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, SKIP, REVERSE, DRAW_TWO, WILD, WILD_DRAW_FOUR };

class Card {
public:
    Color color;
    Value value;

    Card(Color col, Value val) : color(col), value(val) {}
};

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck() {
        initializeDeck();
        shuffleDeck();
    }

    void initializeDeck() {
        for (int i = RED; i <= YELLOW; ++i) {
            for (int j = ZERO; j <= WILD_DRAW_FOUR; ++j) {
                cards.push_back(Card(static_cast<Color>(i), static_cast<Value>(j)));
            }
        }
    }

    void shuffleDeck() {
        std::srand(static_cast<unsigned>(std::time(0)));
        std::random_shuffle(cards.begin(), cards.end());
    }

    Card drawCard() {
        if (!cards.empty()) {
            Card drawnCard = cards.back();
            cards.pop_back();
            return drawnCard;
        } else {
            std::cout << "Deck is empty!" << std::endl;
            // Handle reshuffling or end of the game logic here
            exit(EXIT_FAILURE);
        }
    }
};

class Player {
private:
    std::vector<Card> hand;

public:
    void drawCard(Deck& deck) {
        hand.push_back(deck.drawCard());
    }

    void displayHand() const {
        std::cout << "Player's Hand:" << std::endl;
        for (const auto& card : hand) {
            std::cout << "Color: " << card.color << ", Value: " << card.value << std::endl;
        }
        std::cout << std::endl;
    }
};
