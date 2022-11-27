#include <iostream>
#include "ObjectCreator.hpp"
#include "HUMania.hpp"

Unit* ObjectCreator::getObject(int x, int y){
    int random_number = (rand() % 3);
        if (random_number == 0){
                Unit* p1 = new Pigeon (x,y);
                return p1;
        }
        else if (random_number == 1){
                Unit* Bu1 = new Butterfly (x,y);
                return Bu1;
        }
        else if (random_number == 2){

                Unit* Be1 = new Bee (x,y);
                return Be1;
        }
}