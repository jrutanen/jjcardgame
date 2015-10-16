#include <iostream>
#include "GameEngine.h"

using namespace std;

int main()
{
    cout << "Terve vaan maailma!!!!!!!!!!!!!!!" << endl;
    //Instantiate GameEngine class and start game loop in GameEngine
    GameEngine game;
    game.Run();
    return 0;
}
