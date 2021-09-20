#include "board.hpp"
#include "field.hpp"
#include "algorithm"
#include <iostream>

Board::Board(int boardSize = 3)
{
    for(int i = 0; i < boardSize; i++)
    {
        this->fields.push_back({});
        for(int j = 0; j < boardSize; j++)
        {
            this->fields.at(i).push_back(Field::Empty);
        }
    }
}

Board::Board()
{
    for(int i = 0; i < 3; i++)
    {
        this->fields.push_back({});
        for(int j = 0; j < 3; j++)
        {
            this->fields.at(i).push_back(Field::Empty);
        }
    }

}

Field Board::getField(const Coordinates &coordinates) const
{
    return this->fields.at(coordinates.row).at(coordinates.column);
}

bool operator==(const Coordinates& k, const Coordinates& c)
{
    if((k.column == c.column) && (k.row == c.row))
        return true;
    else
        return false;
}

void Board::setField(const Coordinates & coordinates, Field field)
{
    fields.at(coordinates.row).at(coordinates.column) = field;
}
int Board::getSize() const
{
    return size;

}

int Board::getNumberOfEmptyFields() const
{
    int result = 0;
    for(auto row : this->fields)
    {
        for(auto column : row)
        {
            if(column == Field::Empty)
                result += 1;
        }
    }

    return result;
}

GameState Board::checkGameState() const
{
    int rowNumber = static_cast<int>(this->fields.at(0).size());
    int columnNumber = static_cast<int>(this->fields.size());

    for(int i = 0; i < columnNumber; i++)
    {
        if((std::count_if(this->fields.at(i).begin(), this->fields.at(i).end(), [](const Field &f){return f == Field::X;})) == columnNumber)
            return GameState::XWon;
        if((std::count_if(this->fields.at(i).begin(), this->fields.at(i).end(), [](const Field &f){return f == Field::O;})) == columnNumber)
            return GameState::OWon;
        int numberOfXVertical = 0;
        int numberOfOVertical = 0;
        int numberOfXDiagonallyNW = 0;
        int numberOfXDiagonallySW = 0;
        int numberOfODiagonallyNW = 0;
        int numberOfODiagonallySW = 0;
        for(int k = 0, p = rowNumber-1; k < rowNumber; k++, p--)
        {
            if(this->fields.at(k).at(i) == Field::X)
                numberOfXVertical += 1;
            if(this->fields.at(k).at(i) == Field::O)
                numberOfOVertical += 1;
            if(this->fields.at(k).at(k) == Field::X)
                numberOfXDiagonallyNW += 1;
            if(this->fields.at(p).at(k) == Field::X)
                numberOfXDiagonallySW += 1;
            if(this->fields.at(k).at(k) == Field::O)
                numberOfODiagonallyNW += 1;
            if(this->fields.at(p).at(k) == Field::O)
                numberOfODiagonallySW += 1;
            
        if(numberOfXVertical == columnNumber)
            return GameState::XWon;
        if(numberOfOVertical == columnNumber)
            return GameState::OWon;
        if(numberOfXDiagonallyNW == columnNumber)
            return GameState::XWon;
        if(numberOfXDiagonallySW == columnNumber)
            return GameState::XWon;
        if(numberOfODiagonallyNW == columnNumber)
            return GameState::OWon;
        if(numberOfODiagonallySW == columnNumber)
            return GameState::OWon;
        }
    }

    if(this->getNumberOfEmptyFields() == 0)
        return GameState::InProgress;    

    return GameState::InProgress;
}