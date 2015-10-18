#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Player.h"
#include "CardDeck.h"
#include <iostream>

class GameEngine
{
    public:
        GameEngine();
        virtual ~GameEngine();
        void Run();
    protected:
    private:
        void GameLoop();
        Player player1;
        void InitDeck();
        void InitPlayer();
        CardDeck card_deck;
        Card card_one;
        Card card_two;
        Card card_three;
        Card card_four;
        Card card_five;
};

#endif // GAMEENGINE_H
