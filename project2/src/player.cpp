#include "player.hpp"
#include "iostream"
#include "field.hpp"

PlayerSymbol Player::getPlayerSymbol()
{
    return playerSymbol;
}

bool Player::makeMove()
{
    Coordinates c = input->getInput();

    if(board_pointer->getField(c) == Field::Empty) {
        if(playerSymbol == PlayerSymbol::X)
            board_pointer->setField(c, Field::X);
        else
            board_pointer->setField(c, Field::O);
    return true;
    }
    else
        return false;
    
}