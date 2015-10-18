#include "CardDeck.h"

CardDeck::CardDeck()
{
  //ctor
  //Initialize card vector with five cards for test purposes
}

CardDeck::~CardDeck()
{
  //dtor
}

void CardDeck::AddCard(Card* p_new_card)
{
  cards.push_back(p_new_card);
}

void CardDeck::Shuffle()
{
  std::vector<Card*> shuffled_deck;
  std::vector<Card*> temp_deck;
  temp_deck = cards;
  int card_pos = -1;

  // seed the random number generator
  std::mt19937 eng(time(0));

//  int iterations = temp_deck.size();

  for(int i = 0; i < cards.size(); ++i)
  {
    //if there is more than one card to select from
    if (temp_deck.size() > 1)
    {
      // define the range
      std::uniform_int_distribution<> distr(0, temp_deck.size() - 1);
      //generate random number at assign it to card_pos
      card_pos = distr(eng);
      shuffled_deck.push_back(temp_deck.at(card_pos));
      temp_deck.erase(temp_deck.begin() + card_pos);
    }
    else
    {
      shuffled_deck.push_back(temp_deck.front());
    }
  }
  cards = shuffled_deck;
}

Card* CardDeck::GetCardOnTop()
{
  if (cards.size() > 0)
  {
    Card* first_card = cards.front();
    cards.erase(cards.begin());
    return first_card;
  }
  return nullptr;
}

Card* CardDeck::GetCardOnBottom()
{
  if (cards.size() > 0)
  {
    Card* last_card = cards.back();
    cards.pop_back();
    return last_card;
  }
  return nullptr;
}
