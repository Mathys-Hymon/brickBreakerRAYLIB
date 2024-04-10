#pragma once
#include "raylib.h"
#include "paddle.h"

class ball
{
private:
    float radius;
    
    Color color;
    Vector2 velocity;
    Vector2 maxVelocity;
    Vector2 position;

public:
    ball(float radius, Vector2 velocity, Vector2 position, Color color);

    float GetRadius() const;
    Vector2 GetVelocity() const;
    Vector2 GetPosition() const;

    void SetVelocity(Vector2 velocity);
    void SetPosition(Vector2 position);
    void CheckCollision(const paddle& pad);

    void Update(float deltaTime);
    void Draw() const;
};