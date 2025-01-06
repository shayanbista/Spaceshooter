#include "sdl.h"
#include "character.h"

enum class MovementType {
    HORIZONTAL,
    VERTICAL
};

class Enemy:public Character{
    public:
        Enemy(MovementType type,int x,int y);
        ~Enemy();

        int renderEnemy();

        void slideEnemy(int speed);
        
        // int move(int speed);        
        int moveVertically(int speed);
        int moveHorizontally(int speed);

        SDL_Rect getRect() { return enemyRect; };

    private:
        MovementType movementType;
        int posX=200;
        int posY=20;
        int enemyHeight=32;
        int enemyWidth=32;
        int degree;
        int direction = 1;

        SDL_Texture* enemyTexture;  
        SDL_Surface* enemySurface;
        SDL_Rect enemyRect;
        // std::mutex enemyMutex;

};

