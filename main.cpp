
#include <iostream>
#include "map.h"
#include "player.h"
#include "sdl.h"

int main() {
    // Initialize SDL
    SDL* sdlInstance = SDL::getInstance();
    if (!sdlInstance->initialize("Space Shooter Game", 500, 500)) {
        std::cout << "SDL Initialization failed!" << std::endl;
        return -1;
    }

    // Create map and player instances
    Map map;
    Player player;

    // Get the renderer from SDL Singleton
    SDL_Renderer* renderer = sdlInstance->getRenderer();

    // Main game loop
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear the screen with black color
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render the map 
        map.loadMap();

        // Render the player 
        player.renderPlayer();

        // Present the renderer
        SDL_RenderPresent(renderer);

        // Add a small delay to prevent the CPU from maxing out
        SDL_Delay(16);  // ~60 FPS
    }

    // Cleanup and quit
    sdlInstance->cleanup();
    return 0;
}
