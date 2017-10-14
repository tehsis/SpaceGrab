#include "Background.h"

#include "../lib/Drawer.h"


Background::Background() {
  rect = new Tehsis::Rectangle;
  rect->x = 0;
  rect->y = 0;
  rect->w = 640 * 2;
  rect->h = 480 * 2;

  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();  
  t = drawer->Image("../assets/background.png");  
}


void Background::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  drawer->DrawImage(t, NULL, rect);
}
