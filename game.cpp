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
    if (!sdlInstance->initialize("Space Shooter Game", Constants::screenWidth, Constants::screenHeight)) {
        std::cout << "SDL Initialization failed!" <<"\n";
    }

    renderer = sdlInstance->getRenderer();

    // Initialize enemies
    enemies.emplace_back(MovementType::HORIZONTAL, 10, 30);
    enemies.emplace_back(MovementType::HORIZONTAL, 30, 80);
    enemies.emplace_back(MovementType::HORIZONTAL, 40, 40);
    enemies.emplace_back(MovementType::VERTICAL, 5, 50);

    
    // Start enemy movement threads
    int speed=1;
    for (size_t i = 0; i < enemies.size(); ++i) {
        speed++; 
        enemyThreads.emplace_back(enemyMovementThread, &enemies[i], speed);
    }

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
    for (auto& thread : enemyThreads) {
        if (thread.joinable()) {
            thread.detach();
        }
    }
    sdlInstance->cleanup();
}

void Game::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            quit = true;
        }

        if (e.type == SDL_KEYDOWN) {
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
    player.updateBullets();
    
    std::vector<Enemy*> toRemove;
    for (Enemy& enemy : enemies) {
        if (checkCollision(player.getBulletRect(), enemy.getRect())) {
            toRemove.emplace_back(&enemy);

        }
    }
    
    // Remove marked enemies
    enemies.erase(
        std::remove_if(enemies.begin(), enemies.end(),
            [&](const Enemy& e) {
                return std::find(toRemove.begin(), toRemove.end(), &e) != toRemove.end();
            }),
        enemies.end()
    );


}


void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);//setting color to black
    SDL_RenderClear(renderer);

    map.loadMap();
    player.renderPlayer();

    for (auto& enemy : enemies) {
        enemy.renderEnemy();
    }
    player.updateBullets();

    SDL_RenderPresent(renderer);
}

void Game::enemyMovementThread(Enemy* enemy, int speed) {
    while (true) {
        enemy->slideEnemy(speed);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
}