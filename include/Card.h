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
<<<<<<< HEAD
        std::string GetName();
        void SetName(std::string name);
=======
        std::string card_class;
        void SetCastingCost(int cost);
        int GetCastingCost();
>>>>>>> f60e2023aec360768bdac9b803bcccc14ff8da63
    protected:
        int casting_cost;
        std::string card_text;
        std::string card_name;
        std::string card_type;
    private:
<<<<<<< HEAD
              std::string card_name;
=======

>>>>>>> f60e2023aec360768bdac9b803bcccc14ff8da63
};

#endif // CARD_H
