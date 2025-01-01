
#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Map {
public:
    Map();

    int loadMap();

    ~Map();

    static const int SCREEN_WIDTH = 500;
    static const int SCREEN_HEIGHT = 500; 

private:
    int tileWidth = 32;
    int tileHeight = 32;
    SDL_Texture* mapTexture;  
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* tileSurface;
    SDL_Texture* tileTexture;
};

#endif // MAP_H
