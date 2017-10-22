#include "Camera.h"

Tehsis::Camera::Camera(unsigned x, unsigned y, unsigned width, unsigned height) {
    rect = new Rectangle;
    rect->x = x;
    rect->y = y;
    rect->w = width;
    rect->h = height;
}

void Tehsis::Camera::Move(unsigned x, unsigned y) {
    rect->x = x;
    rect->y = y;
}

Tehsis::Rectangle* Tehsis::Camera::GetRelativeRect(const Rectangle* src) {
    Rectangle* relative = new Rectangle;

    relative->x = src->x - rect->x;
    relative->y = src->y - rect->y;
    relative->h = src->h;
    relative->w = src->w;

    return relative;
}

unsigned int Tehsis::Camera::getWidth() {
    return rect->w;
}

unsigned int Tehsis::Camera::getHeight() {
    return rect->h;
}
