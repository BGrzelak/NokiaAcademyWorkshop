#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "inputMock.hpp"

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

TEST_F(GameTest, shouldReturnSettedXWonState)
{
    std::unique_ptr<Game> sut = std::make_unique<Game>();
    sut->setState(GameState::XWon);
    EXPECT_EQ(sut->getState(), GameState::XWon);
}

TEST_F(GameTest, shouldReturnPlayersSymbolOnFieldSettedByPlayer)
{
    testing::NaggyMock<InputMock> mockInput;
    Coordinates c;
    c.row = 1;
    c.column = 1;
    std::shared_ptr<Board> board = std::make_shared<Board>();
    std::unique_ptr<Player> player1 = std::make_unique<Player>(PlayerSymbol::X, mockInput, board);
    std::unique_ptr<Player> player2 = std::make_unique<Player>(PlayerSymbol::O, mockInput, board);
    std::unique_ptr<Game> sut = std::make_unique<Game>(player1, player2, board);
    ON_CALL(mockInput, getInput()).WillByDefault(testing::Return(c));

    board->setField(c, Field::O);
    sut->askPlayerForMove(player1);
    EXPECT_EQ(board->getField(c), Field::X);
}

TEST_F(GameTest, a)
{
        testing::NaggyMock<InputMock> mockInput;
    Coordinates c;
    c.row = 1;
    c.column = 1;
    std::shared_ptr<Board> board = std::make_shared<Board>();
    std::unique_ptr<Player> player1 = std::make_unique<Player>(PlayerSymbol::X, mockInput, board);
    std::unique_ptr<Player> player2 = std::make_unique<Player>(PlayerSymbol::O, mockInput, board);
    std::unique_ptr<Game> sut = std::make_unique<Game>(player1, player2, board);
    ON_CALL(mockInput, getInput()).WillByDefault(testing::Return(c));

    board->setField(c, Field::O);
    sut->askPlayerForMove(player1);
    EXPECT_EQ(board->getField(c), Field::X);
    EXPECT_EQ(sut->check_win(), GameState::XWon);
}