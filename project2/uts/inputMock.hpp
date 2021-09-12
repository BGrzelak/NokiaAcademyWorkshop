#pragma once

#include "input.hpp"
#include <utility>
#include "gmock/gmock.h"

struct Coordinates;

class InputMock : public InputI
{
public:
    InputMock() = default;
    ~InputMock() override = default;

    MOCK_CONST_METHOD0(getInput, Coordinates());
};
