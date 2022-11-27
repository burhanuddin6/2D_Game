#include <iostream>
#include "HUMania.hpp"
#include "ObjectCreator.hpp"
#include "game.hpp"
#pragma once

void HUMania::drawObjects()
{
    for (int i = 0; i < Units.size(); i++){
        if (typeid(*Units[i]) == typeid(Bee())){
                delete Units[i];
                Units[i] = NULL;
                Units.erase(Units.begin()+i);
                continue;
            }
        }
// float x1 = 0;    // line controlled by mouse
// float y1 = 0;
// float x2 = 10;   // fixed end
// float y2 = 10;

// float x3 = 100;  // static line
// float y3 = 300;
// float x4 = 500;
// float y4 = 100;
//{x, y, 50, 50};

    
// float uA = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
// float uB = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));

// if (r1x + r1w >= r2x &&     // r1 right edge past r2 left
//   r1x <= r2x + r2w &&       // r1 left edge past r2 right
//   r1y + r1h >= r2y &&       // r1 top edge past r2 bottom
//   r1y <= r2y + r2h) {       // r1 bottom edge past r2 top
//     return true;
// }
// return false;

    for (int i = 0; i < Units.size(); i++){
    bool collision = false;
    float r1x = (Units[i] -> moverRect.x);
    float r1y = (Units[i] -> moverRect.y);
    float r1w = 50;
    float r1h = 50;
    //for (int j = 0; i < sizeof(Obstacles[level]); j++){
    
    // float r1x = Units[i] -> moverRect.x;
    // float r1y = Units[i] -> moverRect.y;
    // float r1w = 50;
    // float r1h = 50;
    // float r2x = Obstacles[level][j].hitbox[0];
    // float r2y =  Obstacles[level][j].hitbox[2];
    // float r2w = (Obstacles[level][j].hitbox[1] - Obstacles[level][j].hitbox[0]);
    // float r2h = (Obstacles[level][j].hitbox[2] - Obstacles[level][j].hitbox[3]);

    // if (r1x + r1w >= r2x && r1x <= r2x + r2w && r1y + r1h >= r2y && r1y <= r2y + r2h){       // r1 bottom edge past r2 top
    // collision = false;
    // }
    // if (collision == true){
    //     delete Units[i];
    //     Units[i] = NULL;
    //     Units.erase(Units.begin()+i);
    //     continue;
    //     }
    //}
    Units[i] -> draw();
    Units[i] -> fly();
    }
}


void HUMania::getObstacles(){
    cout << "I farted" << endl;
    // Obstacles[0] = new Obstacle [5]; //change the number of obstacles if there are more levels.
    if (level == 1){
        Obstacles[0] = new Obstacle [5];
        Obstacles[0][0].hitbox_setter(16, 1067, 720, 0); //main screen
        Obstacles[0][1].hitbox_setter(16, 290, 654, 369); //left block
        Obstacles[0][2].hitbox_setter(800, 1069, 654, 369); // right block
        Obstacles[0][3].hitbox_setter(419, 666, 178, 75); //block at top
        Obstacles[0][4].hitbox_setter(290, 800, 720, 654); //base
    }
    else if (level == 2){
        Obstacles[1] = new Obstacle [6];
        Obstacles[0][0].hitbox_setter(16, 1067, 720, 0); //main screen
        Obstacles[1][1].hitbox_setter(666, 1044, 656, 594); //bottomest block
        Obstacles[1][2].hitbox_setter(924, 1065, 460, 397); //middle right block
        Obstacles[1][3].hitbox_setter(573, 742, 461, 395); // middle left block
        Obstacles[1][4].hitbox_setter(266, 438, 334, 204); //top left block
        Obstacles[1][5].hitbox_setter(16, 181, 320, 155); //top right block(573, 742, 461, 395)
    }
    else if (level == 3){
        Obstacles[2] = new Obstacle [8];
        Obstacles[2][0].hitbox_setter(16, 1067, 720, 0); //main screen
        Obstacles[2][1].hitbox_setter(466, 573, 640, 607); //bottomest left block
        Obstacles[2][2].hitbox_setter(717, 844, 640, 607); //bottomest right
        Obstacles[2][3].hitbox_setter(645, 755, 513, 413); // middle right half block
        Obstacles[2][4].hitbox_setter(428, 643, 512, 447); //middle left half block
        Obstacles[2][5].hitbox_setter(355, 486, 330, 236); //topper middle block
        Obstacles[2][6].hitbox_setter(18, 143, 228, 194); //top left
        Obstacles[2][7].hitbox_setter(306, 468, 33, 1); //toppest
    }
    else if (level == 4){
        Obstacles[3] = new Obstacle[1];
        Obstacles[3][0].hitbox_setter(304,472,719,640);
    }

    }


// creates new objects 
void HUMania::createObject(int x, int y)
{
    Obstacles[0] = new Obstacle [5];
    ObjectCreator k;
    if (x<1000)
    {Units.push_back(k.getObject(x,y));}
    if (x>1070)
    {level++;
    getObstacles();
    T = 1;
    }
    cout << "Mouse clicked at: " << x << " -- " << y << endl;

}

HUMania::~HUMania(){ //The Destructor to release all the memory when we exit the program

    cout << "Initiaing Destruction upon all pigeons, butterflies and bees." << endl;
    for (int i = 0; i < Units.size(); i++){
        delete Units[i];
        Units[i] = NULL;
    }
    cout << "Destruction Successfully Carried Out." << endl;
}