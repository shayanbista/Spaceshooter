#ifndef GAME_H
#define GAME_H

// #include <SDL.h>
#include <thread>
#include <mutex>
#include <vector>
#include <list>
#include <SDL_ttf.h>


#include "sdl.h"
#include "map.h"
#include "player.h"
#include "enemy.h"
#include "constants.h"


class Game {
public:
    Game();
    ~Game();

    bool initialize();
    void run();
    void cleanup();

private:
    SDL* sdlInstance;
    SDL_Renderer* renderer;

    bool quit;
    bool startGame=false;

    Map* map;    
    Player* player; 
    std::vector<std::thread> enemyThreads;
    std::list<Enemy> enemies;
    std::vector<int> bulletsToRemove;

    void handleEvents();
    void update();
    void render();

};

#endif // GAME_H
