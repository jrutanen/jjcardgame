#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "JJCardGame.h"
#include "Player.h"
#include "CardDeck.h"
#include "Board.h"
#include "UiCmdLine.h"
#include <iostream>
#include <vector>

class GameEngine
{
    public:
        GameEngine();
        virtual ~GameEngine();
        void Run();
    protected:
    private:
        bool die;
        void GameLoop();
        void StartTurn();
        void EndTurn();
        Player* p_player1;
        Player* p_player2;
        void InitGame();
        void InitPlayer(Player* player);
        Board game_board;
//        std::vector<Card> available_cards;
        std::vector<Player*> players;
        void PlayCard(Board* p_board, Player* p_player, Card* p_card, int slot);
        void UiEvent(std::vector<char> event);
        UiCmdLine ui;
        int turn;
        int player_in_turn;
};

#endif // GAMEENGINE_H
