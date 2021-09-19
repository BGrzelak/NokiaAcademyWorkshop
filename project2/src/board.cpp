#include "board.hpp"
#include "field.hpp"
#include "algorithm"

Board::Board(int boardSize = 3)
{
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            this->fields.at(i).field = Field::Empty;
            this->fields.at(i).coordinates.column = i;
            this->fields.at(i).coordinates.row = j;
        }
    }
}

Field Board::getField(const Coordinates &coordinates) const
{
    for(auto field : fields)
    {
        if(field.coordinates == coordinates)
            return field.field;
    }

    return Field::Empty;
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
    auto it = std::find_if(this->fields.begin(), this->fields.end(), [&coordinates](const FieldContainer& obj){ return coordinates == obj.coordinates;});

    it->coordinates = coordinates;
    it->field = field;
}
int Board::getSize() const
{
    return size;

}

int Board::getNumberOfEmptyFields() const
{
    int result = 0;
    for(auto field : this->fields)
        if(field.field == Field::Empty)
            result += 1;

    return result;
}