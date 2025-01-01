#include "player.h"
#include "sdl.h"
#include <iostream>

Player::Player() {
    // Initialize playerRect here
    playerRect = {100, 100, 20, 20};  
};

int Player::renderPlayer() {
    SDL* sdlInstance = SDL::getInstance();
    SDL_Renderer* renderer = sdlInstance->getRenderer();

    // Set the render color to red for the player
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red color

    // Render the player rectangle
    SDL_RenderFillRect(renderer, &playerRect);

    return 0;
}
