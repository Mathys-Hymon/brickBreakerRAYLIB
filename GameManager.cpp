#include "GameManager.h"

void GameManager::Initialize() {
    Ball.SetPosition({ 400.0f, 300.0f });
    CreateBricks(4);
    score = 0;
    gameOver = false;
}

void GameManager::Update(float deltaTime)
{
    Ball.Update(deltaTime);
    Player.Update(deltaTime);
    CheckCollisions();
    if (Ball.GetPosition().y > GetScreenHeight()) {
        lifes--;
        gameOver = true;
    }
}

void GameManager::Draw() const
{
    DrawText("Score: " + score, 10, 10, 20, WHITE);
    if (!gameOver) {
        Ball.Draw();
        Player.Draw();

        for (const auto& row : bricks) {
            for (const auto& _brick : row) {
                if (_brick.DestructionState() > 0) {
                    _brick.Draw();
                }
            }
        }
    }
    else {
        DrawText("Game Over", GetScreenWidth() / 2 - MeasureText("Game Over", 20) / 2, GetScreenHeight() / 2, 20, RED);
    }
}

void GameManager::CreateBricks(int numRows)
{
    const int numCols = 10;
    const float brickWidth = 80.0f;
    const float brickHeight = 24.0f;
    const float brickPadding = 2.0f;
    const float startX = (GetScreenWidth() - numCols * (brickWidth + brickPadding)) / 2.0f;
    const float startY = 50.0f;

    bricks.clear();
    for (int i = 0; i < numRows; ++i) {
        std::vector<brick> row;
        for (int j = 0; j < numCols; ++j) {
            float x = startX + j * (brickWidth + brickPadding);
            float y = startY + i * (brickHeight + brickPadding);
            row.push_back(brick(x, y, brickWidth, brickHeight, 0));
        }
        bricks.push_back(row);
    }
}

void GameManager::CheckCollisions()
{
    int row = static_cast<int>(Player.GetPosition().y / bricks[0][0].GetDimensions().y);
    int col = static_cast<int>(Player.GetPosition().x / bricks[0][0].GetDimensions().x);

    if (row >= 0 && row < bricks[0].size()-1 && col >= 0 && col < bricks.size() - 1) {
        if (bricks[row][col].DestructionState() > 0) {
            if (bricks[row][col].checkCollision(Ball)) {
                score += 10;
            }
        }
    }
}

void GameManager::Restart()
{
	Initialize();
}

GameManager::GameManager(ball& Ball, paddle& Player) : Ball(Ball), Player(Player)
{
}

GameManager::~GameManager()
{
    int numRows = bricks.size() - 1;
    for (int i = 0; i < numRows; ++i) {
        bricks[i].clear();
    }
    bricks.clear();
}
