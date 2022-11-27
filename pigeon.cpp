#include "pigeon.hpp"
#include "Unit.hpp"
// pigeon implementation will go here.


// in project implementation this draw function should only be in superclass
// void Pigeon::draw(){
//     SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
// }


// fly() is overrided from the superclass
void Pigeon::fly(){
    // 
    moverRect.x += 5;
    if (moverRect.x > 995) //if pigeons has gone off-screen, resetting it to the left.
        moverRect.x = 0;
        
    if (srcRect.x == 7)   //first sprite detected based on x co-ordinates in PNG fill
        srcRect = {0,237,153,84};
    else if (srcRect.x == 0)
        srcRect = {2,361,159,124};
    else if (srcRect.x == 2)
        srcRect = {7,88,155,103};
}

Pigeon::Pigeon(int x, int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {7,88,160,103};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {x, y, 50, 50};
}

