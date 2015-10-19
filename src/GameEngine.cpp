#include "GameEngine.h"

GameEngine::GameEngine()
{
    //ctor
    //add players to the players vector
    players.push_back(&player1);
    players.push_back(&player2);
    //add card decks to the card_decks vector
    card_decks.push_back(&card_deck1);
    card_decks.push_back(&card_deck2);
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

  //initialize card deck for player 1
  InitDeck(&card_deck1);
  //shuffle player 1 deck
  card_deck1.Shuffle();
  //Set-up player for game and turn 1
  InitPlayer(&player1, &card_deck1);

  //initialize card deck for player 2
  InitDeck(&card_deck2);
  //shuffle player 2 deck
  card_deck2.Shuffle();
  //Set-up player for game and turn 1
  InitPlayer(&player2, &card_deck2);
  player2.AddMana(1);

  std::cout << "Player 1 info: HitPoints: ";
  std::cout << player1.GetHitPoints() << ", Mana: " << player1.GetMana();
  std::cout << ", First Card in Hand: " << player1.ShowHand().at(0)->GetCardName() << "\n";

  std::cout << "Player 2 info: HitPoints: ";
  std::cout << player2.GetHitPoints() << ", Mana: " << player2.GetMana();
  std::cout << ", First Card in Hand: " << player2.ShowHand().at(0)->GetCardName() << "\n";

//game loop
int turn = 1;
  while(!die) {
    StartTurn();
    std::cout << "Player 1 info: Mana: " << player1.GetMana() << "\n";
    std::cout << "Player 2 info: Mana: " << player2.GetMana() << "\n";
    EndTurn();
    ++turn;

    //run ten turns at this point.
    if (turn > 10)
    {
      die = true;
    }

  }
}

void GameEngine::StartTurn()
{
  for(int i = 0; i < players.size(); ++i)
  {
    players.at(i)->SetUpTurn();
  }
}

void GameEngine::EndTurn()
{

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
