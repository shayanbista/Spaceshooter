#include "map.h"

void Map::loadMap() {
    std::cout << "Map loaded" << std::endl;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }




}



