#pragma once
#include <memory>
#include "player.hpp"
#include "board.hpp"

enum class GameState
{
    InProgress,
    XWon,
    OWon,
    Draw
};

class Game
{
    public:
    Game()
    {
        this->gameState = GameState::InProgress;
    };
    Game(std::unique_ptr<Player> &player1, std::unique_ptr<Player> &player2, std::shared_ptr<BoardI> board)
        : player1(std::move(player1)), player2(std::move(player2)), board(std::move(board))
    {
        this->gameState = GameState::InProgress;
    };
        GameState getState();
        void setState(GameState gameState);
        void askPlayerForMove(std::unique_ptr<Player> const &player);
        GameState check_win();
    private:
        GameState gameState;
        std::unique_ptr<Player> player1;
        std::unique_ptr<Player> player2;
        std::shared_ptr<BoardI> board;
};
