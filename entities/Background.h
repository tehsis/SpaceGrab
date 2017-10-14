#ifndef _BACKGROUND_H
#define _BACKGROUND_H

#include "../lib/Entity.h"

#include "Ship.h"

class Background: public Tehsis::Entity {
  protected:
    Tehsis::Rectangle* rect;
  public:
    Background();
    void onUpdate() override;
};

#endif
