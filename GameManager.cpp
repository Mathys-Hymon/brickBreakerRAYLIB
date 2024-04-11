#include "GameManager.h"
#include "raylib.h"
#include <iostream>
#include <string>

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
    
    if (!gameOver) {
        
        std::string scoreString = std::to_string(score);
        DrawText(scoreString.c_str(), 150, 10, 20, BLACK);
        DrawText("Score : ", 10, 10, 20, BLACK);
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
        DrawText("Game Over", GetScreenWidth() / 2 - MeasureText("Game Over", 20) / 2, GetScreenHeight() / 2, 20, RED);
    }
}

void GameManager::CreateBricks(int numRows)
{
    const int numCols = 20;
    const float brickWidth = GetScreenWidth() / numCols;
    const float brickHeight = 24.0f;
    const float startX = (GetScreenWidth() - numCols * (brickWidth + 2)) / 2.0f;
    const float startY = 50.0f;

    bricks.clear();
    for (int i = 0; i < numRows; ++i) {
        std::vector<brick> row;
        for (int j = 0; j < numCols; ++j) {
            float x = startX + j * (brickWidth + 2);
            float y = startY + i * (brickHeight + 2);
            row.push_back(brick(x, y, brickWidth, brickHeight, 2));
        }
        bricks.push_back(row);
    }
}

void GameManager::CheckCollisions()
{
    for (int row = 0; row < bricks.size(); ++row) {
        for (int col = 0; col < bricks[row].size(); ++col) {
            // Vérifie si la brique n'est pas déjà détruite
            if (bricks[row][col].DestructionState() > 0) {
                if (bricks[row][col].checkCollision(Ball)) {
                    score += 10;
                }
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
