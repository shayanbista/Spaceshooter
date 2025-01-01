#include "player.h"
#include "sdl.h"
#include <iostream>

Player::Player() {
    // Initialize playerRect here
    playerRect = {posX, posY, playerHeight, playerWidth};  
};

int Player::renderPlayer() {
    SDL* sdlInstance = SDL::getInstance();
    SDL_Renderer* renderer = sdlInstance->getRenderer();

    // Set the render color to red for the player
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  

    // Render the player rectangle
    SDL_RenderFillRect(renderer, &playerRect);

    return 0;
}



int Player::move(int x,int y){
    posX += x;
    posY += y;

    // checking x dimensions
     if (posX < 0) { 
        posX = 0;
    } else if (posX+playerWidth >500) { 
        posX = 500- playerWidth;
    }

    // checking y dimensions
    if (posY < 0) { 
        posY = 0;
    } else if (posY + playerHeight > 500) {
        posY = 500 - playerHeight;
    }


    playerRect.x = posX;
    playerRect.y = posY;

    return 0;
}
