#include "waves.hpp"

void Sinewave::set_frequecy(float freq){
    freq = freqency;
}
void Sinewave::set_amplitude(float amp){
    amp = amplitude;
}
float Sinewave::get_frequency(){return freqency;}
float Sinewave::get_amplitude(){return amplitude;}

void Sinewave::draw(Vector2 startPoint, float width, float offset, float amp, float xPos, float freq, Color color){
    
    amplitude = amp;
    freqency = freq;
    
    for(float x = startPoint.x; x < startPoint.x + width; ++x){
        float y = amp * sinf((x * (PI/180)) * freq + xPos) + offset;
        Vector2 point = {x, y};
        DrawCircleV(point, 4.0f, color);
    }
}

