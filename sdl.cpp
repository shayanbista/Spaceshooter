#include "sdl.h"

// Initialize the singleton instance to nullptr
SDL* SDL::instance = nullptr;

// Private constructor ensures that only one instance can be created
SDL::SDL() : window(nullptr), renderer(nullptr) {}

// Static method to get the Singleton instance
SDL* SDL::getInstance() {
    if (instance == nullptr) {
        instance = new SDL();
    }
    return instance;
}

// Method to initialize SDL, create window and renderer
bool SDL::initialize(const char* title, int width, int height) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create window
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    return true;
}

// Getter for window
SDL_Window* SDL::getWindow() {
    return window;
}

// Getter for renderer
SDL_Renderer* SDL::getRenderer() {
    return renderer;
}

// Clean up SDL resources (window, renderer, SDL_Quit)
void SDL::cleanup() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    SDL_Quit();
}
