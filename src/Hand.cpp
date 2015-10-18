#include "Hand.h"

Hand::Hand()
{
    //ctor
}

Hand::~Hand()
{
    //dtor
}

void Hand::AddCard(Card* p_card)
{
  cards_in_hand.push_back(p_card);
}

Card* Hand::PlayCard(Card* p_card)
{
  //search for the card in hand and remove it
  cards_in_hand.erase(std::remove(cards_in_hand.begin(), cards_in_hand.end(), p_card), cards_in_hand.end());
  //return card
  return p_card;
}

int Hand::GetNumberOfCards()
{
  return cards_in_hand.size();
}

std::vector<Card*> Hand::ShowCards()
{
  return cards_in_hand;
}
