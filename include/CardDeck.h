#ifndef CARDDECK_H
#define CARDDECK_H
#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include "Card.h"
#include "JJCardGame.h"


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
        int GetCardDeckId();
        void SetCardDeckId(int id);
        bool IsEmpty();
//        void RemoveCard(Card* p_card);
    protected:
    private:
        std::vector<Card*> cards;
        int card_deck_id;
        Card card_one;
        Card card_two;
        Card card_three;
        Card card_four;
        Card card_five;
        Card card_six;
        Card card_seven;
        Card card_eight;
        Card card_nine;
        Card card_ten;
        Card card_eleven;
        Card card_twelve;
};

#endif // CARDDECK_H
