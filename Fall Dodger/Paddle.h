#pragma once

class Paddle {
private:
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;

    int width = 150;
    int height = 40;
    float speed = 250.0f;
    Vector2 padPosition;

    KeyboardKey leftkey;
    KeyboardKey rightkey;

    Vector2 initialPosition;

public:
    Paddle(Vector2 position, KeyboardKey leftkey, KeyboardKey rightkey);

    Vector2 getPosition();
    int getWidth();
    int getHeight();

    void draw();
    void movement(float dt);
    void increaseTimedDifficulty(float dt);
    void collision();
    void reset();
};
