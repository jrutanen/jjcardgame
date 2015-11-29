#include "Player.h"

Player::Player()
{
  //ctor
  p_card_deck = new CardDeck();
  hit_points = 40;
  player_name = "Player 1";
  player_mana_points = 0;
  available_mana = 0;
  ai = false;
//  SetDeck(&card_deck);
}

Player::~Player()
{
    //dtor
    delete p_card_deck;
}

void Player::AddHitPoints(int points)
{
  hit_points = hit_points + points;
}

int Player::GetHitPoints()
{
  return hit_points;
}

void Player::ReduceHitPoints(int points)
{
  hit_points = hit_points - points;
}

void Player::SetName(std::string name)
{
  player_name = name;
}

std::string Player::GetName()
{
  return player_name;
}

void Player::SetDeck(CardDeck* p_deck)
{
  p_card_deck = p_deck;
}

void Player::ShuffleDeck()
{
  p_card_deck->Shuffle();
}

void Player::SetHero(Hero* p_hero)
{
  p_player_hero = p_hero;
}

void Player::DrawCard()
{
  Card* p_temp_card;
  p_temp_card = p_card_deck->GetCardOnTop();
  if(p_temp_card){
    cards_in_hand.push_back(p_temp_card);
  }
}

//else {
//    player_hand.AddCard(p_card_deck->GetCardOnTop());


std::vector<Card*> Player::ShowHand()
{
  return cards_in_hand;
 // return player_hand.ShowCards();
}

void Player::AddMana(int mana_points)
{
  player_mana_points += mana_points;
}

int Player::GetMana()
{
  return player_mana_points;
}

void Player::ReduceAvailableMana(int mana_points)
{
  available_mana -= mana_points;
}
void Player::AddAvailableMana(int mana_points)
{
  available_mana += mana_points;
}

int Player::GetAvailableMana()
{
  return available_mana;
}

int Player::GetCardsInHand()
{
  return cards_in_hand.size();
}

void Player::SetUpTurn()
{
  //add one mana point to the player mana points
  AddMana(1);
  available_mana = player_mana_points;
  // draw new card every turn
  DrawCard();
}

void Player::SetUpGame()
{
  //shuffle deck
  ShuffleDeck();

  //start hand contains 2 cards
  for (int i = 0; i < 2; ++i)
  {
    if(!p_card_deck->IsEmpty())
    {
      DrawCard();
    }
  }
}

Card* Player::PlayCard(int card_nbr)
{
  Card* played_card = cards_in_hand.at(card_nbr);
  cards_in_hand.erase(cards_in_hand.begin() + card_nbr);
  return played_card;
  }

Card* Player::CardInHand(int card_nbr)
{
  return cards_in_hand.at(card_nbr);
}


void Player::SetAi(bool setai)
{
 ai = setai;
}

