#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
#pragma once
class Butterfly: public Unit{

public:
    void fly();
    bool down = true; //This will help us in knowing if the butterfly is going up or down.
    Butterfly(int x, int y); 

    // you may add other overloaded constructors here... 
};