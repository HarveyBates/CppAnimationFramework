#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>


class Square{
    float width;
    float height;
    Vector2 positon;
    float lineWidth;
    Color color;
    std::vector<std::pair<float, float>> coordiantes;
    
public:
    void set_width(float w);
    void set_height(float h);
    void set_coordinates(std::vector<std::pair<float, float>> coords);
    float get_width();
    float get_height();
    Vector2 get_position();
    std::vector<std::pair<float, float>> get_coordiantes();
    void draw(Vector2 position);
    void draw(Vector2 position, float height, float width, float lineWidth, Color color);
};


class Circle{
    float radius, resolution = 600.0f;
    float lineWidth = 2.0f;
    Color color = WHITE;
    Vector2 position;
    std::vector<std::pair<float, float>> coordinates;
public:
    void set_radius(float r);
    void set_position(Vector2 pos);
    void set_resolution(float res);
    void set_coordinates(std::vector<std::pair<float, float>> coords);
    float get_radius();
    float get_resolution();
    Vector2 get_position();
    std::vector<std::pair<float, float>> get_coordinates();
    
    void draw(Vector2 position, float radius, float resolution, float lineWidth, Color color);
    
    void update(std::vector<std::pair<float, float>> prevCoordinates, std::vector<std::pair<float, float>> coordinates);
};
