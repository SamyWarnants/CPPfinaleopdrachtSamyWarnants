// PlayerStrategy.h
#ifndef PLAYER_STRATEGY_H
#define PLAYER_STRATEGY_H

class Deck; // Forward declaration

class PlayerStrategy {
public:
    virtual void playTurn(Deck& deck, Player& currentPlayer, Player& nextPlayer) = 0;
};

class HumanPlayerStrategy : public PlayerStrategy {
public:
    void playTurn(Deck& deck, Player& currentPlayer, Player& nextPlayer) override;
};

class ComputerPlayerStrategy : public PlayerStrategy {
public:
    void playTurn(Deck& deck, Player& currentPlayer, Player& nextPlayer) override;
};

#endif
