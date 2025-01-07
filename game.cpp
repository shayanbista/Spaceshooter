#include "game.h"
#include <iostream>
#include <chrono>
#include <thread>

Game::Game() : quit(false), sdlInstance(nullptr), renderer(nullptr) {}

Game::~Game() {
    cleanup();
}

bool Game::initialize() {
    sdlInstance = SDL::getInstance();
    if (!sdlInstance->initialize("Space Shooter Game", SCREEN_WIDTH, SCREEN_HEIGHT)) {
        std::cout << "SDL Initialization failed!" << "\n";
        return false;
    }

    renderer = sdlInstance->getRenderer();

    // Initialize enemies
    enemies.emplace_back(MovementType::HORIZONTAL, 10, 30,1);
    enemies.emplace_back(MovementType::HORIZONTAL, 30, 80,2);
    enemies.emplace_back(MovementType::HORIZONTAL, 70, 20,3);
    // enemies.emplace_back(MovementType::VERTICAL, 3, 50,2);

    return true;
}

void Game::run() {
    while (!quit) {
        handleEvents();
        update();
        render();
        SDL_Delay(16); // ~60 FPS
    }
}

void Game::cleanup() {
    sdlInstance->cleanup();
}


void Game::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        // First pass the event to map
        map.handleTileMapEvent(e);
        
        // Then handle game-specific events
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_LEFT:
                    player.move(-10);  // Move left
                    break;
                case SDLK_RIGHT:
                    player.move(10);   // Move right
                    break;
                case SDLK_l:
                    player.shoot();    // Shooting
                    break;
                default:
                    break;
            }
        }
    }
}




void Game::update() {
    for (Enemy& enemy : enemies) {
        enemy.slideEnemy();  
        enemy.shoot();       
    }

    // Check for collisions between player bullets and enemies
    for (auto it = enemies.begin(); it != enemies.end(); ) {
        if (checkCollision(player.getBulletRect(), it->getRect())) {
            it = enemies.erase(it);  
        } else {
            ++it;  
        }
    }
}


void Game::render() {
 
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
    SDL_RenderClear(renderer);

    map.displayTiles();
    // map.loadMap();
    // player.renderPlayer();

    // for (auto& enemy : enemies) {
    //     enemy.renderEnemy();
    //     // renders the bullets shot by enemy
    //     enemy.renderBullets(); 
    // }
    // // renders the bullet shot by player
    // player.renderBullets();

    SDL_RenderPresent(renderer);
}
