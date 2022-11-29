#include<SDL.h>
#include "pigeon.hpp"
#include "bee.hpp"
#include "butterfly.hpp"
#include<vector>
#include<list>
#include "Unit.hpp"
#include "ObjectCreator.hpp"
#include "Obstacle.hpp"
#pragma once
using namespace std;

class HUMania{
    //Create your list here
    
    vector<Unit*> Units;

    // int** check = new int* [4];
    // Obstacle** Obstacles = new Obstacle* [4];

    vector<Obstacle*> Obstacles; //Each Obstacles pointer point at Obstacles array. Each Index is a level.
    vector<int> Obstacles_per_level;

    public:
    int level = 1;
    int T = 0; //This prevents Loadmedia to keep on loading the same background over and over again, and tells that transitioning is required.

    void drawObjects(); 
    void createObject(int, int);
    void getObstacles();
    

     ~HUMania(); //Destructor added
    // create destructor which deletes all dynamic objects
};