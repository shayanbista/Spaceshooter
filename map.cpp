// map.cpp
#include "map.h"
#include "sdl.h"
#include <iostream>

Map::Map() {
    // Initialize member variables
    tileSurface = nullptr;
    tileTexture = nullptr;
    
    // Initialize SDL_image
    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }
}

int Map::loadMap() {
    // Access the SDL singleton instance
    SDL* sdlInstance = SDL::getInstance();
    SDL_Renderer* renderer = sdlInstance->getRenderer();

    if (!tileTexture) {
        // Try to load the image - use absolute path or correct relative path
        const char* imagePath = "../resources/background3.png";  // Adjust this path
        tileSurface = IMG_Load(imagePath);
        
        if (!tileSurface) {
            std::cout << "Failed to load image at path: " << imagePath << std::endl;
            std::cout << "SDL_image Error: " << IMG_GetError() << std::endl;
            return 1;
        }

        tileTexture = SDL_CreateTextureFromSurface(renderer, tileSurface);
        SDL_FreeSurface(tileSurface);
        tileSurface = nullptr;  // Good practice to nullptr after freeing

        if (!tileTexture) {
            std::cout << "Failed to create texture! SDL Error: " << SDL_GetError() << std::endl;
            return 1;
        }
    }

    // Get the texture dimensions
    int textureWidth, textureHeight;
    SDL_QueryTexture(tileTexture, nullptr, nullptr, &textureWidth, &textureHeight);

    // Create a destination rectangle for the entire screen
    SDL_Rect destRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    
    // Render the background texture to fill the screen
    SDL_RenderCopy(renderer, tileTexture, nullptr, &destRect);

    return 0;
}

Map::~Map() {
    if (tileTexture) {
        SDL_DestroyTexture(tileTexture);
        tileTexture = nullptr;
    }
    IMG_Quit();  
}




