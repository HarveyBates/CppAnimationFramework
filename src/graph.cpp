#include "graph.hpp"



void Grid::set_horizontal_lines(float num){
    num = hLines;
}
void Grid::set_vertical_lines(float num){
    num = vLines;
}
void Grid::draw(Vector2 gridStart, float extentWidth, float extentHeight, float hLines, float vLines, float lineWidth, Color lineColor){
    
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



Vector2 Origin::get_position(){return position;}

void Origin::draw(Vector2 postion, bool arrows, float arrowX, float arrowY, Color color){
    
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

