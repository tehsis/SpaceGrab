#include "Background.h"

#include "../lib/Drawer.h"


void Background::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  Tehsis::Texture* t = drawer->Image("../assets/background.png");

  drawer->DrawImage(t, NULL, NULL);
}