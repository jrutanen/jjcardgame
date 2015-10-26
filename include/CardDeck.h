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
        Card* p_card_one;
        Card* p_card_two;
        Card* p_card_three;
        Card* p_card_four;
        Card* p_card_five;
        Card* p_card_six;
        Card* p_card_seven;
        Card* p_card_eight;
        Card* p_card_nine;
        Card* p_card_ten;
        Card* p_card_eleven;
        Card* p_card_twelve;
};

#endif // CARDDECK_H
