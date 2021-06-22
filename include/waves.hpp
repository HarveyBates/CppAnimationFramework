#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>
#include <math.h>

class Sinewave{
    float freqency, amplitude;
public:
    void set_frequecy(float freq);
    void set_amplitude(float amp);
    float get_frequency();
    float get_amplitude();
    
    void draw(Vector2 startPoint, float width, float offset, float amp, float xPos, float freq, Color color);
};
