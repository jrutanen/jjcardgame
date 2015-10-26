#ifndef UICMDLINE_H
#define UICMDLINE_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include<sstream>
#include "Card.h"
#include "Player.h"
#include "Board.h"


class UiCmdLine
{
  public:
    UiCmdLine();
    virtual ~UiCmdLine();
    void DrawBoard();
    std::vector<char> DrawBoard(int p1_hp, int p1_mana, std::vector<Card*> p1_hand, int p2_hp, int p2_mana, std::vector<Card*> p2_hand );
    std::vector<char> DrawBoard(Player* p1, Player* p2, Board* board, int active_player);
    void DisplayHelp();
  protected:
  private:
    void Clear();
    std::string HandToString(std::vector<Card*> hand);
};
#endif // UICMDLINE_H
