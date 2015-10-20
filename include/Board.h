#ifndef BOARD_H
#define BOARD_H
#include "JJCardGame.h"
#include <vector>
#include "Card.h"

class Board
{
  public:
    Board();
    virtual ~Board();
  protected:
  private:
      std::vector<Card> player_one_cards;
      void AddCardToPlayerOne(Card* card);
};

#endif // BOARD_H
