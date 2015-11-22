#include "Card.h"

Card::Card()
{
 card_class = "basic";
 card_text = "default text";//ctor
 DeActivate();
}

Card::~Card()
{
    //dtor
}

std::string Card::GetCardName()
{
  return card_name;
}

void Card::SetCardName(std::string name1)
{
  card_name = name1;
}

std::string Card::GetCardType()
{
  return card_type;
}

void Card::SetCardType(std::string type1)
{
  card_type = type1;
}

void Card::SetCastingCost(int cost)
{
  casting_cost = cost;
}

int Card::GetCastingCost()
{
  return casting_cost;
}

//This is copy paste from Monstercard

//Get and Set functions
void Card::SetCardAttack(int setattack)
{
  card_attack = setattack;
}

int Card::GetCardAttack()
{
  return card_attack;
}

void Card::SetCardDefence(int setdefence)
{
  card_defence = setdefence;
}

int Card::GetCardDefence()
{
  return card_defence;
}

//Attack and Defence additions and reductions
void Card::AddAttack(int attack)
{
  card_attack = card_attack + attack;
}

void Card::ReduceAttack(int attack)
{
  card_attack = card_attack - attack;
}
void Card::AddDefence(int defence)
{
  card_defence = card_defence + defence;
}

void Card::ReduceDefence(int defence)
{
  card_defence = card_defence - defence;
}

bool Card::IsReady()
{
  return playable;
}

void Card::Activate()
{
  playable = true;
}

void Card::DeActivate()
{
  playable = false;
}
//End copy paste
