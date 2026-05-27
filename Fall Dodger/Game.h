#pragma once

class Game {
private:
    float score = 0.0f;
public:

    int getScore();

    bool collision(Paddle& pad, Enemy& enemy);
    void scoring(float dt);
    void draw_score();
    void reset();
};

