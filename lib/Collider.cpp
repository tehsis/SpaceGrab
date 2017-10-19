#include "Collider.h"

Collider::Collider(int w, int h, int x, int y) {
  rectangle = new Tehsis::Rectangle;

  rectangle->w = w;
  rectangle->h = h;
  rectangle->x = x;
  rectangle->y = y;
}


void Collider::Move(int x, int y) {
    rectangle->x = x;
    rectangle->y = y;
}

bool Collider::IsColliding(Collider* other) {
    bool isColliding = false;
    const Tehsis::Rectangle* c = other->getRectangle();

    if (
      (c->x + c->w >= rectangle->x) &&
      (c->x + c->w < rectangle->x + rectangle->w ) &&
      (c->y + c->h >= rectangle->y) &&
      (c->y + c->h < rectangle->y + rectangle->h)
    ) {
      isColliding = true;
    }

    if (
      (c->x >= rectangle->x) &&
      (c->x < rectangle->x + rectangle->w) &&
      (c->y >= rectangle->y) &&
      (c->y < rectangle->y + rectangle->h )
    ) {
      isColliding = true;
    }

    return isColliding;
}

const Tehsis::Rectangle* Collider::getRectangle() {
    return rectangle;
}
