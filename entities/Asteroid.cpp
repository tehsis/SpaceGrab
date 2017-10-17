#include "Asteroid.h"

#include <iostream>

Asteroid::Asteroid(unsigned x, unsigned y) {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  t = drawer->Image("../assets/asteroid.png");    

  r = new Tehsis::Rectangle;

  r->w = 120;
  r->h = 120;
  r->x = x;
  r->y = y;
}

void Asteroid::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  
  std::cout << "Rendering asteroid (" << r->x << ", " << r->y << ")" << std::endl;
  drawer->DrawImage(t, NULL, r);
}
