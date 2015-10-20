#include "CardDeck.h"

CardDeck::CardDeck()
{
  //ctor
  //Initialize card vector with five cards for test purposes
  card_one.SetCardName("Card One");
  AddCard(&card_one);
  card_two.SetCardName("Card Two");
  AddCard(&card_two);
  card_three.SetCardName("Card Three");
  AddCard(&card_three);
  card_four.SetCardName("Card Four");
  AddCard(&card_four);
  card_five.SetCardName("Card Five");
  AddCard(&card_five);
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

  for(uint i = 0; i < cards.size(); ++i)
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
  if (!IsEmpty())
  {
    Card* p_first_card = cards.front();
    cards.erase(cards.begin());
    return p_first_card;
  }
  return nullptr;
}

int CardDeck::GetCardDeckId()
{
  return card_deck_id;
}

void CardDeck::SetCardDeckId(int id)
{
  card_deck_id = id;
}


bool CardDeck::IsEmpty()
{
  bool is_empty = false;

  if (cards.size() < 1)
  {
    is_empty = true;
  }
  return is_empty;
}

Card* CardDeck::GetCardOnBottom()
{
  if (!IsEmpty())
  {
    Card* last_card = cards.back();
    cards.pop_back();
    return last_card;
  }
  return nullptr;
}
