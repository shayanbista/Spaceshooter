#include "sdl.h"
#include "character.h"
#include "utils.h"

#include <thread>
#include <vector>
#include <chrono>
#include  <algorithm>


enum class MovementType {
    HORIZONTAL,
    VERTICAL
};

class Enemy:public Character{
    public:
        Enemy(MovementType type,int x,int y, int moveSpeed);
        ~Enemy();
        int renderEnemy();
        void slideEnemy();
        void renderBullets();

        void shoot() override;
        SDL_Rect getRect() { return enemyRect; };
    private:
        MovementType movementType;
        int posX=200;
        int posY=20;
        int enemyHeight=32;
        int enemyWidth=32;
        int degree;
        int direction = 1;
        int speed =1;
        SDL_Texture* enemyTexture;  
        SDL_Surface* enemySurface;
        SDL_Rect enemyRect;
        std::vector<Bullet> bullets{};
        std::chrono::steady_clock::time_point lastShotTime;

};

