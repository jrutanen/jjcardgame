#ifndef MONSTERCARD_H
#define MONSTERCARD_H
#include "Card.h"
<<<<<<< HEAD
=======
#include <string>
>>>>>>> f1fa28e8fff19d7e422c9692110731c054ed5877

class MonsterCard:Card
{
    public:
<<<<<<< HEAD
        MonsterCard();
        virtual ~MonsterCard();
    protected:
=======
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
>>>>>>> f1fa28e8fff19d7e422c9692110731c054ed5877
    private:
};

#endif // MONSTERCARD_H
