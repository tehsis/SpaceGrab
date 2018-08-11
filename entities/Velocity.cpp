#include "Velocity.h"

#include "../lib/Drawer.h"

Velocity::Velocity() {
  r = new Tehsis::Rectangle;
  r->x = 20;
  r->y = 20;
  r->w = 200;
  r->h = 50;
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();  
  font = drawer->LoadFont("../assets/ShareTechMono-Regular.ttf"); 
  color = Color{ 255, 0, 0 };
  text = drawer->Text("Velocity", color, font);
}

void Velocity::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();  
  drawer->DrawImageAbsolute(text, NULL, r);
}