#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
#pragma once
class Bee: public Unit{
public: //placing public here instead of beneath it, so that i can use it to remove the object in my HUMANIA.cpp

    void fly();
    bool stop = false; //if the bee is in stop state or is moving.
    Bee(int x, int y); 

    // you may add other overloaded constructors here... 
};