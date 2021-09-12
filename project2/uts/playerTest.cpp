#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "player.hpp"
#include "board.hpp"
#include "inputMock.hpp"
#include "boardMock.hpp"
#include <utility>
#include "field.hpp"

class PlayerTest : public ::testing::Test
{
    public:
            testing::NaggyMock<InputMock> mockInput;
    protected:
    PlayerTest() {};
    ~PlayerTest() override {};

    void SetUp() override {};
    void TearDown() override {};
};


TEST_F(PlayerTest, shouldReturnAsPlayerSymbolIsO)
{
    Board testBoard;
    Player sut(PlayerSymbol::O, mockInput, testBoard);
    
    EXPECT_EQ(sut.getPlayerSymbol(), PlayerSymbol::O);
}

TEST_F(PlayerTest, shouldReturnAsPlayerSymbolIsX)
{
    Board testBoard;
    Player sut(PlayerSymbol::X, mockInput, testBoard);

    EXPECT_EQ(sut.getPlayerSymbol(), PlayerSymbol::X);
}

TEST_F(PlayerTest, shouldReturnTrueIfBoardHaveEmptySpaceOnGivenCoordinates)
{
    Coordinates c;
    c.row = 1;
    c.column = 1;
    Board testBoard;
    testBoard.setField(c, Field::Empty);
    Player sut(PlayerSymbol::X, mockInput, testBoard);

    //ON_CALL(mockInput, getInput()).WillByDefault(testing::Return(c));
    EXPECT_CALL(mockInput, getInput()).WillOnce(testing::Return(c));
    EXPECT_TRUE(sut.makeMove());
}

TEST_F(PlayerTest, shouldReturnFalseIfBoardHaveOccupiedSpaceOnGivenCoordinates)
{
    Coordinates c;
    c.row = 1;
    c.column = 1;
    Board testBoard;
    testBoard.setField(c, Field::X);
    Player sut(PlayerSymbol::X, mockInput, testBoard);

    //ON_CALL(mockInput, getInput()).WillByDefault(testing::Return(c));
    EXPECT_CALL(mockInput, getInput()).WillOnce(testing::Return(c));
    EXPECT_FALSE(sut.makeMove());
}
