// #ifndef Map.h
// #define Map.h

// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
// #include <iosteam>


// class Map{

//     public:
//     Map(){
//         //default constructor
//     }

//     void loadMap();

//     private:
//     const int SCREEN_WIDTH = 640;
//     const int SCREEN_HEIGHT = 480; 
//     SDL_Texture* mapTexture;  
//     SDL_Window* window;
//     SDL_Renderer* renderer;
//     SDL_Surface* tileSurface    


// }

// endif // Map.h


#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Map {
public:
    Map(){


    }

    void loadMap();

private:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480; 
    SDL_Texture* mapTexture;  
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* tileSurface;
};

#endif // MAP_H
