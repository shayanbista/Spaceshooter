#ifndef SDL_H
#define SDL_H

#include <SDL2/SDL.h>
#include <iostream>

class SDL {
private:
    static SDL* instance;  
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL();

public:
    // Static method to get the Singleton instance
    static SDL* getInstance();

    // Method to initialize SDL
    bool initialize(const char* title, int width, int height);

    // Getters for window and renderer
    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();

    // Clean up SDL resources
    void cleanup();

    // Deleted copy constructor and assignment operator to prevent copies
    SDL(const SDL&) = delete;
    SDL& operator=(const SDL&) = delete;
};

#endif // SDL_H
