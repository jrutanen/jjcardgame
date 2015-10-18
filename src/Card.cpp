#include "Card.h"

Card::Card()
{
    //ctor
}

Card::~Card()
{
    //dtor
}

std::string Card::GetName()
{
  return card_name;
}

void Card::SetName(std::string name)
{
  card_name = name;
}
