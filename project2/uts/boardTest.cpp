#include "gtest/gtest.h"
#include "board.hpp"
#include "field.hpp"

class BoardTest : public ::testing::Test
{
};

TEST_F(BoardTest, givenFreshBoardFieldX0Y0IsEmpty)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>();
    EXPECT_EQ(Field::Empty, sut->getField({0, 0}));
}

TEST_F(BoardTest, givenFreshBoardWhenFieldX0Y0IsSetToOThenItReturnsO)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>();
    sut->setField({0, 0}, Field::O);
    EXPECT_EQ(Field::O, sut->getField({0, 0}));
}
