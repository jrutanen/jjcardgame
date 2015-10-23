#include "Board.h"

Board::Board()
{
  //ctor
  for (int i = 0; i < 2; ++i)
  {
    for (int j = 0; j < 6; ++i)
    {
      cards_on_board_player[i][j] = 0;
    }
  }
}

Board::~Board()
{
  //dtor
}

void Board::AddCardToPlayerOne(Card* p_card, int slot)
{
  cards_on_board_player[0][slot] = p_card;
}
