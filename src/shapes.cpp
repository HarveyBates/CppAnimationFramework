#include "shapes.h"

void Square::set_width(float w){
    width = w;
}

void Square::set_height(float h){
    height = h;
}

void Square::set_coordinates(std::vector<std::pair<float, float>> coords){
    coordiantes = coords;
}

float Square::get_width(){return width;}

float Square::get_height(){return height;}

Vector2 Square::get_position(){return positon;}

std::vector<std::pair<float, float>> Square::get_coordiantes(){return coordiantes;}

void Square::draw(Vector2 position){
    for(int i = 0; i < width; i++){
        coordiantes.push_back(std::make_pair(i + position.x, position.y));
        DrawCircleV({i + position.x, position.y}, lineWidth, color);
    }
    // Bottom
    for(int i = 0; i < width; i++){
        coordiantes.push_back(std::make_pair(i + position.x, position.y + height));
        DrawCircleV({i + position.x, position.y + height}, lineWidth, color);
    }
    // Left
    for(int i = 0; i < height; i++){
        coordiantes.push_back(std::make_pair(position.x, i + position.y));
        DrawCircleV({position.x, i + position.y}, lineWidth, color);
    }
    // Right
    for(int i = 0; i < height; i++){
        coordiantes.push_back(std::make_pair(position.x + width, i + position.y));
        DrawCircleV({position.x + width, i + position.y}, lineWidth, color);
    }
}

void Square::draw(Vector2 position, float height, float width, float lineWidth, Color color){
    // Top
    for(int i = 0; i < width; i++){
        coordiantes.push_back(std::make_pair(i + position.x, position.y));
        DrawCircleV({i + position.x, position.y}, lineWidth, color);
    }
    // Bottom
    for(int i = 0; i < width; i++){
        coordiantes.push_back(std::make_pair(i + position.x, position.y + height));
        DrawCircleV({i + position.x, position.y + height}, lineWidth, color);
    }
    // Left
    for(int i = 0; i < height; i++){
        coordiantes.push_back(std::make_pair(position.x, i + position.y));
        DrawCircleV({position.x, i + position.y}, lineWidth, color);
    }
    // Right
    for(int i = 0; i < height; i++){
        coordiantes.push_back(std::make_pair(position.x + width, i + position.y));
        DrawCircleV({position.x + width, i + position.y}, lineWidth, color);
    }
}


void Circle::set_radius(float r){
    radius = r;
}
void Circle::set_position(Vector2 pos){
    position = pos;
}
void Circle::set_resolution(float res){
    resolution = res;
}
void Circle::set_coordinates(std::vector<std::pair<float, float>> coords){
    coordinates = coords;
}
float Circle::get_radius(){return radius;}

float Circle::get_resolution(){return resolution;}

Vector2 Circle::get_position(){return position;}

std::vector<std::pair<float, float>> Circle::get_coordinates(){return coordinates;}

void Circle::draw(Vector2 position,
          float radius,
          float resolution,
          float lineWidth,
          Color color){
        for(int angle = 0; angle < resolution; angle++){
            float theta = 2.0f * PI * float(angle) / resolution;
            float x = radius * cosf(theta);
            float y = radius * sinf(theta);
            coordinates.push_back(std::make_pair(x + position.x, y + position.y));
            DrawCircleV({x + position.x, y + position.y}, lineWidth, color);
        }
        set_coordinates(coordinates);
}

void Circle::update(std::vector<std::pair<float, float>> prevCoordinates, std::vector<std::pair<float, float>> coordinates){
    for(int i = 0; i < coordinates.size(); i++){
        DrawCircleV({prevCoordinates[i].first, prevCoordinates[i].second}, lineWidth, BLACK);
        DrawCircleV({coordinates[i].first, coordinates[i].second}, lineWidth, color);
    }
    prevCoordinates = coordinates;
}

