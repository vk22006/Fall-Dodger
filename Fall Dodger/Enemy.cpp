#include <raylib.h>
#include "Enemy.h"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;

Enemy::Enemy(float x, float y) {
    position = { x,y };
    prevSpeed = speed;
}

Vector2 Enemy::getPosition() { return position; }
int Enemy::getWidth() { return width; }
int Enemy::getHeight() { return height; }

void Enemy::draw() {
    DrawRectangle(position.x, position.y, width, height, RED);
}
void Enemy::movement(float dt) {
    position.y += speed * dt;
}
void Enemy::increaseTimedDifficulty(float dt) {
    if (speed < 400)
    {
        speed += 5 * dt;
    }
    prevSpeed = speed;
}
void Enemy::reset(float yPos) {
    position.x = GetRandomValue(0, SCREEN_WIDTH - width);
    position.y = yPos;
}
void Enemy::respawn()
{
    if (position.y >= SCREEN_HEIGHT)
    {
        reset(GetRandomValue(-300, -100));
    }
}
void Enemy::pause() {
    speed = 0.0f;
}
void Enemy::resume() {
    speed = prevSpeed;
}

