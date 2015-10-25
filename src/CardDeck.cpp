#include "CardDeck.h"

CardDeck::CardDeck()
{
  //ctor
  //Initialize card vector with five cards for test purposes
  card_one.SetCardName("Mummy");
  card_one.SetCastingCost(1);
  AddCard(&card_one);
  card_two.SetCardName("Vampire");
  card_two.SetCastingCost(2);
  AddCard(&card_two);
  card_three.SetCardName("Werewolf");
  card_three.SetCastingCost(1);
  AddCard(&card_three);
  card_four.SetCardName("Cthulhu");
  card_four.SetCastingCost(9);
  AddCard(&card_four);
  card_five.SetCardName("Mummy");
  card_five.SetCastingCost(1);
  AddCard(&card_five);
  card_six.SetCardName("Mummy");
  card_six.SetCastingCost(1);
  AddCard(&card_six);
  card_seven.SetCardName("Werewolf");
  card_seven.SetCastingCost(1);
  AddCard(&card_seven);
  card_eight.SetCardName("Rat");
  card_eight.SetCastingCost(1);
  AddCard(&card_eight);
  card_nine.SetCardName("Mummy");
  card_nine.SetCastingCost(1);
  AddCard(&card_nine);
  card_ten.SetCardName("Ghoul");
  card_ten.SetCastingCost(3);
  AddCard(&card_ten);
  card_eleven.SetCardName("Vampire");
  card_eleven.SetCastingCost(2);
  AddCard(&card_eleven);
  card_twelve.SetCardName("Ghoul");
  card_twelve.SetCastingCost(3);
  AddCard(&card_twelve);
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
