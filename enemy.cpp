#include "enemy.h"
#include "constants.h"


Enemy::Enemy(MovementType type ,int x,int y,int moveSpeed){
    posX = x;
    posY =y;
    movementType = type;
    enemySurface = nullptr;
    enemyTexture = nullptr;
    speed=moveSpeed;
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


void Enemy::renderBullets() {
    SDL* sdlInstance = SDL::getInstance();
    SDL_Renderer* renderer = sdlInstance->getRenderer();
    for (auto& bullet : bullets) {
        bullet.y += 3;
        SDL_Rect bulletRect = {static_cast<int>(bullet.x), static_cast<int>(bullet.y), 10, 5};
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderFillRect(renderer, &bulletRect);
    }
    bullets.erase(std::remove_if(bullets.begin(),bullets.end(),[](const Bullet& bullet){ return bullet.y >=Constants::screenHeight; }),bullets.end());
}


void Enemy::shoot() {
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = currentTime - lastShotTime;

    if (elapsedTime.count() >= 2.0) {
        float firingDegree = 90-degree;
        bullets.emplace_back(posX, (posY - enemyHeight/3), true, firingDegree); 
        lastShotTime = currentTime;
    }
}



// std::chrono::steady_clock::time_point Enemy::getLastShotTime() const {
//     return lastShotTime;
// }

// void Enemy::setLastShotTime(std::chrono::steady_clock::time_point time) {
//     lastShotTime = time;
// }


int Enemy::renderEnemy() {
    SDL* sdlInstance = SDL::getInstance();
    SDL_Renderer* renderer = sdlInstance->getRenderer();

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
    );

    return 0;
}

void Enemy::slideEnemy(){

    if(movementType == MovementType::HORIZONTAL){
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