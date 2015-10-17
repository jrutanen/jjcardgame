#include "Player.h"

Player::Player()
{
  hit_points = 40;//ctor
  player_name = "Player 1";
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







