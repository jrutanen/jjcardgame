#include "GameEngine.h"

GameEngine::GameEngine()
{
    //ctor
    p_player1 = new Player();
    p_player2 = new Player();
    p_player1->SetName("Jani");
    p_player2->SetName("Janne");
    //add to the players vector
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

        int card_nbr = (int)event.at(1)-'0';  //In Ascii table character reduction, 0 is 48. card_nbr is input character number
        if (card_nbr < players.at(player_in_turn)->GetCardsInHand()) //Only execute the code if cards in hand is higher than input character number, otherwise break
        {

        if (players.at(player_in_turn)->CardInHand(card_nbr)->GetCastingCost() > players.at(player_in_turn)->GetAvailableMana()) //If the card that has been given as input casting cost is higher than available mana, then execute code
        {
           //not enough mana
        }
        else  //Yes enough mana
        {
          Card* p_card = players.at(player_in_turn)->PlayCard(card_nbr); //p_player1->PlayCard(0); Plays the card pointer
          game_board.AddCardToPlayer(player_in_turn, p_card); //Adds the card to a his side on board
          players.at(player_in_turn)->ReduceAvailableMana(p_card->GetCastingCost());  //Reduces the played cards Casting Cost
        }
        }
        break;
      }
      case 'A' : //commands to be used:; void Player::ReduceHitPoint(int points); int Player::GetHitPoints(); void Card::ReduceDefence(int defence); int Card::GetCardAttack()
        //int Card::GetCardDefence(); Card::SetCardDefence(int setdefence)
      {
        int card_nbr1 = (int)event.at(1)-'0'; //input character number at position 1
        if (card_nbr1 = false) //How to check card position is valid?
        {
         std::cout << "Invalid input";
        }
        int card_nbr2 = (int)event.at(2)-'0'; //input character number at position 3
        if (card_nbr1 < cards_on_board.at(player_in_turn)->GetCardsOnBoard())//Only cards on board can attack, first parameter A X _ , needs to be valid
        {

        }//Only valid targets are opponent player and defending creatures, second parameter A _ X needs to be valid
        //Attack cards attack - Defending cards Defence = NewDefence for both cards. If defence =< 0, then card is removed from the game





       // ReduceDefence( );
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
