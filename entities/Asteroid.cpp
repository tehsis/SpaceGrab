#include "Asteroid.h"

Asteroid::Asteroid() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  t = drawer->Image("../assets/asteroid.png");    

  r = new Tehsis::Rectangle;

  r->w = 120;
  r->h = 120;
  r->x = 20;
  r->y = 20;
}

void Asteroid::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  
  drawer->DrawImage(t, NULL, r);
}