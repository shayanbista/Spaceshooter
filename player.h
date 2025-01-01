
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Player {
public:
    Player();

    int renderPlayer();
   

private:
    int posX=50;
    int posY=50;
    int playerSize=32;
    SDL_Texture* playerTexture;  
    SDL_Surface* tileSurface;
    SDL_Rect playerRect;
};

#endif // PLAYER_H
