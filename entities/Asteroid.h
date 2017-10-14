#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include "../lib/Entity.h"
#include "../lib/Drawer.h"

class Asteroid: public Tehsis::Entity {
private:
  Tehsis::Rectangle* r;
  Tehsis::Texture* t;
public:
  Asteroid();
  void onUpdate() override;  
};

#endif