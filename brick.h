#pragma once
#include "raylib.h"

class brick
{
private:
    Vector2 dimension;
    Vector2 position;
    float radius;
    Color color;

public:
    brick(float radius, Vector2 velocity, Vector2 position, Color color);

    float GetRadius() const;
    Vector2 GetVelocity() const;
    Vector2 GetPosition() const;

    void SetVelocity(Vector2 velocity);
    void SetPosition(Vector2 position);

    void Update(float deltaTime);
    void Draw() const;
};

