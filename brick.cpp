#include "brick.h"

brick::brick(Vector2 position, Vector2 dimension, Vector2 mapPosition, int lives) : position(position), dimension(dimension), mapPosition(mapPosition), lives(lives)
{
}

void brick::Update()
{
}

void brick::Draw() const
{
	DrawRectangleV(position, dimension, BLUE);
}
