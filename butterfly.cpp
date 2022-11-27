#include "butterfly.hpp"
#include "Unit.hpp"
// Butterfly implementation will go here.

// void Butterfly::draw(){
//     SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);

// }

void Butterfly::fly(){

    //Butterfly will always have a constant horizontal speed.
        moverRect.x+=5;

    //Changing vertical position depending on whether it should be moving up or down.
        if (down ==  true)
            moverRect.y +=5;
        else{
            moverRect.y -= 5;
        }

    //if butterfly hits the upper or lower wall in y-axis, the y-component of where it moves will change by us changing the down variable.
        if (moverRect.y > 560)
            down = false;
        if (moverRect.y < 2)
            down = true;

    //Resets the butterfly to start (left-side of the screen) if it hits the most right wall of the screen
        if (moverRect.x > 995)
            moverRect.x = 0;


    //Animation
        if (srcRect.y == 24)
            srcRect = {257,182,192,214};
        else if (srcRect.y == 182)
            srcRect = {248,432,248,179};
        else if (srcRect.y == 432)
            srcRect = {257,24,173,134};
}

Butterfly::Butterfly(int x, int y){

    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {257,24,173,134};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {x, y, 50, 50};
}