#include "MonsterCard.h"

MonsterCard::MonsterCard()
{
    card_ability = "no text"; //ctor
}

MonsterCard::~MonsterCard()
{
    //dtor
}

//Get and Set functions
void MonsterCard::SetCardAttack(int setattack)
{
  card_attack = setattack;
}

int MonsterCard::GetCardAttack()
{
  return card_attack;
}

void MonsterCard::SetCardDefence(int setdefence)
{
  card_defence = setdefence;
}

int MonsterCard::GetCardDefence()
{
  return card_defence;
}

//Attack and Defence additions and reductions
void MonsterCard::AddAttack(int attack);
{
  card_attack = card_attack + attack;
}

void MonsterCard::ReduceAttack(int attack);
{
  card_attack = card_attack - attack;

void MonsterCard::AddDefence(int defence);
{
  card_defence = card_defence + defence;
}

void MonsterCard::ReduceDefence(int defence);
{
  card_defence = card_defence - defence;
}














