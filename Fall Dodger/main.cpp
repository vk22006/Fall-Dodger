#include <raylib.h>
#include <raymath.h>
#include <iostream>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;

class Paddle {
private:
    int width = 150;
    int height = 40;
    float speed = 20.0f;
    Vector2 padPosition;

    KeyboardKey leftkey;
    KeyboardKey rightkey;

public:
    Paddle(Vector2 position, KeyboardKey leftkey, KeyboardKey rightkey) {
        padPosition = position;
        this->leftkey = leftkey;
        this->rightkey = rightkey;
    }
    void draw() {
        DrawRectangle(padPosition.x, padPosition.y, width, height, RED);
    }
    void movement(float dt) {
        if (IsKeyDown(leftkey)) padPosition.x -= speed * dt;
        if (IsKeyDown(rightkey)) padPosition.x += speed * dt;
    }
};

Paddle pad(
    { static_cast<float>((SCREEN_WIDTH / 2) - (150 / 2)), static_cast<float>(SCREEN_HEIGHT - 60) },
    KEY_A, KEY_D);

int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Fall Dodger");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        pad.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}