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

  //initialize card deck for player 1.
  InitDeck(&card_deck1);
  card_deck1.Shuffle();
  InitPlayer(&player1, &card_deck1);

  InitDeck(&card_deck2);
  card_deck2.Shuffle();
  InitPlayer(&player2, &card_deck2);

  std::cout << "Player 1 info: HitPoints: ";
  std::cout << player1.GetHitPoints() << ", Mana: " << player1.GetMana();
  std::cout << ", First Card in Hand: " << player1.ShowHand().at(0)->GetCardName() << "\n";

  std::cout << "Player 2 info: HitPoints: ";
  std::cout << player2.GetHitPoints() << ", Mana: " << player2.GetMana();
  std::cout << ", First Card in Hand: " << player2.ShowHand().at(0)->GetCardName() << "\n";

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

void GameEngine::InitDeck(CardDeck* card_deck)
{
  card_one.SetCardName("Card One");
  card_deck->AddCard(&card_one);
  card_two.SetCardName("Card Two");
  card_deck->AddCard(&card_two);
  card_three.SetCardName("Card Three");
  card_deck->AddCard(&card_three);
  card_four.SetCardName("Card Four");
  card_deck->AddCard(&card_four);
  card_five.SetCardName("Card Five");
  card_deck->AddCard(&card_five);
}

void GameEngine::InitPlayer(Player* player, CardDeck* card_deck)
{
  player->SetDeck(card_deck);
  player->SetUpGame();
  player->SetUpTurn();
}
