
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "character.h"

class Player : public Character {
public:
    Player();
    // ~Player();  
    int move(int x, int y) override;
    int renderPlayer();

   

private:
    int posX=250;
    int posY=400;
    int playerHeight=32;
    int playerWidth=32;

    SDL_Texture* playerTexture;  
    SDL_Surface* tileSurface;
    SDL_Rect playerRect;
};

#endif // PLAYER_H
