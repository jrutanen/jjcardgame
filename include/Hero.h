#ifndef HERO_H
#define HERO_H
#include <string>
#include "JJCardGame.h"


class Hero
{
    public:
        Hero();
        std::string GetHeroName();
        void SetHeroName(std::string hero1);
        std::string GetHeroType();
        void SetHeroType(std::string type1);
        virtual ~Hero();
    protected:
    private:
        std::string herotype1;
        std::string hero1;
        std::string hero_name;
        std::string type1;

};

#endif // HERO_H
