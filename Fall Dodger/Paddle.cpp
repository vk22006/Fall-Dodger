#include <raylib.h>
#include "Paddle.h"

Paddle::Paddle(Vector2 position, KeyboardKey leftkey, KeyboardKey rightkey) {
    padPosition = position;
    initialPosition = position;
    this->leftkey = leftkey;
    this->rightkey = rightkey;
}

Vector2 Paddle::getPosition() { return padPosition; }
int Paddle::getWidth() { return width; }
int Paddle::getHeight() { return height; }

void Paddle::draw() {
    DrawRectangle(padPosition.x, padPosition.y, width, height, RAYWHITE);
}
void Paddle::movement(float dt) {
    if (IsKeyDown(leftkey)) padPosition.x -= speed * dt;
    if (IsKeyDown(rightkey)) padPosition.x += speed * dt;
}
void Paddle::increaseTimedDifficulty(float dt) {
    speed += 10 * dt;
}
void Paddle::collision() {
    if (padPosition.x < 0.001) padPosition.x = 0;
    if (padPosition.x > SCREEN_WIDTH - width - 0.001) padPosition.x = SCREEN_WIDTH - width;
}
void Paddle::reset() {
    padPosition = initialPosition;
    speed = 250.0f;
}