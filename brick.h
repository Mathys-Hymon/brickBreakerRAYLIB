#pragma once
#include "raylib.h"
#include "ball.h"

class brick
{
private:
    Vector2 position;
    Vector2 dimension;
    Vector2 mapPosition;
    int lives;
    int maxLives;
    Color color;

public:
    brick(float x, float y, float width, float height, int life);

    void Draw() const;
    int DestructionState() const;
    void SetColor(Color color);
    bool checkCollision(ball& _ball);
    Vector2 GetDimensions() const;
};

