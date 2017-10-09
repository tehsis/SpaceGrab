#ifndef _BACKGROUND_H
#define _BACKGROUND_H

#include "../lib/Entity.h"

class Background: public Tehsis::Entity {
  public:
    void onUpdate() override;
};

#endif