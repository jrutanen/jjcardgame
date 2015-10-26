#include "UiCmdLine.h"

UiCmdLine::UiCmdLine()
{
  //ctor
}

UiCmdLine::~UiCmdLine()
{
  //dtor
}

void UiCmdLine::DrawBoard()
{


}

std::vector<char> UiCmdLine::DrawBoard(int p1_hp, int p1_mana, std::vector<Card*> p1_hand, int p2_hp, int p2_mana, std::vector<Card*> p2_hand )
{
  Clear();
  std::vector<char> response;
  std::string input;
  std::cout << "|==============================================|\n";
  std::cout << "  Player 1\tHP: " << p1_hp << "\tMana: " << p1_mana << "\n";
  std::cout << "  Graveyard:\n";
  std::cout << "  Hand: " << HandToString(p1_hand) << "\n";
  std::cout << "\n";
  std::cout << "Board: " /*<< BoardToString(p1_board)*/<< "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "Board: " /*<< BoardToString(p2_board)*/<< "\n";
  std::cout << "\n";
  std::cout << "  Hand: " << HandToString(p2_hand) << "\n";
  std::cout << "  Graveyard:\n";
  std::cout << "  Player 2\tHP: " << p2_hp << "\tMana: " << p2_mana << "\n";
  std::cout << "|==============================================|\n";
  std::cout << "  P x-Play Card x, A x-Attack Card x, R-End turn, Q-Quit\n";
  std::cout << "  Give your command: ";
  while (getline(std::cin, input) && input.empty()) {
        std::cout << "\n  Please give a command.\n"
                  << "  Give your command: ";
  }

  for(char& c : input) {
    if (!isspace(c))
    {
      response.push_back(c);
    }
  }
  return response;
}

std::vector<char> UiCmdLine::DrawBoard(Player* p1, Player* p2, Board* board, int active_player)
{
  Clear();
  std::vector<char> response;
  std::string input;
  std::cout << "|==============================================|\n";
  if (active_player == 0)
  {
    std::cout << " *" << p1->GetName() << "\tHP: " << p1->GetHitPoints() << "\tMana: " << p1->GetMana() << "\n";
  }
  else
  {
    std::cout << "  " << p1->GetName() << "\tHP: " << p1->GetHitPoints() << "\tMana: " << p1->GetMana() << "\n";
  }
  std::cout << "  Graveyard:\n";
  std::cout << "  Hand: " << HandToString(p1->ShowHand()) << "\n";
  std::cout << "\n";
  std::cout << " Board: " << HandToString(board->GetCardsForPlayer(0)) << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << " Board: " << HandToString(board->GetCardsForPlayer(1)) << "\n";
  std::cout << "\n";
  std::cout << "  Hand: " << HandToString(p2->ShowHand()) << "\n";
  std::cout << "  Graveyard:\n";
  if (active_player == 1)
  {
    std::cout << " *" << p2->GetName() << "\tHP: " << p2->GetHitPoints() << "\tMana: " << p2->GetMana() << "\n";
  }
  else
  {
    std::cout << "  " << p2->GetName() << "\tHP: " << p2->GetHitPoints() << "\tMana: " << p2->GetMana() << "\n";
  }
  std::cout << "|==============================================|\n";
  std::cout << "  P x-Play Card x, A x y -Attack Card x with y, R-End turn, Q-Quit\n";
  std::cout << "  Give your command: ";
  while (getline(std::cin, input) && input.empty()) {
        std::cout << "\n  Please give a command.\n"
                  << "  Give your command: ";
  }

  for(char& c : input) {
    if (!isspace(c))
    {
      response.push_back(c);
    }
  }
  return response;
}

void UiCmdLine::Clear()
{
  //Never use system, unsafe and resource hungry!!!!
  std::system("CLS");
}

void UiCmdLine::DisplayHelp()
{
  Clear();
  std::string go_back;
  std::cout << "You can use following commands:\n";
  std::cout << "A nbr\tAttack card nbr\n";
  std::cout << "R\tReady, end turn\n";
  std::cout << "Q\tQuit game\n";
  std::cout << "Go back to game (y/n): ";
  std::cin >> go_back;
}

std::string UiCmdLine::HandToString(std::vector<Card*> hand)
{
  std::string hand_str = "";

  for (uint i = 0; i < hand.size(); ++i)
  {
    std::ostringstream ss;
    std::ostringstream bb;
    ss << (i + 1);
    if(hand.at(i) != nullptr)
    {
      hand_str += ss.str() + ":" + hand.at(i)->GetCardName() + " (";
      bb << (hand.at(i)->GetCastingCost());
      hand_str += bb.str() + ")";
      if (i < hand.size()-1)
      {
        hand_str += ", ";
      }
    }
  }
  return hand_str;
}

