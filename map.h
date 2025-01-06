#ifndef MAP_H
#define MAP_H

#include "sdl.h"
#include "constants.h"
#include <iostream>


class Map {
public:
    Map();
    ~Map();
    int loadMap();

private:
    SDL_Texture* mapTexture;  
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* tileSurface;
    SDL_Texture* tileTexture;
};

#endif // MAP_H
