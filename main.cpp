//s#include <iostream>
#include <random>
#include "GameEngine.h"
#include "SettingsUserInterface.h"

using namespace std;

int main()
{
    //Instantiate GameEngine class and start game loop in GameEngine
    srand(time(NULL));

    //Start game with GameEngine
    //GameEngine game;
    //game.Run();

    //Start game with SettingUserInterface
    SettingsUserInterface start_ui;
    start_ui.Start_user_interface();

    return 0;
}
