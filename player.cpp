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
    shooting.emplace_back(posX,posY+playerHeight,true);
    std::cout<<"shooting length"<<shooting.size()<<"\n";
    return 0;
}



void Player::updateBullets(){

    std::cout<<"updating the value"<<"\n";
    for (auto& bullet :shooting){
        if(bullet.fired){
            bullet.y-=10;
        }
    }

    shooting.erase(std::remove_if(shooting.begin(),shooting.end(),[](const Bullet& bullet){
        return bullet.y < 0 || bullet.fired;
    }),shooting.end());

    }


Player::~Player(){
    if (playerTexture) {
        SDL_DestroyTexture(playerTexture);
        playerTexture = nullptr;
    }
    IMG_Quit();
}


