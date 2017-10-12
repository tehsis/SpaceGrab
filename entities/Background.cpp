#include "Background.h"

#include "../lib/Drawer.h"


Background::Background() {
  rect = new Tehsis::Rectangle;
  rect->x = 0;
  rect->y = 0;
  rect->w = 640;
  rect->h = 480;
}


void Background::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  Tehsis::Texture* t = drawer->Image("../assets/background.png");

  onFollow();

  drawer->DrawImage(t, rect, NULL);
}

void Background::Follow(Ship *e) {
    follower = e;
}

void Background::onFollow() {
    if (follower == NULL) {
        return;
    }

    Tehsis::Rectangle* followerRect = follower->getRect(); 

    rect->x = followerRect->x - 640/2;
    rect->y = followerRect->y - 480/2;

    if (rect->x < 0) {
        rect->x = 0;
    }

    if (rect->x > 640*2) {
        rect->x = 640*2;
    }

    if (rect->y < 0) {
        rect->y = 0;
    }

    if (rect->y > 480*2) {
        rect->y = 480*2;
    }
}
