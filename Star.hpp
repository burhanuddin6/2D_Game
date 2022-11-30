#include<SDL.h>
#include "drawing.hpp"
#pragma once
class Star{
public:
    SDL_Rect srcRect, moverRect;
    void draw();
    Star(int,int);
};