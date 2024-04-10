#pragma once
#include "raylib.h"

class paddle {

private:
    float width;
    float height;
    float speed;
    Vector2 position;

public:
    paddle(float width, float height, float speed);

    float GetWidth() const;
    float GetHeight() const;
    Vector2 GetPosition() const;

    void Update(float deltaTime);
    void Draw() const;
};

