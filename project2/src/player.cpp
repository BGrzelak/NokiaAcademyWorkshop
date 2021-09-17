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

    if(board->getField(c) == Field::Empty) {
        if(playerSymbol == PlayerSymbol::X)
            board->setField(c, Field::X);
        else
            board->setField(c, Field::O);
    return true;
    }
    else
        return false;
    
}