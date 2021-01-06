#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>


class Grid{
    float hLines = 10;
    float vLines = 10;
public:
    void set_horizontal_lines(float num);
    void set_vertical_lines(float num);
    void draw(Vector2 gridStart, float extentWidth, float extentHeight, float hLines, float vLines, float lineWidth, Color lineColor);
};


class Origin{
    Vector2 position;
public:
    Vector2 get_position();
    void draw(Vector2 postion, bool arrows, float arrowX, float arrowY, Color color);
};
