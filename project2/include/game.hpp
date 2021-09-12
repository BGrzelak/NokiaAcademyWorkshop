#pragma once

class BoardI;

enum class GameState
{
    InProgress,
    XWon
};

class Game
{
    public:
    Game(){
        this->gameState = GameState::InProgress;
    };
        GameState getState();
    private:
        GameState gameState;
};
