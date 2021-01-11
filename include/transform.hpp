#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>

class Morph{
public:
    std::vector<std::pair<float, float>> update(std::vector<std::pair<float, float>> obj1, std::vector<std::pair<float, float>> obj2, int currentStep, int totalSteps, float resolution, float lineWidth, Color color);
};
