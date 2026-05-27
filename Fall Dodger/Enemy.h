#pragma once
class Enemy {
private:
    int width = 40;
    int height = 35;
    float speed = 150.0f;

    Vector2 position;

    float prevSpeed;

public:

    Enemy(float x, float y);

    Vector2 getPosition();
    int getWidth();
    int getHeight();

    void draw();
    void movement(float dt);
    void increaseTimedDifficulty(float dt);
    void reset(float yPos);
    void respawn();
    void pause();
    void resume();
};

