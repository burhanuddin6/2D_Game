#include <iostream>
#include "HUMania.hpp"
#include "ObjectCreator.hpp"
#include "game.hpp"
#pragma once


// Don't be intimidated by so many lines of code, Breaking down each code block so you understand it block by block.
void HUMania::drawObjects()
{
//Homework 5 assignment thing. Deletes Bees when they go away from the screen.
    for (int i = 0; i < Units.size(); i++){
        if (typeid(*Units[i]) == typeid(Bee())){
                delete Units[i];
                Units[i] = NULL;
                Units.erase(Units.begin()+i);
                continue;
            }
        

// FOR MYSELF: Line/Line Collision, important for player/environment interaction.
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
//////////////////////////////////



// This block detects the collision between the enemies and the obstacles. RECTANGLE/RECTANGLE COLLISION//

//Obstacles are in a inner loop cause for that level, we will check if the enemy is colliding with
// any of the obstacles present in the level at a given moment
    bool collision = false;
    float r1x = (Units[i] -> moverRect.x);
    float r1y = (Units[i] -> moverRect.y);
    float r1w = 50;
    float r1h = 50;

    //why j = 1? cause first obstacle is our screen and our Units being formed within them will never be drawn and instantly collide (as screen as a whole is thought of as an obstacle)
    //This checks for rectangles/rectangles collision, not lines/lines.
    for (int j = 1; j < Obstacles_per_level[level]; j++){
        int r2x = Obstacles[level][j].hitbox[0]; //x1
        float r2y =  Obstacles[level][j].hitbox[3]; //y1
        float r2w = (Obstacles[level][j].hitbox[1] - Obstacles[level][j].hitbox[0]); //width
        float r2h = (Obstacles[level][j].hitbox[2] - Obstacles[level][j].hitbox[3]); //height
        if (r1x + r1w >= r2x && r1x <= r2x + r2w && r1y + r1h >= r2y && r1y <= r2y + r2h){   //checks for collision
            collision = true;
	        Mix_Chunk* explosion = Mix_LoadWAV("Short_Explosion.wav"); //boom boom sound effect added.
	        Mix_PlayChannel(-1, explosion, 0);
        }
    }
    // The conditional statement underneath just deletes the collided enemy.
    if (collision == true){
        delete Units[i];
        Units[i] = NULL;
        Units.erase(Units.begin()+i);
        continue; //
        }
    collision = false; //resets collision value if it was passed.
    Units[i] -> draw();
    Units[i] -> fly();
    }


//STARS (this is just drawing them as simply as possible depending on the level we are at)
    if (level == 1 || level == 2 || level == 3){
        float sx;
        float sy;
        if (level == 1){
            sx = 910;
            sy = 309;
        }
        else if (level == 2){
            sx = 983;
            sy = 336;
        }
        else if (level == 3){
            sx = 454;
            sy = 402;
        }
        Star(sx,sy).draw();
    }
}


