#include "Hero.h"

Hero::Hero()
{
    //ctor
}

Hero::~Hero()
{
    //dtor
}

std::string Hero::GetHeroName()
{
  return hero_name;
}

void Hero::SetHeroName(std::string name1)
{
  hero_name = name1;
}

std::string Hero::GetHeroType()
{
  return herotype1;
}

void Hero::SetHeroType(std::string type1)
{
  herotype1 = type1;
}
