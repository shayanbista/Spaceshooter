#include "player.h"

Player::Player(SDL_Renderer * render):renderer(render){
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
            std::cout << "Failed to create texture! SDL Error: " << SDL_GetError() << std::endl;
            return 1;
        }
    }

    SDL_RenderCopyEx(
        renderer,
        playerTexture,
        nullptr,
        &playerRect,
        degree,         
        nullptr,       
        SDL_FLIP_NONE   
    );

    return 0;
}

void Player::move(int x, int y) {
    int previousPosX = posX;

    posX += x;
    posY += y;

    if (posX < 0) {
        posX = 0;
        degree = 0;
    } else if (posX + playerWidth > SCREEN_WIDTH) {
        posX = SCREEN_WIDTH - playerWidth;
        degree = 0;
    }

    if(posY<0){
        posY=0;
    }
    else if(posY + playerHeight > SCREEN_HEIGHT) {
        posY=SCREEN_HEIGHT-playerHeight;
    }

    if (previousPosX > posX) {
        degree -= 15; 
        if(degree < -50)  degree = -50;
    } else if (previousPosX < posX) {
        degree += 15; 
        if (degree > 50) degree =50;
    }

    playerRect.x = posX;
    playerRect.y = posY;


}

void Player::shoot() {
    float firingDegree = 90-degree;
    shooting.emplace_back(posX, posY + playerHeight, true, firingDegree); 
}


void Player::renderBullets() {
    for (auto& bullet : shooting) {
        if (bullet.fired) {
            float radians = bullet.firingDegree * M_PI / 180.0f; 
            bullet.x += 4 * cos(radians);
            bullet.y -= 4 * sin(radians);
            bulletRect = { static_cast<int>(bullet.x), static_cast<int>(bullet.y), 5, 10 };
            if (bullet.x <= 0 || bullet.x >= SCREEN_WIDTH) {
                if (bullet.x <= 0) {
                    bullet.firingDegree = 60 + rand() % 91; 
                } else {
                    bullet.firingDegree = 60+ rand() % 91; 
                }
                bullet.x = std::clamp(bullet.x, 0.0f, static_cast<float>(SCREEN_WIDTH - 1));
        }
            // Render the bullet
            SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
            SDL_RenderFillRect(renderer, &bulletRect);
            // Resetting the render color
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        }
    }

    // Remove bullets that go off-screen
    shooting.erase(
        std::remove_if(
            shooting.begin(),
            shooting.end(),
            [](Bullet& bullet) {
                return bullet.y < 0 || bullet.x < 0 || bullet.x > SCREEN_WIDTH;
            }
        ),
        shooting.end()
    );
}


Player::~Player(){
    if (playerTexture) {
        SDL_DestroyTexture(playerTexture);
        playerTexture = nullptr;
    }
    IMG_Quit();
}

