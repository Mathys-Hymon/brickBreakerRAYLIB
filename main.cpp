#include "raylib.h"
#include "ball.h"
#include "paddle.h"
#include <iostream>

using namespace std;

int main() {

    InitWindow(600, 800, "BRICK BREAKER");
    SetTargetFPS(60);

    ball Ball(10.0f, { 3.0f, -3.0f }, { 300, 400 }, BLUE);
    paddle playerPaddle(100.0f, 20.0f, 5.0f);

    while (!WindowShouldClose()) {
        BeginDrawing();

        playerPaddle.Update();
        playerPaddle.Draw();

        Ball.Update(GetFrameTime());
        Ball.Draw();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}