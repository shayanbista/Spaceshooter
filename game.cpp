#include "game.h"
#include <iostream>
#include <chrono>
#include <thread>

Game::Game() : quit(false), sdlInstance(nullptr),renderer(nullptr),map(nullptr),player(nullptr){};

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
    enemies.emplace_back(renderer,MovementType::HORIZONTAL, 10, 30,1);
    enemies.emplace_back(renderer,MovementType::HORIZONTAL, 30, 80,2);
    enemies.emplace_back(renderer,MovementType::HORIZONTAL, 70, 20,3);

    map = new Map(renderer);
    player = new Player(renderer);
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
    delete map;
    delete player;
}


void Game::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        // First pass the event to map
        map->handleTileMapEvent(e);
        
        // Then handle game-specific events
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_LEFT:
                    player->move(-10,0);  // Move left
                    break;
                case SDLK_RIGHT:
                    player->move(10,0);   // Move right
                    break;

                case SDLK_UP:
                    player->move(0,-10);  // Move up
                    break;
                case SDLK_DOWN:
                    player->move(0,10);   // Move down
                    break;
                case SDLK_l:
                    player->shoot();    // Shooting
                    break;
                case SDLK_s:
                    map->saveMap("output.txt"); // Save a map
                    break;
                case SDLK_o:
                    map->loadMap("output.txt"); // Save a map
                    startGame=true;
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
        if (checkCollision(player->getBulletRect(), it->getRect())) {
            it = enemies.erase(it);  
        } else {
            ++it;  
        }
    }
}


void Game::render() {
    // clear the renderer
    SDL_RenderClear(renderer);

    map->displayTiles();
    player->renderPlayer();

    if(startGame){
    for (auto& enemy : enemies) {
        enemy.renderEnemy();
        // renders the bullets shot by enemy
        enemy.renderBullets(); 
    }
    // renders the bullet shot by player
    player->renderBullets();
    }
    SDL_RenderPresent(renderer);

}
