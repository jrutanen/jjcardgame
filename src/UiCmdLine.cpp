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

std::vector<char> UiCmdLine::DrawBoard(Player* p1, Player* p2, Board* board, int active_player)
{
  Clear();
  std::vector<char> response;
  std::string input;
  std::cout << "|==============================================|\n";
  if (active_player == 0)
  {
    std::cout << " *" << p1->GetName() << "\tHP: " << p1->GetHitPoints() << "\tMana: "
              << p1->GetAvailableMana() << "(" << p1->GetMana() << ")\n";
  }
  else
  {
    std::cout << "  " << p1->GetName() << "\tHP: " << p1->GetHitPoints() << "\tMana: "
              << p1->GetAvailableMana() << "(" << p1->GetMana() << ")\n";
  }
  std::cout << "  Graveyard: " << GraveyardToString(board->ShowGraveyard(0)) << "\n";
  std::cout << "  Hand: " << HandToString(p1->ShowHand()) << "\n";
  std::cout << "\n";
  std::cout << " Board: " << HandToString(board->GetCardsForPlayer(0)) << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << " Board: " << HandToString(board->GetCardsForPlayer(1)) << "\n";
  std::cout << "\n";
  std::cout << "  Hand: " << HandToString(p2->ShowHand()) << "\n";
  std::cout << "  Graveyard: " << GraveyardToString(board->ShowGraveyard(1)) << "\n";
  if (active_player == 1)
  {
    std::cout << " *" << p2->GetName() << "\tHP: " << p2->GetHitPoints() << "\tMana: "
              << p2->GetAvailableMana() <<"(" << p2->GetMana() << ")\n";
  }
  else
  {
    std::cout << "  " << p2->GetName() << "\tHP: " << p2->GetHitPoints() << "\tMana: "
              << p2->GetAvailableMana() <<"(" << p2->GetMana() << ")\n";
  }
  std::cout << "|==============================================|\n";
  std::cout << "  P x-Play Card x\n";
  std::cout << "  A x y -Attack Card x with y, Attack opponent with O\n";
  std::cout << "  R-End turn, Q-Quit\n";
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
    std::ostringstream aa;
    std::ostringstream dd;
    std::ostringstream active;
    ss << (i);
    if(hand.at(i) != nullptr)
    {
      hand_str += ss.str() + ":" + hand.at(i)->GetCardName() + " (";
      bb << (hand.at(i)->GetCastingCost());
      aa << (hand.at(i)->GetCardAttack());
      dd << (hand.at(i)->GetCardDefence());
      hand_str += bb.str() + ")" + aa.str() + "/" + dd.str();
      if (hand.at(i)->IsReady())
      {
        active << "*";
      }
      else
      {
        active << "";
      }
      hand_str += active.str();
      if (i < hand.size()-1)
      {
        hand_str += ", ";
      }
    }
  }
  return hand_str;
}

std::string UiCmdLine::GraveyardToString(std::vector<Card*> graveyard)
{
  std::string graveyard_str = "";

  for (uint i = 0; i < graveyard.size(); ++i)
  {
    std::ostringstream ss;
    std::ostringstream bb;
    std::ostringstream aa;
    std::ostringstream dd;
    ss << (i);
    if(graveyard.at(i) != nullptr)
    {
      graveyard_str += ss.str() + ":" + graveyard.at(i)->GetCardName();
      if (i < graveyard.size()-1)
      {
        graveyard_str += ", ";
      }
    }
  }
  return graveyard_str;
}
void UiCmdLine::AiLogic()
{
//Ai.UiEvent('P');
}
