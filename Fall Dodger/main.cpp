#include <raylib.h>
#include <raymath.h>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My first Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Functionalities
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Text Here", 15, 20, 20, DARKGRAY);
        // Draw here
        EndDrawing();
    }

    CloseWindow();
    return 0;
}