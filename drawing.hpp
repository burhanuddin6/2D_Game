#include <math.h>
#include<SDL.h>
#pragma once
class Drawing{
    public:
        //The window renderer
    static SDL_Renderer* gRenderer;
    //global reference to png image sheets
    static SDL_Texture* assets;
};

class Direction
{
    public:
    double angle;
    Direction(int degrees = 0)
    {
        angle =  degrees*(3.142/180);
    }
    // Direction(double radians = 0)
    // {
    //     angle =  radians;
    // }
    float x_Ratio()
    {
        return cos(angle);
    }
    float y_Ratio()
    {
        return sin(angle);
    }
    Direction operator + (Direction obj)
    {
        return Direction(angle + obj.angle);
    }
};