#include "drawing.hpp"

std::string Drawing::assets_path = "res/JumpKing.png";

Sprites *Drawing::JumpKing = Drawing::set();

// static function to define JumpKing
Sprites* Drawing::set()
{
    Sprites *ab = new Sprites();
    ab->insert(std::pair<std::string,SDL_Rect>("DEFAULT",{429,10,26,28}));
    ab->insert(Sprites::value_type("UP",{429,10,26,28}));
    // ab->insert(Sprites::value_type("UP",{126,42,32,33}));
    ab->insert(Sprites::value_type("DOWN",{50,43,30,26}));
    ab->insert(Sprites::value_type("LEFT",{237,9,25,29}));
    ab->insert(Sprites::value_type("RIGHT",{465,8,29,30}));
    ab->insert(Sprites::value_type("LEFT_RUN",{200,9,32,29}));
    ab->insert(Sprites::value_type("RIGHT_RUN",{147,10,30,26}));
    ab->insert(Sprites::value_type("LAND",{179,20,30,17}));
    ab->insert(Sprites::value_type("JUMP",{146,111,27,29}));
    ab->insert(Sprites::value_type("UP_LEFT",{140,4,26,34}));
    ab->insert(Sprites::value_type("UP_RIGHT",{212,5,25,32}));
    ab->insert(Sprites::value_type("DOWN_LEFT",{105,4,30,34}));
    ab->insert(Sprites::value_type("DOWN_RIGHT",{244,5,28,32}));
    return ab;
}