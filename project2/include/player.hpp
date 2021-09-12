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
        Player(PlayerSymbol playerSymbol, InputI& humanInput, Board& board) 
        : playerSymbol(playerSymbol), input(&humanInput), board_pointer(&board){}
        
        PlayerSymbol getPlayerSymbol();
        bool makeMove();
    private:
        PlayerSymbol playerSymbol;
        InputI* input;
        Board* board_pointer;
};

