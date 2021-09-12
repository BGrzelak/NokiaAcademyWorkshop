#pragma once

#include <utility>

// Do no change anything in this file,
// do not create a coresponding cpp file,
// instead use mocks!

struct Coordinates;

class InputI
{
public:
    virtual ~InputI() = default;

    virtual Coordinates getInput() const = 0;
};

class HumanInput : public InputI // do not implement this class!
{
public:
    Coordinates getInput() const;
};

class AiInput : public InputI // do not implement this class!
{
public:
    Coordinates getInput() const;
};
