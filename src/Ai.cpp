#include "Ai.h"
Ai::Ai()
{

}

Ai::~Ai()
{

}

std::vector<char> Ai::EvaluatePlay(std::vector<Card*> p1_cards, std::vector<Card*> p2_cards, std::vector<Card*> p2_cardsinhand)

//{    //if there is still cards to play, attacks to attack in a turn repeat
//    if ((players.at(player_in_turn)->CardInHand(card_nbr)->GetCastingCost() < players.at(player_in_turn)->GetAvailableMana()) )
  {
  std::vector<char> ai_command;


    //if attacks+spells result in fatal dmg or opponent doesn't have any creatures, then attack hero directly

    //If opponent has creatures
      //Cast spells to remove opp creatures
      //Attack to opponents creatures. Attack with a creature that has higher or equal attack to defending players creature && own creature survives
            //If 2 similar targets, then just pick one randomly
            //If opponent low on health and you are high on health then maybe attack face instead
    //If no more actions to do then, Pass turn to opponent
  ai_command.push_back('R');
  return ai_command;
 //   }

}
