#include "main.h"

const int screenWidth = 800;
const int screenHeight = 450;

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Window");

    const int frameRate = 60;
    SetTargetFPS(frameRate);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Main animation loop

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
