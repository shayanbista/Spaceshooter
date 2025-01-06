#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <thread>
#include <mutex>
#include <vector>

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
    void handleEvents();
    void update();
    void render();

    static void enemyMovementThread(Enemy* enemy, int speed);

    SDL* sdlInstance;
    SDL_Renderer* renderer;
    bool quit;

    Map map;
    Player player;
    std::vector<std::thread> enemyThreads;
    std::vector<Enemy> enemies;
    std::mutex enemyMutex;
};

#endif // GAME_H
