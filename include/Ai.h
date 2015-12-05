#ifndef AI_H
#define AI_H
#include "Player.h"
#include "JJCardGame.h"
#include "Board.h"

class Ai
{
  public:
      Ai();
      virtual ~Ai();
      //std::vector<char> EvaluatePlay(Board* board, std::vector<Card*> cards);
      std::vector<char> EvaluatePlay(std::vector<Card*> p1_cards, std::vector<Card*> p2_cards, std::vector<Card*> p2_cardsinhand);
  private:
      char ai_command;


};

#endif // AI_H_INCLUDED
