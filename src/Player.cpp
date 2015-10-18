#include "Player.h"

Player::Player()
{
  //ctor
  hit_points = 40;
  player_name = "Player 1";
  player_mana_points = 0;
  available_mana = 0;
}

Player::~Player()
{
    //dtor
}

void Player::AddHitPoints(int points)
{
  hit_points = hit_points + points;
}

int Player::GetHitPoints()
{
  return hit_points;
}

void Player::ReduceHitPoint(int points)
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

void Player::SetHero(Hero* p_hero)
{
  p_player_hero = p_hero;
}
std::vector<Card> Player::ShowHand()
{
  std::vector<Card> vectori;
  return vectori;
}

void Player::DrawCard()
{

}

void Player::AddMana(int mana_points)
{
  player_mana_points += mana_points;
}

void Player::ReduceAvailableMana(int mana_points)
{
  available_mana -= mana_points;
}

void Player::SetUpTurn()
{
  //add one mana point to the player mana points
  AddMana(1);
}

void Player::SetUpGame()
{
  //start hand contains 2 cards

}
