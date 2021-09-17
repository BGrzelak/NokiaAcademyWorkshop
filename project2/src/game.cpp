#include "game.hpp"

GameState Game::getState()  {
    return gameState;
}

void Game::setState(GameState gameState) {
    this->gameState = gameState;
}

void Game::askPlayerForMove(std::unique_ptr<Player> const &player) {
    player->makeMove();
}