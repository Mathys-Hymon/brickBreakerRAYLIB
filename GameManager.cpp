#include "GameManager.h"
#include "raylib.h"
#include <iostream>
#include <string>

void GameManager::Initialize(int bricksRow) {
    Ball.SetPosition({ 400.0f, 300.0f });
    CreateBricks(bricksRow);
    gameStarted = false;
    gameOver = false;
}

void GameManager::Update(float deltaTime)
{
    if (!gameOver) {

        if (!gameStarted) {
            Vector2 ballPos = { Player.GetPosition().x, Player.GetPosition().y - 50};
           Ball.SetPosition(ballPos);
            Player.Update(deltaTime);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                gameStarted = true;
                Ball.SetVelocity({ 0, -Ball.GetVelocity().y});
            }

        }
        else {
            Ball.Update(deltaTime);
            Player.Update(deltaTime);
            CheckCollisions();
            if (Ball.GetPosition().y > GetScreenHeight()) {
                lifes--;
                if (lifes <= 0) {
                    gameOver = true;
                }
                else {
                    gameStarted = false;
                }
            }
        }


    }
    else {
        if (IsKeyPressed(KEY_ENTER)) {
            gameStarted = false;
            Initialize(5);
            score = 0;
            lifes = 3;
        }
    }

}

void GameManager::Draw() const
{
    std::string scoreString = std::to_string(score);
    if (!gameOver) {
        
        
        std::string lifesString = std::to_string(lifes);
        DrawText(scoreString.c_str(), 100, 10, 20, BLACK);
        DrawText(lifesString.c_str(), GetScreenWidth() - 50, 10, 20, BLACK);
        DrawText("Score : ", 10, 10, 20, BLACK);
        DrawText("Life : ", GetScreenWidth() - 150, 10, 20, BLACK);
        Ball.Draw();
        Ball.CheckCollision(Player);
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
        DrawText("Game Over", GetScreenWidth() / 2 - MeasureText("Game Over", 20) / 2, GetScreenHeight() / 4, 20, RED);
        DrawText(scoreString.c_str(), GetScreenWidth() / 2 - MeasureText(scoreString.c_str(), 20) / 2, GetScreenHeight() / 3, 20, BLACK);
        DrawText("Your score : ", GetScreenWidth() / 2 - MeasureText("Your score : ",20) /2, (GetScreenHeight() / 3) - 30, 20, BLACK);
        DrawText("ENTER to restart", GetScreenWidth() / 2 - MeasureText("ENTER to restart", 20) / 2, GetScreenHeight() / 2, 20, RED);
    }
}

void GameManager::CreateBricks(int numRows)
{
    const int numCols = 10;
    const float brickWidth = GetScreenWidth() / numCols;
    const float brickHeight = 24.0f;
    const float startX = (GetScreenWidth() - numCols * brickWidth + 60) / 2.0f;
    const float startY = 50.0f;

    bricks.clear();
    for (int i = 0; i < numRows; ++i) {
        std::vector<brick> row;
        for (int j = 0; j < numCols; ++j) {
            float x = startX + j * (brickWidth);
            float y = startY + i * (brickHeight);
            row.push_back(brick(x, y, brickWidth, brickHeight, 1));
        }
        bricks.push_back(row);
    }
}

void GameManager::CheckCollisions()
{
    int brickAlive = 0;
    for (int row = 0; row < bricks.size(); ++row) {
        for (int col = 0; col < bricks[row].size(); ++col) {
            if (bricks[row][col].DestructionState() > 0) {
                brickAlive += 1;
                if (bricks[row][col].checkCollision(Ball)) {
                    score += 10;
                }
            }
        }
    }

    if (brickAlive == 0) {
        NewRound();
    }
}

void GameManager::NewRound()
{
    gameStarted = false;

    if (bricks.size() < 14) {
        Initialize(bricks.size() + 3);
    }
    else {
        Initialize(14);
    }

}

GameManager::GameManager(ball& Ball, paddle& Player) : Ball(Ball), Player(Player), lifes(3)
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
