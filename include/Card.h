#ifndef CARD_H
#define CARD_H
#include <string>

class Card
{
    public:
        Card();
        virtual ~Card();
        std::string GetName();
        void SetName(std::string name);
    protected:
    private:
              std::string card_name;
};

#endif // CARD_H
