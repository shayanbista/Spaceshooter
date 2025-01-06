#ifndef _UTILITIES_H
#define _UTILITIES_H

struct Bullet {
    float x, y;
    bool fired;
    float firingDegree; 
    Bullet(float x, float y, bool fired, float degree)
        : x(x), y(y), fired(fired), firingDegree(degree) {}
};


inline bool checkCollision(const SDL_Rect& a, const SDL_Rect& b) {
    // Collision detection logic
    if (a.x + a.w <= b.x || b.x + b.w <= a.x || a.y + a.h <= b.y || b.y + b.h <= a.y) {
        return false;
    }
    return true;
}

#endif // _UTILITIES_H