#include "main.h"

const int screenWidth = 800;
const int screenHeight = 450;

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Window");

    int frameRate = 60;
    SetTargetFPS(frameRate);

    Vector2 gridStart = {50, 50};
    
    Vector2 originPos = {50, 50};
    
    float gridWidth = 300.0f;
    float gridHeight = 320.0f;
    
    float hLines = 10.0f;
    float vLines = 10.0f;
    
    float xPos = 10.0f;
    float freq = 2.0f;
    
    float radius = 180.0f;
    float step = 0;
    
    Vector2 circPos = {575.0f, screenHeight / 2};
    float resolution = 600.0f;
    
    std::vector<std::pair<float, float>> newPos;
    
    int numFrames = 0;
    
    while (!WindowShouldClose() && numFrames < 10000)    // Detect window close button or ESC key
    {
        BeginDrawing();
        
        ClearBackground(BLACK);
        
        Grid grid;
        grid.draw(gridStart, gridWidth, gridHeight, hLines, vLines, 1.0f, LIGHTGRAY);
        
        Origin origin;
        Vector2 position = {originPos.x, originPos.y + gridHeight};
        origin.draw(position, true, gridWidth / 2.0f, gridHeight  / 2.0f, WHITE);
        
        Vector2 sineStart = {50, 50};
        Sinewave sinewave;
        sinewave.draw(sineStart, 300.0f, 200.0f, 100.0f, xPos, freq, YELLOW);
        Sinewave sinewave1;
        sinewave1.draw(sineStart, 300.0f, 200.0f, 100.0f, xPos + 10.0f, freq, BLUE);
        
        xPos += 0.05f;
//        DrawText(std::to_string(sinewave.get_frequency()).c_str(), 100, 400, 25, WHITE);
//        DrawText(std::to_string(sinewave.get_frequency()).c_str(), 100, 400, 25, WHITE);
        DrawText("x", 300/2 + 45, 375, 25, WHITE);
        DrawText("y", 25, gridHeight / 2 + 40, 25, WHITE);
        
        Circle circle;
        circle.draw(circPos, radius, resolution, 2.0f, BLACK);
        
        Square square;
        square.draw({500.0f, screenHeight/3}, 150.0f, 150.0f, 2.0f, BLUE);
        
        if(numFrames > 800){
            std::vector<std::pair<float, float>> sqrCoordiantes = square.get_coordiantes();
            std::vector<std::pair<float, float>> circCoordiantes = circle.get_coordinates();
            
            Morph morph;
            newPos = morph.update(circCoordiantes, sqrCoordiantes, step, 100, 600.0f, 2.0f, BLUE);
            circle.update(circCoordiantes, newPos);
            
            if(step < 100.0f){
                step+= 1.0f;
            }
            else{
                step = 100.0f;
            }
        }
        
        EndDrawing();
        
        numFrames++;
    }

    CloseWindow();

    return 0;
}
