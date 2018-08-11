#include "Asteroid.h"

#include <iostream>

Asteroid::Asteroid(unsigned x, unsigned y) {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  t = drawer->Image("../assets/asteroid.png");    

  r = new Tehsis::Rectangle;

  animationCount = 0;
  time = 0;
  previousTime = 0;

  r->w = 120;
  r->h = 120;
  r->x = x;
  r->y = y;

  collider = new Collider(80, 80, r->x, r->y);
}

void Asteroid::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();

  Tehsis::Rectangle* s = new Tehsis::Rectangle;

  int currentTime = SDL_GetTicks();

  time = currentTime - previousTime;

  if (time >= 200) {
    previousTime = SDL_GetTicks();
    animationCount = animationCount >= 15 ? 0 : animationCount + 1;
  }

  

  s->w = 120;
  s->h = 120;
  s->x = 120 * animationCount;
  s->y = 0;
  
  drawer->DrawImage(t, s, r);
}

Collider* Asteroid::GetCollider() {
    return collider;
}
