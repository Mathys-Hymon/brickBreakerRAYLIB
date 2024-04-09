#pragma once
#include "raylib.h"

class paddle {
public:
    paddle(float width, float height, float speed);

    float GetWidth() const;
    float GetHeight() const;
    Vector2 GetPosition() const;

    void Update();
    void Draw() const;

private:
    float width;
    float height;
    float speed;
    Vector2 position;
};

