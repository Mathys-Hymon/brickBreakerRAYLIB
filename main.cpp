#include "raylib.h"
#include "ball.h"
#include "paddle.h"
#include "GameManager.h"

#include <iostream>

int main() {

    InitWindow(600, 800, "BRICK BREAKER");
    SetTargetFPS(60);

    ball Ball(10.0f, { 3.0f, -3.0f }, { 300, 400 }, BLUE);
    paddle playerPaddle(150, 25, 5.0f);

    while (!WindowShouldClose()) {
        BeginDrawing();

        playerPaddle.Update();
        playerPaddle.Draw();

        Ball.Update(GetFrameTime());
        Ball.Draw();
        Ball.CheckCollision(playerPaddle);
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}