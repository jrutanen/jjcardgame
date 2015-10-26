//s#include <iostream>
#include <random>
#include "GameEngine.h"

using namespace std;

int main()
{
    //Instantiate GameEngine class and start game loop in GameEngine
    srand(time(NULL));
    GameEngine game;
    game.Run();
    return 0;
}
