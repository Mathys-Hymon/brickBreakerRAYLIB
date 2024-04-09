#include "paddle.h"

paddle::paddle(float width, float height, float speed) : width(width), height(height), speed(speed), position{ GetScreenWidth() / 2.0f, GetScreenHeight() - 50.0f } {}

float paddle::GetWidth() const 
{ 
    return width; 

}
float paddle::GetHeight() const 
{ 
    return height; 
}
Vector2 paddle::GetPosition() const 
{ 
    return position; 
}

void paddle::Update() 
{
    float mouseX = GetMouseX();
    if (mouseX < 0 + width/2) {
        mouseX = 0 + width / 2;
    }
    if (mouseX > GetScreenWidth() - width / 2) {
        mouseX = GetScreenWidth() - width / 2;
    }
        position.x += 0.1 * (mouseX - position.x);
}

void paddle::Draw() const 
{
    DrawRectangle(position.x - width / 2, position.y - height / 2, width, height, RED);
}