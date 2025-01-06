#include "enemy.h"
#include "constants.h"

Enemy::Enemy(MovementType type ,int x,int y){
    posX = x;
    posY =y;
    movementType = type;
    enemySurface = nullptr;
    enemyTexture = nullptr;

    degree = 90;

    if(movementType==MovementType::HORIZONTAL){
        degree =180;
    }
   
    // Initialize SDL_image
    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        return;
    }
    enemyRect = {posX, posY, enemyHeight, enemyWidth};  
};


int Enemy::renderEnemy() {
    SDL* sdlInstance = SDL::getInstance();
    SDL_Renderer* renderer = sdlInstance->getRenderer();

    // Load texture only once
    if (!enemyTexture) {
        const char* imagePath = "../resources/spaceShip/ships/Gray2.png"; 
        enemySurface = IMG_Load(imagePath);

        if (!enemySurface) {
            std::cout << "Failed to load the enemy surface: " << SDL_GetError() << "\n";
            return -1;
        }

        enemyTexture = SDL_CreateTextureFromSurface(renderer, enemySurface);
        SDL_FreeSurface(enemySurface);
        enemySurface = nullptr;

        if (!enemyTexture) {
            std::cout << "Failed to create enemy texture: " << SDL_GetError() << "\n";
            return -1;
        }
    }

    enemyRect.x = posX;
    enemyRect.y = posY;

       SDL_RenderCopyEx(
        renderer,
        enemyTexture,
        nullptr,
        &enemyRect,
        degree,         
        nullptr,       
        SDL_FLIP_NONE   
    );;

    return 0;
}


int Enemy::moveHorizontally(int speed) {
    posX += speed * direction;
    
    if (posX <= 0) {
        posX = 0;
        direction = 1;  
    } 
    else if (posX >= Constants::screenWidth - enemyWidth) {
        posX = Constants::screenWidth - enemyWidth;
        direction = -1;  
    }
    
    return 0;
}

int Enemy::moveVertically(int speed){
   
    posY +=speed * direction;

    if(posY <=0){
        posY=0;
        direction = 1;
    }

    else if(posY >=(Constants::screenHeight)/2){
        posY=(Constants::screenHeight)/2;
        direction = -1;

    }
    return 0;
};

void Enemy::slideEnemy(int speed){

    if(movementType == MovementType::HORIZONTAL){
        std::cout <<"speed before applying horizontally" << speed << std::endl;
        posX += speed * direction;
        if(posX>=Constants::screenWidth-enemyWidth){
        posX = Constants::screenWidth - enemyWidth;
        direction = -1;  
        }
        else if(posX<=0){
        posX = 0;
        direction = 1;  
        }
    }else if(movementType == MovementType::VERTICAL){
        std::cout <<"speed before applying " << speed << std::endl;
        posY += speed * direction;
        if(posY <=0){
            posY=0;
            direction = 1;
        }

    else if(posY >=(Constants::screenHeight)/2){
        posY=(Constants::screenHeight)/2;
        direction = -1;

    }    
    }
    
}

Enemy::~Enemy(){
    if(enemyTexture){
        SDL_DestroyTexture(enemyTexture);
        enemyTexture = nullptr;
    }
    IMG_Quit();
}