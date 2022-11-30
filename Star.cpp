#include "Star.hpp"
#include "Unit.hpp"

void Star::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::star, &srcRect, &moverRect);
}

Star::Star(int x, int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {0,0,768,768};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {x, y, 50, 50};
}