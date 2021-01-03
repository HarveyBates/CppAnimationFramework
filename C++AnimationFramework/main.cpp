#include "raylib.h"
#include <math.h>

const int screenWidth = 800;
const int screenHeight = 450;

void draw_grid(Vector2 gridStart,
               float extentWidth,
               float extentHeight,
               float hLines,
               float vLines,
               float lineWidth,
               Color lineColor){
    
    float densityH = extentHeight / hLines;
    float densityV = extentWidth / vLines;
    
    Vector2 startHLine = {gridStart.x, gridStart.y};
    Vector2 endHLine = {extentWidth + gridStart.x, gridStart.y};
    DrawLineEx(startHLine, endHLine, lineWidth, lineColor);
    for(int i = 0; i < hLines; i++){
        Vector2 startHLine = {gridStart.x, gridStart.y + densityH};
        Vector2 endHLine = {extentWidth + gridStart.x, gridStart.y + densityH};
        DrawLineEx(startHLine, endHLine, lineWidth, lineColor);
        densityH += extentHeight / hLines;
    }

    densityH = extentHeight / hLines;
    Vector2 startVLine = {gridStart.x, gridStart.y};
    Vector2 endVLine = {gridStart.x, extentHeight + gridStart.y};
    DrawLineEx(startVLine, endVLine, lineWidth, lineColor);
    for(int i = 0; i < vLines; i++){
        Vector2 startVLine = {gridStart.x + densityV, gridStart.y};
        Vector2 endVLine = {gridStart.x + densityV, extentHeight + gridStart.y};
        DrawLineEx(startVLine, endVLine, lineWidth, lineColor);
        densityV += extentWidth / vLines;
    }
}


void draw_origin(Vector2 origin,
                 bool arrows,
                 float arrowX,
                 float arrowY,
                 Color color){
    
    DrawCircleV(origin, 4.0f, color);
    
    if(arrows){
        // Construct Lines
        Vector2 extentX = {origin.x + arrowX, origin.y};
        DrawLineEx(origin, extentX, 2.0f, color);
        Vector2 extentY = {origin.x, origin.y - arrowY};
        DrawLineEx(origin, extentY, 2.0f, color);
        
        // Construct Arrowheads
        // X-arrowhead
        Vector2 revUpArrow = {origin.x + arrowX - 10.0f, origin.y + 5.0f};
        Vector2 revDownArrow = {origin.x + arrowX - 10.0f, origin.y - 5.0f};
        DrawLineEx(extentX, revUpArrow, 2.0f, color);
        DrawLineEx(extentX, revDownArrow, 2.0f, color);
        
        // Y-arrowHead
        Vector2 revLArrow = {origin.x + 5.0f, origin.y - arrowY + 10.0f};
        Vector2 revRArrow = {origin.x - 5.0f, origin.y - arrowY + 10.0f};
        DrawLineEx(extentY, revLArrow, 2.0f, color);
        DrawLineEx(extentY, revRArrow, 2.0f, color);
    }
}

void insert_sine_wave(Vector2 startPoint,
                      float width,
                      float height,
                      float amp,
                      float xPos,
                      float freq){
    for(float x = startPoint.x; x < startPoint.x + width; ++x){
        float y = amp * sin((x * (PI/180)) * freq + xPos) + height;
        Vector2 point = {x, y};
        DrawCircleV(point, 2.0f, RED);
    }
}


int main(void)
{
    InitWindow(screenWidth, screenHeight, "Window");

    SetTargetFPS(60);

    Vector2 gridStart = {50, 50};
    
    float gridWidth = 300.0f;
    float gridHeight = 320.0f;
    
    float numHLines = 10.0f;
    float numVLines = 10.0f;
    
    float amp = 150.0f;
    float xPos = 10.0f;
    float freq = 2.0f;
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        
        ClearBackground(BLACK);
        
        draw_grid(gridStart, gridWidth, gridHeight, numHLines, numVLines, 1.0f, LIGHTGRAY);
        
        Vector2 origin = {gridStart.x, gridStart.y + gridHeight};
        
        draw_origin(origin, true, gridWidth / 2.0f, gridHeight  / 2.0f, WHITE);
        
        insert_sine_wave(gridStart, gridWidth, gridStart.y + (gridHeight / 2), amp, xPos, freq);
        
        EndDrawing();
        xPos += 0.05f;
    }

    CloseWindow();

    return 0;
}
