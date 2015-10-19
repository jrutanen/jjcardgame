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
        Player player2;
        void InitDeck(CardDeck* card_deck);
//        void InitDeck(Player* player);
        void InitPlayer(Player* player, CardDeck* card_deck);
        CardDeck card_deck1;
        CardDeck card_deck2;
        Card card_one;
        Card card_two;
        Card card_three;
        Card card_four;
        Card card_five;
};

#endif // GAMEENGINE_H
