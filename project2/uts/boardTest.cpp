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
    
    EXPECT_EQ(Field::Empty, sut->getField({0, 0}));
}

TEST_F(BoardTest, givenFreshBoardWhenFieldX0Y0IsSetToOThenItReturnsO)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>();
    sut->setField({0, 0}, Field::O);

    EXPECT_EQ(Field::O, sut->getField({0, 0}));
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

TEST_F(BoardTest, shouldReturnWinnigPlayerXWhenHorizontalLineSetToX)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>(3);
    sut->setField({1, 0}, Field::X);
    sut->setField({1, 1}, Field::X);
    sut->setField({1, 2}, Field::X);

    EXPECT_EQ(sut->checkGameState(), GameState::XWon);
}

TEST_F(BoardTest, shouldReturnWinnigPlayerXWhenVerticalLineSetToX)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>(3);
    sut->setField({0, 0}, Field::X);
    sut->setField({1, 0}, Field::X);
    sut->setField({2, 0}, Field::X);

    EXPECT_EQ(sut->checkGameState(), GameState::XWon);
}

TEST_F(BoardTest, shouldReturnWinnigPlayerOWhenVerticalLineSetToO)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>(3);
    sut->setField({0, 2}, Field::O);
    sut->setField({1, 2}, Field::O);
    sut->setField({2, 2}, Field::O);

    EXPECT_EQ(sut->checkGameState(), GameState::OWon);
}

TEST_F(BoardTest, shouldReturnWinnigPlayerXWhenDiagonalNWLineSetToX)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>(3);
    sut->setField({0, 0}, Field::X);
    sut->setField({1, 1}, Field::X);
    sut->setField({2, 2}, Field::X);

    EXPECT_EQ(sut->checkGameState(), GameState::XWon);
}

TEST_F(BoardTest, shouldReturnWinnigPlayerXWhenDiagonalSWLineSetToX)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>(3);
    sut->setField({2, 0}, Field::X);
    sut->setField({1, 1}, Field::X);
    sut->setField({0, 2}, Field::X);

    EXPECT_EQ(sut->checkGameState(), GameState::XWon);
}

TEST_F(BoardTest, shouldReturnWinnigPlayerOWhenDiagonalNWLineSetToO)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>(3);
    sut->setField({0, 0}, Field::O);
    sut->setField({1, 1}, Field::O);
    sut->setField({2, 2}, Field::O);

    EXPECT_EQ(sut->checkGameState(), GameState::OWon);
}

TEST_F(BoardTest, shouldReturnWinnigPlayerOWhenDiagonalSWLineSetToO)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>(3);
    sut->setField({2, 0}, Field::O);
    sut->setField({1, 1}, Field::O);
    sut->setField({0, 2}, Field::O);

    EXPECT_EQ(sut->checkGameState(), GameState::OWon);
}

TEST_F(BoardTest, shouldReturnWinnigPlayerOWhenDiagonalSWLineSetToOForBoardOfSize4)
{
    std::unique_ptr<BoardI> sut = std::make_unique<Board>(4);
    sut->setField({3, 0}, Field::O);
    sut->setField({2, 1}, Field::O);
    sut->setField({1, 2}, Field::O);
    sut->setField({0, 3}, Field::O);

    EXPECT_EQ(sut->checkGameState(), GameState::OWon);
}