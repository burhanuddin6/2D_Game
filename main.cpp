#include "game.hpp"

int main(int argc, char *argv[]){
    Window game;
    srand(time(NULL));
    if( !game.init() ){
		printf( "Failed to initialize!\n" );
        return 0;
	}
		//Load media
    if(!game.loadBackground(Background::bg) || !game.loadAssets(Drawing::assets_path)){
        printf( "Failed to load media!\n" );
        return 0;
    }

    game.run();
    game.close();

    return 0;
}