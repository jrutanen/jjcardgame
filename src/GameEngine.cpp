#include "GameEngine.h"

GameEngine::GameEngine()
{
    //ctor
}

GameEngine::~GameEngine()
{
    //dtor
}

void GameEngine::Run()
{
    GameLoop();
}

void GameEngine::GameLoop()
{
  bool die = false;

  while(!die) {
    //execute game
    if (player1.GetHitPoints() > 0)
    {
      std::cout << "hit points is " << player1.GetHitPoints() << std::endl;
      player1.ReduceHitPoint(5);
    }
    else
    {
      die = true;
      std::cout << "hit points is " << player1.GetHitPoints() << std::endl;
    }

    //prevent infinite loop at this point

  }

}
