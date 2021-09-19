#include "board.hpp"
#include "field.hpp"
#include "algorithm"

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

GameState Board::checkWinningPatterns() const
{
    // this->fields
    // auto it = std::find_if(this->fields.begin(), this->fields.end(), [&coordinates](const FieldContainer& obj)
    // {
    //     return coordinates == obj.coordinates;
    // });

    return GameState::XWon;
}