#ifndef CARD_H
#define CARD_H
#include <string>
#include "JJCardGame.h"


class Card
{
    public:
        Card();
        std::string GetCardName();
        void SetCardName(std::string type1);
        std::string GetCardType();
        void SetCardType(std::string type1);
        virtual ~Card();
        std::string card_class;
        void SetCastingCost(int cost);
        int GetCastingCost();
        //This is copy paste from Monstercard

        void AddAttack(int attack);
        void AddDefence(int defence);
        void ReduceAttack(int attack);
        void ReduceDefence(int defence);
        void SetCardAttack(int setattack);
        void SetCardDefence(int setdefence);
        int GetCardAttack();
        int GetCardDefence();
        bool IsReady();
        void Activate();
        void DeActivate();
        //end copy paste
    protected:
        int casting_cost;
        std::string card_text;
        std::string card_name;
        std::string card_type;
        //This is copy paste from Monstercard
        int card_attack;
        int card_defence;
        std::string card_ability;
        bool playable;
         //end copy paste
    private:
};

#endif // CARD_H
