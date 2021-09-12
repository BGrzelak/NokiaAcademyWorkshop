#include "game.hpp"

GameState Game::getState()  {
    return gameState;
}

void Game::setState(GameState gameState) {
    this->gameState = gameState;
}