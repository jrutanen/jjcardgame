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
  InitDeck();

  std::cout << "Before shuffling deck is:\n";
  for (int i = 0; i < 5; ++i)
  {
    Card* debug_card = card_deck.GetCardOnTop();
    std::cout << debug_card->GetCardName() << "\n";
  }

  std::cout << "After shuffling deck is:\n";
  InitDeck();
  card_deck.Shuffle();
  for (int i = 0; i < 5; ++i)
  {
    std::cout << card_deck.GetCardOnTop()->GetCardName() << "\n";
  }

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

void GameEngine::InitDeck()
{
  card_one.SetCardName("Card One");
  card_deck.AddCard(&card_one);
  card_two.SetCardName("Card Two");
  card_deck.AddCard(&card_two);
  card_three.SetCardName("Card Three");
  card_deck.AddCard(&card_three);
  card_four.SetCardName("Card Four");
  card_deck.AddCard(&card_four);
  card_five.SetCardName("Card Five");
  card_deck.AddCard(&card_five);
}
