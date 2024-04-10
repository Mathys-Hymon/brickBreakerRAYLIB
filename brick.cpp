#include "brick.h"

brick::brick(float x, float y, float width, float height, int life) : position({x,y}), dimension({width,height}),lives(life), maxLives(life)
{
}



void brick::Draw() const
{
    if (lives == maxLives) {
        DrawRectangle(position.x - dimension.x / 2, position.y - dimension.y / 2, dimension.x, dimension.y, GREEN);
    }
    else if (lives >= maxLives / 2) {
        DrawRectangle(position.x - dimension.x / 2, position.y - dimension.y / 2, dimension.x, dimension.y, DARKGREEN);
    }
    else if (lives >= maxLives / 3) {
        DrawRectangle(position.x - dimension.x / 2, position.y - dimension.y / 2, dimension.x, dimension.y, RED);
    }
    else {
        DrawRectangle(position.x - dimension.x / 2, position.y - dimension.y / 2, dimension.x, dimension.y, BEIGE);
    }
        
}

int brick::DestructionState() const
{
	return lives;
}

bool brick::checkCollision(ball& _ball)
{
    if (position.x - (dimension.x / 2) < _ball.GetPosition().x + (_ball.GetRadius() / 2) &&
        position.x + (dimension.x / 2) > _ball.GetPosition().x - (_ball.GetRadius() / 2) &&
        position.y - (dimension.y / 2) < _ball.GetPosition().y + (_ball.GetRadius() / 2) &&
        position.y + (dimension.y / 2) > _ball.GetPosition().y - (_ball.GetRadius() / 2)) {

        // GAUCHE
        if (_ball.GetPosition().x - (_ball.GetRadius() / 2) <= position.x - (dimension.x / 2)) {
            _ball.SetVelocity({ -_ball.GetVelocity().x, _ball.GetVelocity().y });
            _ball.SetPosition({ position.x - (_ball.GetRadius() / 2), _ball.GetPosition().y });
        }
        // DROITE
        else if (_ball.GetPosition().x + (_ball.GetRadius() / 2) >= position.x + (dimension.x / 2)) {
            _ball.SetVelocity({ -_ball.GetVelocity().x, _ball.GetVelocity().y });
            _ball.SetPosition({ position.x + (_ball.GetRadius() / 2), _ball.GetPosition().y });
        }
        // HAUT
        if (_ball.GetPosition().y - (_ball.GetRadius() / 2) <= position.y - (dimension.y / 2)) {
            _ball.SetVelocity({ _ball.GetVelocity().x, -_ball.GetVelocity().y });
            _ball.SetPosition({ _ball.GetPosition().x, position.y - (_ball.GetRadius() / 2) });
        }
        // BAS
        else if (_ball.GetPosition().y + (_ball.GetRadius() / 2) >= position.y + (dimension.y / 2)) {
            _ball.SetVelocity({ _ball.GetVelocity().x, -_ball.GetVelocity().y });
            _ball.SetPosition({ _ball.GetPosition().x, position.y + (_ball.GetRadius() / 2) });
        }

        if (lives > 0) {
            lives--;
        }
        return true;
    }
    else {
        return false;
    }
}

Vector2 brick::GetDimensions() const
{
    return dimension;
}




