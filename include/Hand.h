#ifndef HAND_H
#define HAND_H
#include <vector>
#include <algorithm>
#include "Card.h"


class Hand
{
    public:
        Hand();
        virtual ~Hand();
        void AddCard(Card* p_card);
        Card* PlayCard(Card* p_card);
        std::vector<Card*> ShowCards();
        int GetNumberOfCards();
    protected:
    private:
      std::vector<Card*> cards_in_hand;
};

#endif // HAND_H
