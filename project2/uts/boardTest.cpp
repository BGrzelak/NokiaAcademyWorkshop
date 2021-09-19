#include "gtest/gtest.h"
#include "board.hpp"
#include "field.hpp"

std::ostream &operator<<(std::ostream &str, Field field)
{
    switch (field)
    {
    case Field::Empty:
        return str << "Empty";
    case Field::O:
        return str << "O";
    default:
        return str << "Unknown";
    }
}

class BoardTest : public ::testing::Test
{
};

TEST_F(BoardTest, givenFreshBoardFieldX0Y0IsEmpty)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>();
    Coordinates c;
    c.row = 0;
    c.column = 0;
    
    EXPECT_EQ(Field::Empty, sut->getField(c));
}

TEST_F(BoardTest, givenFreshBoardWhenFieldX0Y0IsSetToOThenItReturnsO)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>();
    sut->setField({0, 0}, Field::O);

    EXPECT_EQ(Field::O, sut->getField(Coordinates{0, 0}));
}

TEST_F(BoardTest, givenFreshBoardWhenFieldX0Y0IsSetToOThenItReturnsX)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>();
    sut->setField({0, 0}, Field::X);

    EXPECT_EQ(Field::X, sut->getField({0, 0}));
}

TEST_F(BoardTest, shouldReturnDefaultSize3ofBoard)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>();

    EXPECT_EQ(sut->getSize(), 3);
}

TEST_F(BoardTest, shouldReturn9EmptyPlacesForNewBoard)

{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>(3);

    EXPECT_EQ(sut->getNumberOfEmptyFields(), 9);
}

TEST_F(BoardTest, shouldReturn8EmptyPlaces)

{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>(3);
    sut->setField({0, 0}, Field::X);

    EXPECT_EQ(sut->getNumberOfEmptyFields(), 8);
}

TEST_F(BoardTest, shouldReturnWinnigPlayer)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>(3);
    sut->setField({0, 0}, Field::X);
    sut->setField({1, 0}, Field::X);
    sut->setField({2, 0}, Field::X);

    EXPECT_EQ(sut->checkWinningPatterns(), GameState::XWon);
}