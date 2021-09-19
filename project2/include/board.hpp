#pragma once
#include <vector>

enum class Field;

enum class GameState
{
    InProgress,
    XWon,
    OWon,
    Draw
};

struct Coordinates
{
    int row;
    int column;

    public:
        bool operator==(const Coordinates& c)
        {
            if((this->column == c.column) && (this->row == c.row))
                return true;
            else
                return false;
        };
};

class FieldContainer
{
    public:
        Coordinates coordinates;
        Field field;
};

class BoardI
{
public:
    virtual ~BoardI() = default;
    virtual void setField(const Coordinates &, Field) = 0;
    virtual Field getField(const Coordinates &) const = 0;
    virtual int getSize() const = 0;
    virtual int getNumberOfEmptyFields() const = 0;
    virtual GameState checkWinningPatterns() const = 0;
};

class Board : public BoardI
{
public:
    Board();
    Board(int boardSize);
    Field getField(const Coordinates &) const override;
    void setField(const Coordinates &, Field) override;
    int getSize() const override;
    int getNumberOfEmptyFields() const override;
    GameState checkWinningPatterns() const override;

private:
    std::vector<std::vector<Field>> fields;
    static constexpr int size = 3;
};