void HUMania::getObstacles(){

// Sets obstacles in all the level. Is called in Game:run only once. 
    int n [] = {2,5,6,7,3};
    cout << endl;
    for (int i = 0; i < 5; i++){
        Obstacle* k = new Obstacle [n[i]];
        Obstacles.push_back(k);
        // Interesting to note: you can not use sizeof() to check the size of array declared dynamically through pointers. I suffered for hours for this little fact.
        //That's why you have seen me declare an extra vector as data members and pushing it. Helps in humania.draw()
        Obstacles_per_level.push_back(n[i]);
        cout << n[i] << endl;
    }
    // (Title Screen obstacles are useless..)
        Obstacles[0][0].hitbox_setter(16, 1067, 720, 0); //main screen
        Obstacles[0][1].hitbox_setter(16, 1067, 720, 0); //main screen
        Obstacles[0][2].hitbox_setter(16, 290, 654, 369); //left block
    // Level 1
        Obstacles[1][0].hitbox_setter(16, 1067, 720, 0); //main screen
        Obstacles[1][1].hitbox_setter(16, 290, 654, 369); //left block
        Obstacles[1][2].hitbox_setter(800, 1069, 654, 369); // right block
        Obstacles[1][3].hitbox_setter(419, 666, 178, 75); //block at top
        Obstacles[1][4].hitbox_setter(290, 800, 720, 654); //base
    // Level 2
        Obstacles[2][0].hitbox_setter(16, 1067, 720, 0); //main screen
        Obstacles[2][1].hitbox_setter(666, 1044, 656, 594); //bottomest block
        Obstacles[2][2].hitbox_setter(924, 1065, 460, 397); //middle right block
        Obstacles[2][3].hitbox_setter(573, 742, 461, 395); // middle left block
        Obstacles[2][4].hitbox_setter(266, 438, 334, 204); //top left block
        Obstacles[2][5].hitbox_setter(16, 181, 320, 155); //top right block(573, 742, 461, 395)
    // Level 3
        Obstacles[3][0].hitbox_setter(16, 1067, 720, 0); //main screen
        Obstacles[3][1].hitbox_setter(466, 573, 640, 607); //bottomest left block
        Obstacles[3][2].hitbox_setter(717, 844, 640, 607); //bottomest right
        Obstacles[3][3].hitbox_setter(645, 755, 513, 413); // middle right half block
        Obstacles[3][4].hitbox_setter(428, 643, 512, 447); //middle left half block
        Obstacles[3][5].hitbox_setter(355, 486, 330, 236); //topper middle block
        Obstacles[3][6].hitbox_setter(18, 143, 228, 194); //top left
    // Level 4
        Obstacles[4][0].hitbox_setter(16, 1067, 720, 0); //main screen
        Obstacles[4][1].hitbox_setter(304,472,719,640);

    //checker for myself
    // for (int i = 0; i < 5; i++){
    //     cout << "Obstacles per level: [" << i << "]" << Obstacles_per_level[i] << endl;
    // }
}
// creates new objects 
void HUMania::createObject(int x, int y)
{
    //Note:: For both Level 0 and 1, I am checking point//Rectangle Collision. 
    //Meaning if I click inside a rectangle, the below code detects it and helps me navigate accordingly.
    //
    if (level == 0){

    // r1 = Start Button Rectangle area.
    float r1x = 546;  // x position
    float r1y = 276;  // y position
    float r1w = 342;  // width
    float r1h = 94;  // height

    // r2 = Credits Button Rectangle area.
    float r2x = 546;
    float r2y = 370;
    float r2w = 342;
    float r2h = 94; 

    if (x >= r1x && x <= r1x + r1w && y >= r1y && y <= r1y + r1h) {
        level++;
        T=1;
        }
    if (x >= r2x && x <= r2x + r2w && y >= r2y && y <= r2y + r2h) {
        level = -1;
        T=1;
        }
    }
    if (level == -1){
    
    //r3 = Go back Button
    float r3x = 367;
    float r3y = 659;  
    float r3w = 707;
    float r3h = 56;  
    if (x >= r3x && x <= r3x + r3w && y >= r3y && y <= r3y + r3h) {
        level = 0;
        T=1;
        }
    }



    //Any level that isn't level 0 (Title Screen) or -1 (Credits), normal code is written as was in hw5
    else{ 
    ObjectCreator k;
    if (x<1000)
    {Units.push_back(k.getObject(x,y));}
    }
    if (x>1000) //changes level if u click further than x>1000 instead of spawning a new unit. Useful for checking.
    {level++;
    T = 1;
    }
    cout << "Mouse clicked at: " << x << " -- " << y << endl;

}

HUMania::~HUMania(){ //The Destructor to release all the memory when we exit the program

    cout << "Initiaing Destruction upon all pigeons, butterflies and bees." << endl;
    for (int i = 0; i < Units.size(); i++){
        delete Units[i];
        Units[i] = NULL;
        delete Obstacles [i];
        Obstacles[i] = NULL;
    }
    cout << "Destruction Successfully Carried Out." << endl;
}