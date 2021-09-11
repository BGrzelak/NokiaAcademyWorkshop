#pragma once
#include "board.hpp"
#include <memory>

enum class PlayerSymbol
{
    O,
    X
};

class Player
{
    public:
        Player(PlayerSymbol playerSymbol, std::shared_ptr<BoardI> playerBoard) : playerSymbol(playerSymbol), playerBoard(playerBoard)
        {}
        PlayerSymbol getPlayerSymbol();

    private:
        PlayerSymbol playerSymbol;
        std::shared_ptr<BoardI> playerBoard;
};

