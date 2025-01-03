
#include <iostream>
#include <thread>

#include "map.h"
#include "player.h"
#include "sdl.h"
#include "constants.h"
#include "enemy.h"
#include <mutex>


std::mutex enemyMutex;

void enemyMovementThread(Enemy* enemy, int speed) {
    while (true) {
        {
            enemy->move(speed);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(30));  
    }
}

int main() {
    // Initialize SDL
    SDL* sdlInstance = SDL::getInstance();
    if (!sdlInstance->initialize("Space Shooter Game", Constants::screenWidth , Constants::screenHeight)) {
        std::cout << "SDL Initialization failed!" << std::endl;
        return -1;
    }

    // Create map and player instances
    Map map;
    Player player;
    Enemy enemy(MovementType::HORIZONTAL,10,30);
    Enemy enemy2(MovementType::HORIZONTAL,30,80);
    Enemy enemy1(MovementType::VERTICAL,10,50);


 
    // Get the renderer from SDL Singleton
    SDL_Renderer* renderer = sdlInstance->getRenderer();


    // applying threading to move the enemy
    std::thread enemyThread1(enemyMovementThread, &enemy, 2);
    std::thread enemyThread2(enemyMovementThread, &enemy1, 1);
    std::thread enemyThread3(enemyMovementThread, &enemy2, 3);


    // Main game loop
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            // Player movement handling (using arrow keys or WASD)
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        std::cout<<"Top button is called"<<"\n";
                        break;
                    case SDLK_DOWN:
                        std::cout<<"Top button is called"<<"\n";
                        break;
                    case SDLK_LEFT:
                        player.move(-10);  // Move left
                        break;
                    case SDLK_RIGHT:
                        player.move(10);   // Move right
                        break;
					case SDLK_l:
						player.shoot(); //shooting
                }

            }
        }

        // Clear the screen with black colorbut i dont get it how the move 
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render the map 
        map.loadMap();

        // Render the player 
        player.renderPlayer();

        player.updateBullets();
        
        enemy.renderEnemy();
        enemy1.renderEnemy();
        enemy2.renderEnemy();
        
        // Present the renderer
        SDL_RenderPresent(renderer);

        SDL_Delay(16);  // ~60 FPS
    }


    enemyThread1.detach();  
    enemyThread2.detach();
    enemyThread3.detach();
    
    // Cleanup and quit
    sdlInstance->cleanup();
    return 0;
}

