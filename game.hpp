#include "drawing.hpp"
#include "story.cpp"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Background
{
    public:
    static const int NUMBER_OF_BGS = 4;
    static string paths[NUMBER_OF_BGS];
    static string bg;
    static int ind;
    static void change_bg()
    {
        bg = paths[ind];
        ind = (ind + 1) % NUMBER_OF_BGS;
    }
};


class Window{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    

public:



    bool init();
    bool loadAssets(string assets);
    bool loadBackground(string bg);
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
    const int getScreenWidth();
    const int getScreenHeight();
    void handleEvent(SDL_Event, Story&);

};

