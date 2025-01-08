
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
    Player(SDL_Renderer* render) ;
    ~Player();  
    void move(int x , int y);
    void shoot() override;
    int renderPlayer();
    void renderBullets();
    SDL_Rect getRect() { return playerRect; }
    SDL_Rect getBulletRect() { return bulletRect; }

private:
    int posX=350;
    int posY=650;
    int playerHeight=32;
    int playerWidth=32;
    int degree=0;
    std::vector<Bullet> shooting{};
    
    SDL_Texture* playerTexture;  
    SDL_Surface* playerSurface;
    SDL_Rect playerRect;
    SDL_Rect bulletRect;
    SDL_Renderer* renderer;
};

#endif // PLAYER_H
