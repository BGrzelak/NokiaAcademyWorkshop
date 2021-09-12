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
        void setState(GameState gameState);
    private:
        GameState gameState;
};
