#include "bee.hpp"
#include "Unit.hpp"
// Bee implementation will go here.

// void Bee::draw(){
//     SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);

// }

void Bee::fly(){
        if (stop == false){
        int random_number = (rand() % 19); // 1/20 = 0.05 percent chance at a frame to stop. Change this value to change the probability
        moverRect.x+=5;
        if (random_number == 1){
            stop = true;
        }
        }

        if (stop == true){ //Once stopped if it passes the probability when stop is false, the counter will increment with each frame until it reaches 10 and allows bee to move again.
            if (frame == 10) //change this number if you want to change for how long the bee should be stopped for.
            {
                stop = false;
                frame = 0;
            }
            frame++;
        }


        if (srcRect.y == 619)
            srcRect = {234,630,163,162};
        else if (srcRect.y == 630)
            srcRect = {409,650,171,147};
        else if (srcRect.y == 650)
            srcRect = {63,619,151,166};
}

Bee::Bee(int x, int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {63,619,151,166};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {x, y, 50, 50};
}