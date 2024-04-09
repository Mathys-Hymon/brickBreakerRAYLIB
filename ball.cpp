#include "ball.h"

ball::ball(float radius, Vector2 velocity, Vector2 position, Color color) : radius(radius), velocity(velocity), position(position), color(color) {}

float ball::GetRadius() const 
{ 
    return radius; 
}

Vector2 ball::GetVelocity() const 
{ 
    return velocity;
}

Vector2 ball::GetPosition() const 
{
    return position; 
}

void ball::SetVelocity(Vector2 velocity) 
{ 
    this->velocity = velocity; 
}

void ball::SetPosition(Vector2 position) 
{
    this->position = position; 
}

void ball::Update(float deltaTime) 
{
    position.x += velocity.x * 50 * deltaTime;
    position.y += velocity.y * 50 * deltaTime;

    if (position.x <= 0) {
        position.x = 0 + radius / 2;
        velocity.x *= -1;
    }
    if (position.x >= GetScreenWidth()) {
        position.x = GetScreenWidth() - radius / 2;
        velocity.x *= -1;
    }
    if (position.y <= 0) {
        position.y = 0 + radius / 2;
        velocity.y *= -1;
    }
    if (position.y >= GetScreenHeight()) {
        position.y = GetScreenHeight() - radius / 2;
        velocity.y *= -1;
    }
}

void ball::Draw() const 
{
    DrawCircleV(position, radius, color);
}