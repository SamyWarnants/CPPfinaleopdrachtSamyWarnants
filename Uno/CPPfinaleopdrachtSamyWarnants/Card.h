#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

// Enumeration for card colors and values, providing meaningful names.
enum Color { RED, GREEN, BLUE, YELLOW };
enum Value { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, SKIP, REVERSE, DRAW_TWO, WILD, WILD_DRAW_FOUR };

// Card class representing a playing card with color and value.
class Card {
public:
    std::string color;
    Value value;

    // Constructor initializes the card with specified color and value.
    Card(std::string col, Value val) : color(col), value(val) {}

    // Function to display the card.
    void displayCard() const {
        std::cout << "Color: " << color << ", Value: ";
        if (value <= NINE) {
            std::cout << value;
        } else {
            switch (value) {
            case SKIP:
                std::cout << "SKIP";
                break;
            case REVERSE:
                std::cout << "REVERSE";
                break;
            case DRAW_TWO:
                std::cout << "DRAW_TWO";
                break;
            case WILD:
                std::cout << "WILD";
                break;
            case WILD_DRAW_FOUR:
                std::cout << "WILD_DRAW_FOUR";
                break;
            }
        }
        std::cout << std::endl;
    }
};

// Deck class representing a deck of cards.
class Deck {
private:
    std::vector<Card> cards;

public:
    Deck() {
        initializeDeck();
        shuffleDeck();
    }

    // Function to initialize the deck with all possible cards.
    void initializeDeck() {
        for (int i = RED; i <= YELLOW; ++i) {
            for (int j = ZERO; j <= WILD_DRAW_FOUR; ++j) {
                std::string colorName;
                switch (i) {
                case RED:
                    colorName = "RED";
                    break;
                case GREEN:
                    colorName = "GREEN";
                    break;
                case BLUE:
                    colorName = "BLUE";
                    break;
                case YELLOW:
                    colorName = "YELLOW";
                    break;
                }
                cards.push_back(Card(colorName, static_cast<Value>(j)));
            }
        }
    }

    // Function to shuffle the deck.
    void shuffleDeck() {
        std::srand(static_cast<unsigned>(std::time(0)));
        std::random_shuffle(cards.begin(), cards.end());
    }

    // Function to draw a card from the deck.
    Card drawCard() {
        if (!cards.empty()) {
            Card drawnCard = cards.back();
            cards.pop_back();
            return drawnCard;
        } else {
            std::cout << "Deck is empty!" << std::endl;
            // Handle reshuffling or end-of-the-game logic here
            exit(EXIT_FAILURE);
        }
    }
};

// Player class representing a player in the game.
class Player {
private:
    std::vector<Card> hand;

public:
    Player() {
        // Player initialization if needed
    }

    // Function to draw a card from the deck and add it to the player's hand.
    void drawCard(Deck& deck) {
        hand.push_back(deck.drawCard());
    }

    // Function to set the player's hand.
    void setHand(const std::vector<Card>& newHand) {
        hand = newHand;
    }

    // Function to display the player's hand.
    void displayHand() const {
        std::cout << "Player's Hand:" << std::endl;
        for (const auto& card : hand) {
            card.displayCard();
        }
        std::cout << std::endl;
    }

    // Function to get the player's hand.
    const std::vector<Card>& getHand() const {
        return hand;
    }
};

// UnoGame class representing the Uno game.
class UnoGame {
public:
    UnoGame() {
        initializePlayers();
        dealInitialCards();
    }

    // Function to play the Uno game.
    void playGame() {
        std::cout << "Starting Uno Game!" << std::endl;

        // Game loop
        for (int round = 0; round < 40; ++round) {  // Adjust the number of rounds as needed
            playRound();
            displayPlayerHands();
            // Check game-ending conditions and break the loop if needed
        }

        std::cout << "Game Over!" << std::endl;
    }

private:
    Deck unoDeck;
    std::vector<Player> players;

    // Function to initialize players.
    void initializePlayers() {
        for (int i = 0; i < 4; ++i) {
            players.push_back(Player());
        }
    }

    // Function to deal initial cards to players.
    void dealInitialCards() {
        for (auto& player : players) {
            std::vector<Card> initialHand;
            for (int i = 0; i < 7; ++i) {
                initialHand.push_back(unoDeck.drawCard());
            }
            player.setHand(initialHand);
        }
    }

    // Function to play a round of the Uno game.
    void playRound() {
        // Implement Uno game logic here
        // For example: players taking turns, playing cards, drawing cards, etc.
        for (auto& player : players) {
            const Card playedCard = player.getHand()[0];  // Use Card instead of const Card*
            // Implement Uno game logic with the played card
        }
    }

    // Function to display player hands.
    void displayPlayerHands() const {
        for (const auto& player : players) {
            player.displayHand();
        }
    }
};

#endif // CARD_H
