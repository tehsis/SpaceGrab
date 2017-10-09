#include "GameRuntime.h"

#include "Drawer.h"

GameRuntime::GameRuntime() {
  Tehsis::SDrawer::Init(DEFAULT_SCREEN_NAME, DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
}

GameRuntime::GameRuntime(std::string window_title, uint width, uint height) {
  Tehsis::SDrawer::Init(window_title, width, height);
}

void GameRuntime::onLoop() {
  Tehsis::SDrawer::Drawer()->clearScreen();
  Runtime::onLoop();
  Tehsis::SDrawer::Drawer()->updateScreen();
}