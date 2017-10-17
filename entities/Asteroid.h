#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include "../lib/Entity.h"
#include "../lib/Drawer.h"

class Asteroid: public Tehsis::Entity {
private:
  static int count;
  Tehsis::Rectangle* r;
  Tehsis::Texture* t;
public:
  Asteroid(unsigned x, unsigned y);
  void onUpdate() override;  
};

#endif
