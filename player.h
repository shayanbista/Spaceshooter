
#ifndef PLAYER_H
#define PLAYER_H

#include "sdl.h"
#include "character.h"
#include "constants.h"
#include "utils.h"

#include <algorithm>
#include <vector>
#include <iostream>

class Player : public Character {
public:
    Player();
    ~Player();  
    int move(int x);
    int shoot() override;
    int renderPlayer();
    std::vector<Bullet> shooting{};
    void updateBullets();
    SDL_Rect getRect() { return playerRect; }
    SDL_Rect getBulletRect() { return bulletRect; }

private:
    int posX=250;
    int posY=400;
    int playerHeight=32;
    int playerWidth=32;
    int degree=0;
    
    SDL_Texture* playerTexture;  
    SDL_Surface* playerSurface;
    SDL_Rect playerRect;
    SDL_Rect bulletRect;
};

#endif // PLAYER_H
