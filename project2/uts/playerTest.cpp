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
            //std::shared_ptr<InputMock> mockInput = std::shared_ptr<InputMock>(&mockInput1(), [](...){});
            //std::shared_ptr<InputMock> mockInput = std::make_shared<InputMock>();
            //std::shared_ptr<InputI> mockInput = std::shared_ptr<testing::NaggyMock<InputMock>>(new testing::NaggyMock<InputMock>());
            //std::shared_ptr<InputMock> mockInput = std::make_shared<testing::NaggyMock<InputMock>>();
            //Fake(Dtor((*mockInput)));
            //std::shared_ptr<InputMock> mockInput = &mockInput1;
};

TEST_F(PlayerTest, shouldReturnAsPlayerSymbolIsO)
{
    std::shared_ptr<Board> board = std::make_shared<Board>();
    Player sut(PlayerSymbol::O, mockInput, board);
    
    EXPECT_EQ(sut.getPlayerSymbol(), PlayerSymbol::O);
}

TEST_F(PlayerTest, shouldReturnAsPlayerSymbolIsX)
{
    std::shared_ptr<Board> board = std::make_shared<Board>();
    Player sut(PlayerSymbol::X, mockInput, board);

    //EXPECT_EQ(sut.getPlayerSymbol(), PlayerSymbol::X);
}

TEST_F(PlayerTest, shouldReturnTrueIfBoardHaveEmptySpaceOnGivenCoordinates)
{
    Coordinates c;
    c.row = 1;
    c.column = 1;
    std::shared_ptr<Board> board = std::make_shared<Board>();
    board->setField(c, Field::Empty);
    Player sut(PlayerSymbol::X, mockInput, board);

    //ON_CALL(mockInput, getInput()).WillByDefault(testing::Return(c));
    EXPECT_CALL(mockInput, getInput()).WillOnce(testing::Return(c));
    EXPECT_TRUE(sut.makeMove());
}

TEST_F(PlayerTest, shouldReturnFalseIfBoardHaveOccupiedSpaceOnGivenCoordinates)
{
    Coordinates c;
    c.row = 1;
    c.column = 1;
    std::shared_ptr<Board> board = std::make_shared<Board>();
    board->setField(c, Field::X);
    Player sut(PlayerSymbol::X, mockInput, board);

    //ON_CALL(mockInput, getInput()).WillByDefault(testing::Return(c));
    EXPECT_CALL(mockInput, getInput()).WillOnce(testing::Return(c));
    EXPECT_FALSE(sut.makeMove());
}
