#include<SDL.h>
#include "pigeon.hpp"
#include "bee.hpp"
#include "butterfly.hpp"
#include<vector>
#include<list>
#include "Unit.hpp"
#pragma once

class ObjectCreator{
    public:
    Unit* getObject(int, int);
};