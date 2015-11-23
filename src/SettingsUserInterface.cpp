#include "SettingsUserInterface.h"


void SettingsUserInterface::Start_user_interface()
{


    std::cout << "S-Start Game, Q-Quit\n";
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
  return response;
}

void SettingsUserInterface::StartMenuEvent(std::vector<char> event)
{

  if (event.size() > 0)
    {
    switch(event.at(0))
      {
        case '?' :
        {
        ui.DisplayHelp();
        break;
        }

       case 'S' :
        {
        GameEngine game;
        game.Run();
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

void SettingsUserInterface:Create_deck()
{

}
