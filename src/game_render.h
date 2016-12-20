/** this file includes all the other files that will be used into the
  * ::game_render.cc file and declares the functions of this file like
  * ::() and ::(), ::() and ::().
  */

#ifndef GAME_RENDER
#define GAME_RENDER

#include "debug.h"
#include "data_structure.h"

const int PLATFORMS_NUMBER = 10;

void init_render();
void random_platform();
void update_render(sf::RenderWindow &window);

#endif
