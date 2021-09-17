#pragma once

#include "input.hpp"
#include <utility>
#include "gmock/gmock.h"
#include "board.hpp"

class InputMock : public InputI
{
public:
    InputMock() = default;
    ~InputMock() override = default;

    MOCK_CONST_METHOD0(getInput, Coordinates());
};
