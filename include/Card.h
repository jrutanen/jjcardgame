#ifndef CARD_H
#define CARD_H
#include <string>

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
    protected:
        int casting_cost;
        std::string card_text;
        std::string card_name;
        std::string card_type;
    private:
        std::string card_name;
};

#endif // CARD_H
