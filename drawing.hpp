#include <math.h>
#include<SDL.h>
#include <map>
#include <string>
#pragma once
// All the members should be static
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
typedef std::map<std::string,SDL_Rect> Sprites;
class Drawing{
    public:
    ~Drawing()
    {
        delete JumpKing;
        delete assets;
        delete gRenderer;
    }
        //The window renderer
    static SDL_Renderer* gRenderer;
    //global reference to png image sheets
    static std::string assets_path;
    static SDL_Texture* assets;
    static Sprites* JumpKing;
    static Sprites* set();
};

