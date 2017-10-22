#include "Background.h"

#include "../lib/Drawer.h"
#include "../globals.h"


Background::Background() {
  rect = new Tehsis::Rectangle;
  rect->x = 0;
  rect->y = 0;
  rect->w = SpaceGrab::LEVEL_WIDTH;
  rect->h = SpaceGrab::LEVEL_HEIGHT;

  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();  
  t = drawer->Image("../assets/background.png");  
}


void Background::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  drawer->DrawImage(t, NULL, rect);
}
