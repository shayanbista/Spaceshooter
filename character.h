#ifndef CHARACTER_H
#define CHARACTER_H

#include "sdl.h"
#include <iostream>


class Character{
    public:
        int health=5;
    Character()=default;

    virtual void shoot() { }


};

#endif // CHARACTER_H