#include "Board.h"

Board::Board()
{
  //ctor
  //intialize vector with 5 slots for both players.
  std::vector<Card*> initial_vector;

  {
  //  initial_vector.push_back(nullptr);
  }
  cards_on_board.push_back(initial_vector);
  cards_on_board.push_back(initial_vector);

}

Board::~Board()
{
  //dtor
}

void Board::AddCardToPlayerOne(Card* p_card, int slot)
{
//  cards_on_board_player[0][slot] = p_card;
}

void Board::AddCardToPlayer(int player, Card* p_card, int slot)
{
  cards_on_board.at(player)[slot] = p_card;
}

void Board::AddCardToPlayer(int player, Card* p_card)
{
  cards_on_board.at(player).push_back(p_card);
}

std::vector<Card*> Board::GetCardsForPlayer(int player)
{
  return cards_on_board.at(player);
}

int Board::GetCardsOnBoard()
{
  return cards_on_board.size();
}
