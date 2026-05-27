#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;

class Paddle {
private:
    int width = 150;
    int height = 40;
    float speed = 250.0f;
    Vector2 padPosition;

    KeyboardKey leftkey;
    KeyboardKey rightkey;

public:
    Paddle(Vector2 position, KeyboardKey leftkey, KeyboardKey rightkey) {
        padPosition = position;
        this->leftkey = leftkey;
        this->rightkey = rightkey;
    }

    Vector2 getPosition() { return padPosition; }
    int getWidth() { return width; }
    int getHeight() { return height; }

    void draw() {
        DrawRectangle(padPosition.x, padPosition.y, width, height, RAYWHITE);
    }
    void movement(float dt) {
        if (IsKeyDown(leftkey)) padPosition.x -= speed * dt;
        if (IsKeyDown(rightkey)) padPosition.x += speed * dt;
    }
    void collision() {
        if (padPosition.x < 0.001) padPosition.x = 0;
        if (padPosition.x > SCREEN_WIDTH - width -0.001) padPosition.x = SCREEN_WIDTH - width;
    }
};

class Enemy {
private:
    int width = 40;
    int height = 35;
    float speed = 150.0f;

    Vector2 position;

public:

    Enemy(float x, float y) {
        position = { x,y };
    }

    Vector2 getPosition() { return position; }
    int getWidth() { return width; }
    int getHeight() { return height; }

    void draw() {
        DrawRectangle(position.x, position.y, width, height, RED);
    }
    void movement(float dt) {
        position.y += speed * dt;
    }
    void reset() {
        position.x = GetRandomValue(0, SCREEN_WIDTH - width);
        position.y = 20;
    }
    void respawn() {
        if (position.y >= SCREEN_HEIGHT)
        {
            reset();
        }
    }
};

class Game {
private:
    float score = 0.0f;
public:

    int getScore() { return score; }

    bool collision(Paddle& pad, Enemy& enemy)
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
    void scoring(float dt) {
        score += 10 * dt;
    }
    void draw_score() {
        DrawText(TextFormat("%d", (int)score), 20, 30, 25, SKYBLUE);
    }

};

Paddle pad(
    { static_cast<float>((SCREEN_WIDTH / 2) - (150 / 2)), static_cast<float>(SCREEN_HEIGHT - 60) },
    KEY_A, KEY_D);
std::vector<Enemy> enemies;
Game game;

enum GameState {
    TITLE,
    PLAYING,
    GAMEOVER
};

int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Fall Dodger");
    SetTargetFPS(60);

    GameState currentState = TITLE;

    //Loading enemies
    for (int i = 0; i < 5; i++) {
        enemies.push_back(
            Enemy(GetRandomValue(0, SCREEN_WIDTH - 40), -100 * i)
        );
    }

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        if (currentState == TITLE) {
            if (IsKeyPressed(KEY_SPACE)) {
                currentState = PLAYING;
            }
        }
        if (currentState == PLAYING) {
            pad.movement(dt);
            for (Enemy& enemy : enemies)
            {
                enemy.movement(dt);
            }
            for (Enemy& enemy : enemies) {
                enemy.respawn();
            }

            pad.collision();
            for (Enemy& enemy : enemies)
            {
                if (game.collision(pad, enemy))
                {
                    currentState = GAMEOVER;
                }
                
            }
            game.scoring(dt);
        }
        
        BeginDrawing();
        ClearBackground(BLACK);
        if (currentState == TITLE) {
            DrawText("FALL DODGER", 280, 200, 60, SKYBLUE);
            DrawText("Enter [SPACE] to Play", 350, 300, 25, RAYWHITE);
        }
        else if (currentState == PLAYING) {
            pad.draw();
            for (Enemy& enemy : enemies) {
                enemy.draw();
            }
            game.draw_score();
        }
        else if (currentState == GAMEOVER) {
            DrawText("GAME OVER", 280, 200, 60, RED);
            DrawText(TextFormat("Points Earned: %d", game.getScore()), 350, 300, 25, RAYWHITE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}