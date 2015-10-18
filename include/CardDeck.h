#ifndef CARDDECK_H
#define CARDDECK_H
#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include "Card.h"

//for testing
#include <string>
#include <sstream>


class CardDeck
{
    public:
        CardDeck();
        virtual ~CardDeck();
        void AddCard(Card* p_card);
        void Shuffle();
        Card* GetCardOnTop();
        Card* GetCardOnBottom();
        bool IsEmpty();
//        void RemoveCard(Card* p_card);
    protected:
    private:
        std::vector<Card*> cards;

};

#endif // CARDDECK_H
