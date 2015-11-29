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
    //Clear();
    std::vector<char> response;
    std::string input;
    std::cout << "|==============================================|\n";
    std::cout << "Welcome to jjcardgame!\n";
    std::cout << "|==============================================|\n";
    std::cout << "S-Start Singleplayer Game\n";
    std::cout << "M-Start Multiplayer Game\n";
    std::cout << "H-Select Hero, HX\n";
    std::cout << "   N-Necromancer\n";
    std::cout << "   J-Jedi\n";
    std::cout << "C-Change player name\n";
    std::cout << "Q-Quit\n";
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
        case 'H' :
        {
        if (event.size() > 1)
          {
          Hero hero1;
          std::cout << "Select N-Necromancer or J-Jedi \n";

            if (event.at(1) == 'N') //Necromancer
            {
            hero1.SetHeroType("Necromancer");
            std::cout << "You have selected Necromancer\n";
            }
            else if (event.at(1) == 'J') //Jedi
            {
            hero1.SetHeroType("Jedi");
            std::cout << "You have selected Jedi\n";
            }
            else
            {
            hero1.SetHeroType("Necromancer"); //Not valid hero type
            }
            break;
          }
        }

        case 'S' : //Start Singleplayer Game
        {
        p_player2->SetAi(true); //
        GameEngine* p_game = new GameEngine(p_player1, p_player2);
        p_game->Run();
        break;
        }

        case 'M' : //Start Multiplayer Game
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
