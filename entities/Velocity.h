#ifndef _VELOCITY_H_
#define _VELOCITY_H_

#include "../lib/Entity.h"
#include "../lib/Drawer.h"

class Velocity: public Tehsis::Entity {
  private:
  Font* font;
  Rectangle* r;
  Tehsis::Color color;
  Tehsis::Texture* text;
  public:
  Velocity();
  void onUpdate() override;
};
#endif