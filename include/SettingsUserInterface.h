#ifndef SETTINGSUSERINTERFACE_H
#define SETTINGSUSERINTERFACE_H
#include "JJCardGame.h"
#include <iostream>
#include <vector>

class SettingsUserInterface
{
  public:
        SettingsUserInterface();
        virtual ~SettingsUserInterface();
        void Start_user_interface();
   private:
        void StartMenuEvent(std::vector<char> event);
        void Start_game();
        void Create_deck();
};
#endif // SETTINGSUSERINTERFACE_H_INCLUDED
