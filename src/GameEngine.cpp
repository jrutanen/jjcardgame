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

void GameEngine::ChangePlayerInTurn()
{
 if (player_in_turn == 1)
        {
          player_in_turn = 0;
        }
        else
        {
          player_in_turn = 1;
        }
}

int GameEngine::DefendingPlayer()
{
 if (player_in_turn == 1)
        {
          return 0;
        }
        else
        {
          return 1;
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

void GameEngine::AttackPlayer(int player_nbr)
{

     //int att_card_attack = 0;
    // att_card_attack = game_board.GetCardsForPlayer(player_in_turn).at(att_card_nbr)->GetCardAttack();

      //players.at(DefendingPlayer())-> ReduceHitPoints(att_card_attack);
              //player.players.at().GetHitPoints();
              //ReduceHitPoints(att_card_attack);

}

void GameEngine::AttackCard(int att_card_nbr, int def_card_nbr)
{
    if (def_card_nbr < game_board.NumberOfCardsOnBoard( DefendingPlayer() ))  //Only valid targets are opponent player and defending creatures, second parameter A _ X needs to be valid
          {
            int att_card_attack = 0;
            int att_card_defence = 0;
            int def_card_attack = 0;
            int def_card_defence = 0;
            int att_new_defence = 0;
            int def_new_defence = 0;

            //Get current attack and defence values for the cards
            //Attacking card
            att_card_defence = game_board.GetCardsForPlayer( player_in_turn ).at(att_card_nbr)->GetCardDefence();
            att_card_attack = game_board.GetCardsForPlayer(player_in_turn).at(att_card_nbr)->GetCardAttack();
            //Defending card
            def_card_defence = game_board.GetCardsForPlayer( DefendingPlayer() ).at(def_card_nbr)->GetCardDefence();
            def_card_attack = game_board.GetCardsForPlayer(DefendingPlayer()).at(def_card_nbr)->GetCardAttack();
            //calculate new defence values for both cards
            att_new_defence = att_card_defence - def_card_attack;
            def_new_defence = def_card_defence - att_card_attack;

            if (att_new_defence <= 0)
            {
              //Attacking Creature dies, erase the element from the vector and add it to the graveyard
              game_board.RemoveCardFromBoard(player_in_turn, att_card_nbr);
            }
            else  //Reduce hit points
            {
             //Attacking Creatures defences are reduced
              game_board.GetCardsForPlayer(player_in_turn).at(att_card_nbr)->ReduceDefence(def_card_attack);
             // SetCardDefence
            }

            if (def_new_defence <= 0)
            {
              //defending Creature dies, erase the element from the vector
              game_board.RemoveCardFromBoard(DefendingPlayer(), def_card_nbr);
            }
            else  //Reduce hit points
            {
              game_board.GetCardsForPlayer(DefendingPlayer()).at(def_card_nbr)->ReduceDefence(att_card_attack);
              // SetCardDefence
              //Creatures defences are reduced
            }

            //  std::cout << "newdefence toimii!!!" << newdefence << std::endl;
            // std::cout << "GetCardAttack toimii!!!" << cardattack;
            //Attack cards attack - Defending cards Defence = NewDefence for both cards. If defence =< 0, then card is removed from the game
            //cards_on_board.at(player)[slot]
            //GetCardAttack();
          }
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
        int att_card_nbr = (int)event.at(1)-'0'; //input character number at position 1, own side of board
        int def_card_nbr = (int)event.at(2)-'0'; //input character number at position 2, opponent side of board
        if (att_card_nbr < game_board.NumberOfCardsOnBoard(player_in_turn))  //Only cards on board can attack, first parameter A X _ , needs to be valid
        {

      if (event.at(2) == 'O')
      {
      AttackPlayer(DefendingPlayer());
      }
      else
      {
      AttackCard(att_card_nbr, def_card_nbr);
      }
        }
      break;
      }

      case 'R' :
      {
        ChangePlayerInTurn();
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
