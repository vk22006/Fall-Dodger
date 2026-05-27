#include <raylib.h>

#include "Paddle.h"
#include "Enemy.h"
#include "Game.h"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;

int Game::getScore() { return score; }

bool Game::collision(Paddle& pad, Enemy& enemy)
{
    Vector2 enemyPos = enemy.getPosition();
    Vector2 padPos = pad.getPosition();

    if (
        enemyPos.x + enemy.getWidth() >= padPos.x &&
        enemyPos.x <= padPos.x + pad.getWidth() &&

        enemyPos.y + enemy.getHeight() >= padPos.y &&
        enemyPos.y <= padPos.y + pad.getHeight()
        )
    {
        return true;
    }

    return false;
}
void Game::scoring(float dt) {
    score += 10 * dt;
}
void Game::draw_score() {
    DrawText(TextFormat("%d", (int)score), 20, 30, 25, SKYBLUE);
}
void Game::reset() {
    score = 0.0f;
}