#include "GameEngine.h"

GameEngine::GameEngine()
{
    //ctor
    //add players to the players vector
    players.push_back(&player1);
    players.push_back(&player2);
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

  die = false;
  std::vector<char> response;

  //initialize game components (board, player, etc.)
  InitGame();
/*
  std::cout << "Player 1 info: HitPoints: ";
  std::cout << player1.GetHitPoints() << ", Mana: " << player1.GetMana();
  std::cout << ", First Card in Hand: " << player1.ShowHand().at(0)->GetCardName() << "\n";

  std::cout << "Player 2 info: HitPoints: ";
  std::cout << player2.GetHitPoints() << ", Mana: " << player2.GetMana();
  std::cout << ", First Card in Hand: " << player2.ShowHand().at(0)->GetCardName() << "\n";
*/
//game loop
  turn = 1;
  player_in_turn = 0;
  while(!die) {
    StartTurn();
  //  response = ui.DrawBoard(player1.GetHitPoints(), player1.GetMana(), player1.ShowHand(), player2.GetHitPoints(), player2.GetMana(), player2.ShowHand());
    response = ui.DrawBoard(&player1, &player2, &game_board, player_in_turn);
    UiEvent(response);
  }
}

void GameEngine::InitGame()
{
  for (uint i = 0; i < players.size(); ++i)
  {
    InitPlayer(players.at(i));
  }
}

void GameEngine::StartTurn()
{
  for (uint i = 0; i < players.size(); ++i)
  {
    players.at(i)->SetUpTurn();
  }
}

void GameEngine::EndTurn()
{

}

void GameEngine::InitPlayer(Player* player)
{
  player->SetUpGame();
}
/*
void GameEngine::PlayCard( Board* p_board, Player* p_player, Card* p_card, int slot)
{
  p_board->AddCardToPlayerOne(p_player->player_hand.PlayCard(p_card), slot);
}
*/

void GameEngine::UiEvent(std::vector<char> event)
{
//  std::cout << "P x-Play Card x, A x-Attack Card x, R-End turn, Q-Quit\n";
  if (event.size() > 0)
  {
    switch(event.at(0))
    {
      case '?' :
        ui.DisplayHelp();
        break;
      case 'P' :
        std::cout << "\nP-pressed";
//        game_board.AddCardToPlayer(player_in_turn, players.at(player_in_turn)->PlayCard(event.at(1)));
        break;
      case 'A' :
        std::cout << "\nA-pressed";
        break;
      case 'R' :
        if (player_in_turn == 1)
        {
          player_in_turn = 0;
        }
        else
        {
          player_in_turn = 1;
        }
        EndTurn();
        ++turn;
        break;
      case 'Q' :
        die = true;
        break;
    }
  }

}
