#pragma once
#include "raylib.h"

class ball
{
private:
    float radius;
    Color color;
    Vector2 velocity;
    Vector2 position;

public:
    ball(float radius, Vector2 velocity, Vector2 position, Color color);

    float GetRadius() const;
    Vector2 GetVelocity() const;
    Vector2 GetPosition() const;

    void SetVelocity(Vector2 velocity);
    void SetPosition(Vector2 position);

    void Update(float deltaTime);
    void Draw() const;
};