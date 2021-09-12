#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "game.hpp"

class GameTest : public ::testing::Test
{
    protected:
    GameTest() {};
    ~GameTest() override {};

    void SetUp() override {};
    void TearDown() override {};
};

TEST_F(GameTest, shouldReturnInPrograssStateForNewGame)
{
    std::unique_ptr<Game> sut = std::make_unique<Game>();
    EXPECT_EQ(sut->getState(), GameState::InProgress);
}

TEST_F(GameTest, b)
{
    std::unique_ptr<Game> sut = std::make_unique<Game>();
    sut->setState(GameState::XWon);
    EXPECT_EQ(sut->getState(), GameState::XWon);
}
