#ifndef MAP_H
#define MAP_H

#include "sdl.h"
#include "constants.h"
#include "utils.h"


#include <iostream>
#include <vector>
#include <string>
#include <map>

class Map {
public:
    Map();
    ~Map();

    void displayTiles();

    void setColoredTile(char c, SDL_Event& event); 
    void handleTileMapEvent(SDL_Event& event); 
    void renderColoredTile(char c, SDL_Event& event); 


private:
    SDL_Texture* mapTexture;  
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* tileSurface;
    SDL_Texture* tileTexture;
    std::vector<std::vector<char>> mapData; 


};

#endif // MAP_H
