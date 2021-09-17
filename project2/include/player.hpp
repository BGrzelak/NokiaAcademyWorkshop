#pragma once
#include "board.hpp"
#include <memory>
#include "input.hpp"
#include "field.hpp"

enum class PlayerSymbol
{
    O,
    X
};

class Player
{
    public:
        Player(PlayerSymbol playerSymbol, InputI &humanInput, std::shared_ptr<Board>& board) 
        : playerSymbol(playerSymbol), input(&humanInput), board(std::move(board)){}
        
        PlayerSymbol getPlayerSymbol();
        bool makeMove();
    private:
        PlayerSymbol playerSymbol;
        InputI *input;
        std::shared_ptr<Board> board;
};

