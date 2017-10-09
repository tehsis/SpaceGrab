#ifndef _GAMERUNTIME_H
#define _GAMERUNTIME_H

#include "Runtime.h"
#include <iostream>

const char DEFAULT_SCREEN_NAME[] = "Game";
const uint DEFAULT_SCREEN_WIDTH = 640;
const uint DEFAULT_SCREEN_HEIGHT = 480;

class GameRuntime: public Runtime {
public:
  GameRuntime();
  GameRuntime(std::string window_title, uint width, uint height);
  void onLoop();
};

#endif