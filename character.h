#ifndef CHARACTER_H
#define CHARACTER_H

#include "sdl.h"
#include <iostream>


class Character{
    public:
    Character()=default;
    virtual int move(int x, int y)=0;
};

#endif // CHARACTER_H