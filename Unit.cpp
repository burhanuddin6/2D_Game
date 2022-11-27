#include "Unit.hpp"


// in project implementation this draw function should only be in superclass
void Unit::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}


// fly() is overrided from the superclass

// void Unit::fly(){
// }

Unit::Unit(){ //why the hell is this constructor necessary AAAAAA it took so much time to debug. Why isn't this being called as default ;-;
}
