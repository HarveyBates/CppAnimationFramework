#include "transform.hpp"

std::vector<std::pair<float, float>> Morph::update(std::vector<std::pair<float, float>> obj1,
                                            std::vector<std::pair<float, float>> obj2,
                                            int currentStep, int totalSteps,
                                            float resolution, float lineWidth,
                                            Color color){
    std::vector<std::pair<float, float>> coordinates;
    for(int i = 0; i < resolution; i++){
        float obj1X = obj1[i].first;
        float obj1Y = obj1[i].second;
        float obj2X = obj2[i].first;
        float obj2Y = obj2[i].second;
        float morphX = obj2X + (obj1X - obj2X) * currentStep / totalSteps;
        float morphY = obj2Y + (obj1Y - obj2Y) * currentStep / totalSteps;
        coordinates.push_back(std::make_pair(morphX, morphY));
    }
    return coordinates;
}
