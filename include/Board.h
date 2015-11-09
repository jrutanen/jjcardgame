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
    void AddCardToPlayer(int player, Card* p_card, int slot);
    void AddCardToPlayer(int player, Card* p_card);
    std::vector<Card*> GetCardsForPlayer(int player);
    int GetCardsOnBoard();
  protected:
  private:
      Card* cards_on_board_player[2][5];
      std::vector<Card> player_one_cards;
      std::vector<Card*> cards_in_board_own;
      std::vector<Card*> cards_in_board_opp;
      std::vector<Card*> cards_in_graveyard_own;
      std::vector<Card*> cards_in_graveyard_opp;
      std::vector<std::vector<Card*>> cards_on_board;
};

#endif // BOARD_H
