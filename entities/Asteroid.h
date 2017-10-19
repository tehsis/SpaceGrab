#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include "../lib/Entity.h"
#include "../lib/Drawer.h"
#include "../lib/Collider.h"

class Asteroid: public Tehsis::Entity {
private:
  Collider* collider;
  int animationCount;
  int time;
  int previousTime;
  Tehsis::Rectangle* r;
  Tehsis::Texture* t;
public:
  Asteroid(unsigned x, unsigned y);
  void onUpdate() override;  
  Collider* GetCollider();
};

#endif
