#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "player.hpp"
#include "board.hpp"

class PlayerTest : public ::testing::Test
{
    protected:
    PlayerTest() {};
    ~PlayerTest() override {};

    void SetUp() override {};
    void TearDown() override {};
};


TEST_F(PlayerTest, shouldReturnAsPlayerSymbolIsO)
{
    std::shared_ptr<BoardI> board = std::make_shared<Board>();
    std::unique_ptr<Player> sut = std::make_unique<Player>(PlayerSymbol::O, board);
    
    EXPECT_EQ(sut->getPlayerSymbol(), PlayerSymbol::O);
}

TEST_F(PlayerTest, shouldReturnAsPlayerSymbolIsX)
{
    std::shared_ptr<BoardI> board = std::make_shared<Board>();
    std::unique_ptr<Player> sut = std::make_unique<Player>(PlayerSymbol::X, board);
    
    EXPECT_EQ(sut->getPlayerSymbol(), PlayerSymbol::X);
}

// TEST_F(PlayerTest, b)
// {
//     std::shared_ptr<BoardI> board = std::make_shared<Board>();
//     std::unique_ptr<Player> sut = std::make_unique<Player>(PlayerSymbol::X, board);
//     //EXPECT_EQ(sut->setPlayerBoard(board), sutboard);
// }
