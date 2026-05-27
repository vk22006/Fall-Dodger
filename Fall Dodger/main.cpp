#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>

#include "Paddle.h"
#include "Enemy.h"
#include "Game.h"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;

Paddle pad(
    { static_cast<float>((SCREEN_WIDTH / 2) - (150 / 2)), static_cast<float>(SCREEN_HEIGHT - 60) },
    KEY_LEFT, KEY_RIGHT);
std::vector<Enemy> enemies;
Game game;

enum GameState {
    TITLE,
    PLAYING,
    PAUSE,
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
            if (IsKeyPressed(KEY_SPACE)) currentState = PLAYING;
        }
        if (currentState == PLAYING) {
            pad.movement(dt);
            pad.increaseTimedDifficulty(dt);
            for (Enemy& enemy : enemies) enemy.movement(dt);
            for (Enemy& enemy : enemies) {
                enemy.respawn();
                enemy.increaseTimedDifficulty(dt);
            }

            pad.collision();
            for (Enemy& enemy : enemies) if (game.collision(pad, enemy)) currentState = GAMEOVER;
            game.scoring(dt);
            
            if (IsKeyPressed(KEY_P)) currentState = PAUSE;
        }

        if (currentState == PAUSE) {
            for (Enemy& enemy : enemies) enemy.pause();
            if (IsKeyPressed(KEY_R)) {
                for (Enemy& enemy : enemies) {
                    enemy.resume();
                    currentState = PLAYING;
                }
            }
        }

        if (currentState == GAMEOVER) {
            if (IsKeyPressed(KEY_ENTER)) {
                game.reset();
                currentState = TITLE;
            }
            pad.reset();
            for (int i = 0; i < enemies.size(); i++)
            {
                enemies[i].reset(-150 * i);  // Reset enemies' yPosition
            }
        }
        
        BeginDrawing();
        ClearBackground(BLACK);
        if (currentState == TITLE) {
            DrawText("FALL DODGER", 280, 200, 60, SKYBLUE);
            DrawText("Enter [SPACE] to Play", 350, 300, 25, RAYWHITE);
        }
        else if (currentState == PLAYING || currentState == PAUSE) {
            pad.draw();
            for (Enemy& enemy : enemies) enemy.draw();
            game.draw_score();

            if (currentState == PAUSE) {
                DrawRectangleLines(60, 25, 120, 30, GREEN);
                DrawText("PAUSED", 70, 30, 25, GREEN);
                DrawText("Enter [R] to Resume", 350, 250, 25, RAYWHITE);
            }
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