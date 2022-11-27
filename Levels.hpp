#include<SDL.h>
#include "drawing.hpp"
#pragma once
class Levels{
protected:
    int frame = 0; //useful in bees, where counter is needed.

public:
    // add the fly function here as well.
    SDL_Rect srcRect, moverRect; //////////////
    void draw();
    virtual void fly(); //creating virtual abstract function, meaning each child class must define the fly function.
    Unit();

};