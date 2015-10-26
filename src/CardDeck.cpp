#include "CardDeck.h"

CardDeck::CardDeck()
{
  //ctor
  //Initialize card vector with five cards for test purposes
  p_card_one = new Card();
  p_card_one->SetCardName("Mummy");
  p_card_one->SetCastingCost(1);
  AddCard(p_card_one);
  p_card_two = new Card();
  p_card_two->SetCardName("Vampire");
  p_card_two->SetCastingCost(2);
  AddCard(p_card_two);
  p_card_three = new Card();
  p_card_three->SetCardName("Werewolf");
  p_card_three->SetCastingCost(1);
  AddCard(p_card_three);
  p_card_four = new Card();
  p_card_four->SetCardName("Cthulhu");
  p_card_four->SetCastingCost(9);
  AddCard(p_card_four);
  p_card_five= new Card();
  p_card_five->SetCardName("Mummy");
  p_card_five->SetCastingCost(1);
  AddCard(p_card_five);
/*  p_card_six.SetCardName("Mummy");
  p_card_six.SetCastingCost(1);
  AddCard(p_card_six);
  p_card_seven.SetCardName("Werewolf");
  p_card_seven.SetCastingCost(1);
  AddCard(p_card_seven);
  p_card_eight.SetCardName("Rat");
  p_card_eight.SetCastingCost(1);
  AddCard(p_card_eight);
  p_card_nine.SetCardName("Mummy");
  p_card_nine.SetCastingCost(1);
  AddCard(p_card_nine);
  p_card_ten.SetCardName("Ghoul");
  p_card_ten.SetCastingCost(3);
  AddCard(p_card_ten);
  p_card_eleven.SetCardName("Vampire");
  p_card_eleven.SetCastingCost(2);
  AddCard(p_card_eleven);
  p_card_twelve.SetCardName("Ghoul");
  p_card_twelve.SetCastingCost(3);
  AddCard(p_card_twelve);
*/
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
