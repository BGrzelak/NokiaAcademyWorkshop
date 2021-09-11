#pragma once

enum class Field;

struct Coordinates
{
    int row;
    int column;
};

class BoardI
{
public:
    virtual ~BoardI() = default;
    virtual void setField(const Coordinates &, Field) = 0;
    virtual Field getField(const Coordinates &) const = 0;
    virtual int getSize() const = 0;
};

class Board : public BoardI
{
public:
    Board();
    Field getField(const Coordinates &) const override;
    void setField(const Coordinates &, Field) override;
    int getSize() const override;

private:
    Field _field;
    static constexpr int size = 3;
};
