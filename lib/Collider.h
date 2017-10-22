#ifndef _COLLIDER_H_

#define _COLLIDER_H_

#include "Aliases.h"

class Collider {
    Tehsis::Rectangle* rectangle;

    public:
    Collider(int w, int h, int x, int y);
    void Move(int x, int y);
    bool IsColliding(Collider* c);
    const Tehsis::Rectangle* getRectangle();
    
};

#endif
