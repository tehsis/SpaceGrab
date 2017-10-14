#include "Background.h"

#include "../lib/Drawer.h"


Background::Background() {
  rect = new Tehsis::Rectangle;
  rect->x = -640;
  rect->y = -480;
  rect->w = 640 * 3;
  rect->h = 480 * 3;
}


void Background::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  Tehsis::Texture* t = drawer->Image("../assets/background.png");


  drawer->DrawImage(t, NULL, rect);
}
