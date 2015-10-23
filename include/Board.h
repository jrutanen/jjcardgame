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
      std::vector<Card*> cards_in_board_own;
      std::vector<Card*> cards_in_board_opp;
      std::vector<Card*> cards_in_graveyard_own;
      std::vector<Card*> cards_in_graveyard_opp;
};

#endif // BOARD_H
