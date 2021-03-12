#include "main.h"

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Window");

    const int frameRate = 60;
    SetTargetFPS(frameRate);

	Camera3D camera = { 0 };
	camera.position = (Vector3){ (float)screenHeight / 2, (float)screenWidth / 2, 5.0f };  // Camera position
	camera.target = (Vector3){0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = (Vector3){ 0.0f, 2.0f, 20.0f };          // Camera up vector (rotation towards targe
	camera.fovy = 10.0f;                                // Camera field-of-view Y
	camera.type = CAMERA_PERSPECTIVE;
	
	int scl = 20;
	const int cols = screenWidth / scl;
	const int rows = screenHeight / scl;
	
    while (!WindowShouldClose())
    {
        BeginDrawing();
		BeginMode3D(camera);
        ClearBackground(BLACK);
			
		for(int y = 0; y <= rows; y++){
			for(int x = 0; x <= cols; x++){
				// Vertical Lines
				DrawLine3D({(float)x*scl, (float)y*scl, 0.0f}, 
						{(float)x*scl, (float)y+1*scl, 0.0f}, WHITE);

				// Horizontal Lines
				DrawLine3D({(float)x*scl, (float)y*scl, 0.0f}, 
						{(float)(x+1)*scl, (float)y*scl, 0.0f}, WHITE);

				// Diagonal Lines
				DrawLine3D({(float)x*scl, (float)y*scl, 0.0f}, 
						{(float)(x+1)*scl,(float)(y+1)*scl, 0.0f}, WHITE);
			}
		}
		EndMode3D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
