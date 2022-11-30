#include "game.hpp"
#include "HUMania.hpp"
#include "drawing.hpp"

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;

bool Game::init()
{
	//Initialization flag
	bool success = true;


	//Initialize SDL
	/// Initializing Music SDL Library
	int init2 = Mix_Init(0);

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "The Jump King By Asghar, Burhan and ShahJahan!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}
	// Initializing TTF SDL Library
	if (TTF_Init() == -1){
		cout << "Could not initialize SDL2_ttf, error: " << TTF_GetError() << endl;
	}
	TTF_Font* ourFont = TTF_OpenFont("Kingthings Foundation.ttf",32);
	if (ourFont == nullptr){
		cout << "Could not load font" << endl;
		exit(1);
	}
	return success;
}

bool Game::loadMedia(int n)
{
	//Loading success flag
	bool success = true;
	
	Drawing::assets = loadTexture("assets.png");
	if (n==1){
		SDL_DestroyTexture(gTexture);
		gTexture = loadTexture("Level 1.png");
	}
	else if (n==2){
		SDL_DestroyTexture(gTexture); //supposedly destroys the previous texture. Helps in not casuing lag.
		gTexture = loadTexture("Level 2.png");
	}
	else if (n==3){
		SDL_DestroyTexture(gTexture);
		gTexture = loadTexture("Level 3.png");
	}
	else if (n==4){
		SDL_DestroyTexture(gTexture);
		gTexture = loadTexture("Level 4.png");
	}
	if(Drawing::assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run( )
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_Music* music = Mix_LoadMUS("Popular_Potpourri.wav");
	if (!music){
		cout << "Music Error: " << Mix_GetError() << endl;
	}
	Mix_PlayMusic(music, -1);
	// Mix_Chunk* sound = Mix_LoadWAV("Filename";)
	// if (!sound){
	// 	cout << "Sound Error: " << Mix_GetError() << endl;
	// }
	//Mix_PlayChannel(-1, sound, 0);


	bool quit = false;
	SDL_Event e;

	HUMania humania;
	humania.getObstacles();
	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 ) //responsible for looping
		{
			// cout << "humania level: " << humania.level << endl;
			if (humania.level == 2 && humania.T == 1){
			// SDL_DestroyTexture(gTexture);
	
	// SDL_SetRenderDrawColor(Drawing::gRenderer, 0,0,0xFF,SDL_ALPHA_OPAQUE);

	// TTF_Font* ourFont = TTF_OpenFont("Kingthings Foundation.ttf",48);
	// SDL_Surface* surfaceText = TTF_RenderText_Solid(ourFont, "I like Fortnite", {233,0,0});
	// SDL_Texture* TextureText = SDL_CreateTextureFromSurface(Drawing::gRenderer,surfaceText);
	// SDL_Rect rectangle = {30,30, surfaceText -> w, surfaceText -> h};
	// SDL_FreeSurface(surfaceText);

	//https://www.youtube.com/watch?v=ltNTI9m_Vg0
	//https://www.youtube.com/watch?v=1tBzIhVgR7E
	// TTF_CloseFont(ourFont);
	// rectangle.x = 10;
	// rectangle.y = 10;
	// rectangle.w = 400;
	// rectangle.h = 100;
	// SDL_SetRenderDrawColor(Drawing::gRenderer, 0,0,0xFF,SDL_ALPHA_OPAQUE);
	// SDL_RenderClear(Drawing::gRenderer);
	// SDL_RenderCopy(Drawing::gRenderer, TextureText, NULL, &rectangle);
	// SDL_RenderPresent(Drawing::gRenderer);


				Game::loadMedia(2);
			}
			else if (humania.level == 3  && humania.T == 1){
				Game::loadMedia(3); 
			}
			else if (humania.level == 4 && humania.T == 1){
				Game::loadMedia(4); 
			}
			humania.T = 0;
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}


			if(e.type == SDL_MOUSEBUTTONDOWN){
			//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				humania.createObject(xMouse, yMouse);
			}

		}

		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************

		humania.drawObjects();
		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}
