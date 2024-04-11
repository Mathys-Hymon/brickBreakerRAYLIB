#include "raylib.h"
#include "ball.h"
#include "paddle.h"
#include "GameManager.h"

int main() {
    const int screenWidth = 600;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Brick Breaker");
    SetTargetFPS(60);

    ball gameBall(10.0f, {4, 4}, { screenWidth / 2.0f, screenHeight - 50.0f }, RED);
    paddle playerPaddle(100.0f, 20.0f, 5.0f);

    GameManager gameManager(gameBall, playerPaddle);

    gameManager.Initialize();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        gameManager.Update(GetFrameTime());
        gameManager.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}