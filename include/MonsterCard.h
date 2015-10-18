#ifndef MONSTERCARD_H
#define MONSTERCARD_H
#include "Card.h"
#include <string>

class MonsterCard:Card
{
    public:
        void AddAttack(int attack);
        void AddDefence(int defence);
        void ReduceAttack(int attack);
        void ReduceDefence(int defence);
        void SetCardAttack(int setattack);
        void SetCardDefence(int setdefence);
        int GetCardAttack();
        int GetCardDefence();
        MonsterCard();
        virtual ~MonsterCard();
    protected:
        int card_attack;
        int card_defence;
        std::string card_ability;
    private:
};

#endif // MONSTERCARD_H
