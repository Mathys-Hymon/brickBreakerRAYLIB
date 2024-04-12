#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include <vector>

class GameManager 
{
private:
    ball& Ball;
    paddle& Player;
    std::vector<std::vector<brick>> bricks;
    int score;
    int lifes;
    bool gameOver;
    bool gameStarted;
    void CreateBricks(int numRows);
    void CheckCollisions();

public:
    GameManager(ball& Ball, paddle& Player);
    ~GameManager();
    void Initialize(int bricksRow);
    void Update(float deltaTime);
    void Draw() const;
    void NewRound();
};