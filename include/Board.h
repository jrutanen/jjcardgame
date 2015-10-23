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
    void AddCardToPlayerOne(Card* card, int slot);
  protected:
  private:
      Card* cards_on_board_player[2][5];
      std::vector<Card> player_one_cards;
      std::vector<Card*> cards_in_board_own;
      std::vector<Card*> cards_in_board_opp;
      std::vector<Card*> cards_in_graveyard_own;
      std::vector<Card*> cards_in_graveyard_opp;
};

#endif // BOARD_H
