#include "main.h"

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Window");

    const int frameRate = 60;
    SetTargetFPS(frameRate);

	Camera2D camera;

    while (!WindowShouldClose())
    {
        BeginDrawing();
		BeginMode2D(camera);
		ClearBackground(WHITE);

		DrawRectangle((screenWidth / 2) - 50, (screenHeight / 2) - 50, 50, 50, BLACK);
			
		EndMode3D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
