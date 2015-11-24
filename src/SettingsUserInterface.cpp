#include "SettingsUserInterface.h"

SettingsUserInterface::SettingsUserInterface()
{
  die = false;//ctor
  p_player1 = new Player();
  p_player2 = new Player();
  p_player1->SetName("Jani");
  p_player2->SetName("Janne");
  //add to the players vector
  players.push_back(p_player1);
  players.push_back(p_player2);
}

SettingsUserInterface::~SettingsUserInterface()
{
  //dtor
  delete p_player1;
  delete p_player2;
}

void SettingsUserInterface::Clear()
{
  //Never use system, unsafe and resource hungry!!!!
  std::system("CLS");
}

void SettingsUserInterface::StartUserInterface()
{
  while(!die)
  {
    Clear();
    std::vector<char> response;
    std::string input;
    std::cout << "|==============================================|\n";
    std::cout << "S-Start Game\n";
    std::cout << "Q-Quit\n";
    std::cout << "C-Change player names\n";
    std::cout << "  Give your command: ";
    while (getline(std::cin, input) && input.empty())
    {
        std::cout << "\n  Please give a command.\n"
                  << "  Give your command: ";
    }

    for(char& c : input)
    {
    if (!isspace(c))
      {
      response.push_back(c);
      }
    }
 StartMenuEvent(response);
  }
}

void SettingsUserInterface::StartMenuEvent(std::vector<char> event)
{

  if (event.size() > 0)
    {
    switch(event.at(0))
      {
        case '?' :
        {
        //ui.DisplayHelp();
        break;
        }

        case 'S' :
        {
        GameEngine* p_game = new GameEngine(p_player1, p_player2);
        p_game->Run();
        break;
        }

       case 'C' : //Change player names
       {
       std::string name;
       getline(std::cin, name);
       p_player1->SetName(name);
       std::cout << "New name for " << name << " is " << std::endl;
       break;
       }

        case 'Q' :
        {
        die = true;
        break;
        }
      }
    }
}
void SettingsUserInterface::Start_game()
{
    GameEngine game;
    game.Run();
}

void SettingsUserInterface::Create_deck()
{

}
