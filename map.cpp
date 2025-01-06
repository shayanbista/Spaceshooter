// map.cpp
#include "map.h"

Map::Map() {
    // Initialize member variables
    tileSurface = nullptr;
    tileTexture = nullptr;
    
    // Initialize SDL_image
    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        return;
    }
}

int Map::loadMap() {
    // Access the SDL singleton instance
    SDL* sdlInstance = SDL::getInstance();
    SDL_Renderer* renderer = sdlInstance->getRenderer();

    if (!tileTexture) {
        //loading an image to render
        const char* imagePath = "../resources/background3.png";  
        tileSurface = IMG_Load(imagePath);
        
        if (!tileSurface) {
            std::cout << "Failed to load image at path: " << imagePath << std::endl;
            std::cout << "SDL_image Error: " << IMG_GetError() << std::endl;
            return 1;
        }

        tileTexture = SDL_CreateTextureFromSurface(renderer, tileSurface);
        SDL_FreeSurface(tileSurface);
        tileSurface = nullptr;  // Avoiding dangling pointer

        if (!tileTexture) {
            std::cout << "Failed to create texture! SDL Error: " << SDL_GetError() << std::endl;
            return 1;
        }
    }

    // Create a destination rectangle for the entire screen
    SDL_Rect destRect = {0, 0, Constants::screenWidth,Constants::screenHeight} ;
    
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




