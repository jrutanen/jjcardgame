#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "CardDeck.h"
#include "Hero.h"
#include "Hand.h"
#include "Card.h"
#include "JJCardGame.h"
#include "Ai.h"
#include "Board.h"

//using namespace std;

class Player
{
    public:
        Player();
        virtual ~Player();
        void AddHitPoints(int points);
        int GetHitPoints ();
        void ReduceHitPoints(int points);
        void DrawCard();
        std::vector<Card*> ShowHand();
        void SetName(std::string name);
        std::string GetName();
        void SetDeck(CardDeck* p_deck);
        void ShuffleDeck();
        void SetHero(Hero* p_hero);
        void AddMana(int mana_points);
        int GetMana();
        void ReduceAvailableMana(int mana_points);
        void AddAvailableMana(int mana_points);
        int GetAvailableMana();
        int GetCardsInHand();
        void SetUpTurn();
        void SetUpGame();
        Hand player_hand;
        Card* PlayCard(int card_nbr);
        Card* CardInHand(int card_nbr);
        void SetAi(bool set_ai);
        bool IsAi();
        //std::vector<char> Evaluate(Board* b);
        std::vector<char> Evaluate(std::vector<Card*> p1_cards, std::vector<Card*> p2_cards);
    protected:
    private:
        bool ai;
        int hit_points;
        int player_mana_points;
        int available_mana;
        int no_of_cards_in_hand;
        std::string player_name;
        CardDeck* p_card_deck;
        CardDeck card_deck;
        Hero* p_player_hero;
        std::vector<Card*> cards_in_hand; //moved here from Hand.h


};

#endif // PLAYER_H
