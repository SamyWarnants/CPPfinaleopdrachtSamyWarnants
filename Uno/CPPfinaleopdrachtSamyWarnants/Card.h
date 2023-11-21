#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

// Enumeration for card values, providing meaningful names.
enum Value {
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, SKIP, REVERSE, DRAW_TWO, CHOOSE_COLOR, P4};

// Enumeration for card colors, providing meaningful names.
enum Color { RED, GREEN, BLUE, YELLOW, BLACK };

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
        switch (value) {
        case ZERO:
            std::cout << "0";
            break;
        case ONE:
            std::cout << "1";
            break;
        case TWO:
            std::cout << "2";
            break;
        case THREE:
            std::cout << "3";
            break;
        case FOUR:
            std::cout << "4";
            break;
        case FIVE:
            std::cout << "5";
            break;
        case SIX:
            std::cout << "6";
            break;
        case SEVEN:
            std::cout << "7";
            break;
        case EIGHT:
            std::cout << "8";
            break;
        case NINE:
            std::cout << "9";
            break;
        case SKIP:
            std::cout << "SKIP";
            break;
        case REVERSE:
            std::cout << "REVERSE";
            break;
        case DRAW_TWO:
            std::cout << "DRAW_TWO";
            break;
        case CHOOSE_COLOR:
            std::cout << "CHOOSE_COLOR";
            break;
        case P4:
            std::cout << "P4";
            break;
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
            for (int j = ZERO; j <= P4; ++j) {
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
                case BLACK:
                    colorName = "BLACK";
                    break;
                }
                cards.push_back(Card((j == CHOOSE_COLOR || j == P4) ? "BLACK" : colorName, static_cast<Value>(j)));
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
        // Player initialization to be added
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
        for (int round = 0; round < 10; ++round) {  // Adjust the number of rounds as needed
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
        // Implement Uno game logic will be here
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
/*
class SpecialActionCard {
public:
    virtual void performAction(Player& currentPlayer, UnoGame& unoGame) = 0;
    virtual ~SpecialActionCard() = default;
};

class ReverseCard : public SpecialActionCard {
public:
    void performAction(Player& currentPlayer, UnoGame& unoGame) override {}
};

class SkipCard : public SpecialActionCard {
public:
    void performAction(Player& currentPlayer, UnoGame& unoGame) override {}
};

class DrawTwoCard : public SpecialActionCard {
public:
    void performAction(Player& currentPlayer, UnoGame& unoGame) override {}
};

class UnoGame {
private:
    std::vector<std::unique_ptr<SpecialActionCard>> specialActionCards;

public:
    UnoGame() {
        initializeSpecialActionCards();
    }

    void playSpecialActionCard(Player& currentPlayer) {
        if (!specialActionCards.empty()) {
            int randomIndex = rand() % specialActionCards.size();
            specialActionCards[randomIndex]->performAction(currentPlayer, *this);
        }
    }

private:
    void initializeSpecialActionCards() {
        specialActionCards.push_back(std::make_unique<ReverseCard>());
        specialActionCards.push_back(std::make_unique<SkipCard>());
        specialActionCards.push_back(std::make_unique<DrawTwoCard>());
    }
};
*/
#endif // CARD_H
