#ifndef CHARACTER_H
#define CHARACTER_H

#include "sdl.h"
#include <iostream>


class Character{
    public:
        int health=5;
    Character()=default;

    virtual int shoot() {




        return 0;
    }


};

#endif // CHARACTER_H