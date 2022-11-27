
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <typeinfo>

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1080; //1000
    const int SCREEN_HEIGHT = 720; //600

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    

public:


    
    bool init();
    bool loadMedia(int); //adding one argument, important for changing levels.
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
};

