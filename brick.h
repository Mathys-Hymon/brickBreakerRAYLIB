#pragma once
#include "raylib.h"

class brick
{
private:
    Vector2 position;
    Vector2 dimension;
    Vector2 mapPosition;
    int lives;
    Color color;

public:
    brick(Vector2 position, Vector2 dimension, Vector2 mapPosition, int lives);

    void Update();
    void Draw() const;
};

