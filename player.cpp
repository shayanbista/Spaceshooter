#include "player.h"

Player::Player() {
    playerSurface = nullptr;
    playerTexture = nullptr;
    
    // Initialize SDL_image
    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        return;
    }
    playerRect = {posX, posY, playerHeight, playerWidth};  
};

int Player::renderPlayer() {
    SDL* sdlInstance = SDL::getInstance();
    SDL_Renderer* renderer = sdlInstance->getRenderer();

    if (!playerTexture) {
        //loading an image to render
        const char* imagePath = "../resources/spaceShip/ships/Gray1.png";  
        playerSurface = IMG_Load(imagePath);
        
        if (!playerSurface) {
            std::cout << "SDL_image Error: " << IMG_GetError() << std::endl;
            return 1;
        }

        playerTexture = SDL_CreateTextureFromSurface(renderer, playerSurface);
        SDL_FreeSurface(playerSurface);
        playerSurface = nullptr;  // Avoiding dangling pointer 

        if (!playerTexture) {
            std::cout<<"error from here"<<"\n";
            std::cout << "Failed to create texture! SDL Error: " << SDL_GetError() << std::endl;
            return 1;
        }

    }

    SDL_Rect destRect = {100, 100, 50, 50};
    SDL_RenderCopy(renderer, playerTexture, nullptr, &playerRect);

    return 0;
}


int Player::move(int x,int y){
    posX += x;
    posY += y;

    // checking x dimensions
     if (posX < 0) { 
        posX = 0;
    } else if (posX+playerWidth >Constants::screenWidth) { 
        posX = Constants::screenWidth- playerWidth;
    }

    // checking y dimensions
    if (posY < 0) { 
        posY = 0;
    } else if (posY + playerHeight > Constants::screenWidth) {
        posY = Constants::screenWidth - playerHeight;
    }

    playerRect.x = posX;
    playerRect.y = posY;

    return 0;
}
int Player::shoot(){
    SDL* sdlInstance = SDL::getInstance();
    SDL_Renderer* renderer = sdlInstance->getRenderer();
    int firingPositionX=posX;
    int firingPositionY=posY+playerHeight;
    

    std::cout<<"firing position: "<< firingPositionX<<"\n";
    std::cout<<"firing position y: "<< firingPositionY<<"\n";
    SDL_Rect rect = {firingPositionX, firingPositionY, 20, 20};

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
    SDL_RenderFillRect(renderer, &rect);


    return 0;
}


Player::~Player(){
    if (playerTexture) {
        SDL_DestroyTexture(playerTexture);
        playerTexture = nullptr;
    }
    IMG_Quit();
}
