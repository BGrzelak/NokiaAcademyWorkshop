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

    if(board_pointer->getField(c) == Field::Empty)
        return true;
    else
        return false;
    
}