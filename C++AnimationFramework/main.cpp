#include "raylib.h"
#include <iostream>
#include <math.h>

const int screenWidth = 800;
const int screenHeight = 450;


class Grid{
    float hLines = 10;
    float vLines = 10;
public:
    void set_horizontal_lines(float num){
        num = hLines;
    }
    void set_vertical_lines(float num){
        num = vLines;
    }
    void draw(Vector2 gridStart,
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
};


class Origin{
    Vector2 position;
public:
    Vector2 get_position(){return position;}
    void draw(Vector2 postion,
              bool arrows,
              float arrowX,
              float arrowY,
              Color color){
        
        DrawCircleV(postion, 4.0f, color);
        
        if(arrows){
            // Construct Lines
            Vector2 extentX = {postion.x + arrowX, postion.y};
            DrawLineEx(postion, extentX, 2.0f, color);
            Vector2 extentY = {postion.x, postion.y - arrowY};
            DrawLineEx(postion, extentY, 2.0f, color);
            
            // Construct Arrowheads
            // X-arrowhead
            Vector2 revUpArrow = {postion.x + arrowX - 10.0f, postion.y + 5.0f};
            Vector2 revDownArrow = {postion.x + arrowX - 10.0f, postion.y - 5.0f};
            DrawLineEx(extentX, revUpArrow, 2.0f, color);
            DrawLineEx(extentX, revDownArrow, 2.0f, color);
            
            // Y-arrowHead
            Vector2 revLArrow = {postion.x + 5.0f, postion.y - arrowY + 10.0f};
            Vector2 revRArrow = {postion.x - 5.0f, postion.y - arrowY + 10.0f};
            DrawLineEx(extentY, revLArrow, 2.0f, color);
            DrawLineEx(extentY, revRArrow, 2.0f, color);
        }
    }
};


class Sinewave{
    float freqency, amplitude;
public:
    void set_frequecy(float freq){
        freq = freqency;
    }
    void set_amplitude(float amp){
        amp = amplitude;
    }
    float get_frequency(){return freqency;}
    float get_amplitude(){return amplitude;}
    
    void draw(Vector2 startPoint,
              float width,
              float offset,
              float amp,
              float xPos,
              float freq){
        
        amplitude = amp;
        freqency = freq;
        
        for(float x = startPoint.x; x < startPoint.x + width; ++x){
            float y = amp * sin((x * (PI/180)) * freq + xPos) + offset;
            Vector2 point = {x, y};
            DrawCircleV(point, 2.0f, RED);
        }
    }
};


int main(void)
{
    InitWindow(screenWidth, screenHeight, "Window");

    SetTargetFPS(60);

    Vector2 gridStart = {50, 50};
    
    Vector2 originPos = {50, 50};
    
    float gridWidth = 300.0f;
    float gridHeight = 320.0f;
    
    float hLines = 10.0f;
    float vLines = 10.0f;
    
    float xPos = 10.0f;
    float freq = 2.0f;
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        
        ClearBackground(BLACK);
        
        Grid grid;
        grid.draw(gridStart, gridWidth, gridHeight, hLines, vLines, 1.0f, LIGHTGRAY);
        
        Origin origin;
        Vector2 position = {originPos.x, originPos.y + gridHeight};
        origin.draw(position, true, gridWidth / 2.0f, gridHeight  / 2.0f, WHITE);
        
        Vector2 sineStart = {400, 200};
        Sinewave sinewave;
        sinewave.draw(sineStart, 200.0f, 100.0f, 50.0f, xPos, freq);
        xPos += 0.01f;
        DrawText(std::to_string(sinewave.get_frequency()).c_str(), 650, 100, 25, WHITE);
        DrawText(std::to_string(sinewave.get_amplitude()).c_str(), 650, 140, 25, WHITE);
        
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
