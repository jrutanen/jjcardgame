#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Player.h"
#include <iostream>

class GameEngine
{
    public:
        GameEngine();
        virtual ~GameEngine();
        void Run();
    protected:
    private:
        void GameLoop();
        Player player1;
};

#endif // GAMEENGINE_H
