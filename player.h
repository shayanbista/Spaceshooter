
#ifndef PLAYER_H
#define PLAYER_H

#include "sdl.h"
#include "character.h"
#include "constants.h"

#include <iostream>

class Player : public Character {
public:
    Player();
    ~Player();  
    int move(int x, int y) override;
    int shoot() override;
    int renderPlayer();

   

private:
    int posX=250;
    int posY=400;
    int playerHeight=32;
    int playerWidth=32;

    SDL_Texture* playerTexture;  
    SDL_Surface* playerSurface;
    SDL_Rect playerRect;
};

#endif // PLAYER_H
