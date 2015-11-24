#ifndef SETTINGSUSERINTERFACE_H
#define SETTINGSUSERINTERFACE_H
#include "JJCardGame.h"
#include "GameEngine.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class SettingsUserInterface
{
  public:
        SettingsUserInterface();
        virtual ~SettingsUserInterface();
        void StartUserInterface();
   private:
        void StartMenuEvent(std::vector<char> event);
        void Start_game();
        void Create_deck();
        bool die = false;
        void Clear();
        Player* p_player1;
        Player* p_player2;
        std::vector<Player*> players;
};
#endif // SETTINGSUSERINTERFACE_H_INCLUDED
