#include "Obstacle.hpp"

void Obstacle::hitbox_setter(int x1, int x2, int y1, int y2, int repeat, int victory){
    hitbox[0] = x1;
    hitbox[1] = x2;
    hitbox[2] = y1;
    hitbox[3] = y2;
    hitbox[4] = repeat;
    hitbox[5] = victory;
}