#ifndef SETTINGSUSERINTERFACE_H
#define SETTINGSUSERINTERFACE_H
#include "JJCardGame.h"
#include "GameEngine.h"
#include <iostream>
#include <vector>

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
};
#endif // SETTINGSUSERINTERFACE_H_INCLUDED
