#include "GameEngine.h"

GameEngine::GameEngine()
{
    //ctor
    p_player1 = new Player();
    p_player2 = new Player();
    p_player1->SetName("Jani");
    p_player2->SetName("Janne");
    //add players to the players vector
    players.push_back(p_player1);
    players.push_back(p_player2);
}

GameEngine::~GameEngine()
{
    //dtor
    delete p_player1;
    delete p_player2;
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
  //game loop
  turn = 1;
  player_in_turn = 0;
  //set-up first turn
  players.at(player_in_turn)->SetUpTurn();
  while(!die)
  {
    response = ui.DrawBoard(p_player1, p_player2, &game_board, player_in_turn);
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
//  for (uint i = 0; i < players.size(); ++i)
//  {
    if (player_in_turn == 0)
    {
      p_player1->SetUpTurn();
    }
    else
    {
      p_player2->SetUpTurn();
    }
 // }
}

void GameEngine::EndTurn()
{

}

void GameEngine::InitPlayer(Player* player)
{
  player->SetUpGame();
}

void GameEngine::UiEvent(std::vector<char> event)
{
//  std::cout << "P x-Play Card x, A x-Attack Card x, R-End turn, Q-Quit\n";
  if (event.size() > 0)
  {
    switch(event.at(0))
    {
      case '?' :
      {
        ui.DisplayHelp();
        break;
      }
      case 'P' :
      {
        //std::ostringstream card << event.at(1) ;
        int card_nbr = (int)event.at(1)-'0';
        if (players.at(player_in_turn)->CardInHand(card_nbr)->GetCastingCost() > players.at(player_in_turn)->GetAvailableMana())
        {
           //not enough mana
        }
        else
        {
          Card* p_card = players.at(player_in_turn)->PlayCard(card_nbr); //p_player1->PlayCard(0);
          game_board.AddCardToPlayer(player_in_turn, p_card);
          players.at(player_in_turn)->ReduceAvailableMana(p_card->GetCastingCost());
        }
        break;
      }
      case 'A' :
      {
        std::cout << "\nA-pressed";
        break;
      }
      case 'R' :
      {
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
        players.at(player_in_turn)->SetUpTurn();
        break;
      }
      case 'Q' :
      {
        die = true;
        break;
      }
    }
  }

}
