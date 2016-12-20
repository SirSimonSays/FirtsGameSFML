/** this file includes all the other files that will be used into the
  * ::game_render.cc file and declares the functions of this file like
  * ::init_render() and ::random_platform(), ::update_render() and ::move_player().
  */

#ifndef GAME_RENDER
#define GAME_RENDER

#include "debug.h"
#include "data_structure.h"

const int PLATFORMS_NUMBER = 10;
const int PLAYER_DIMENSION = 40;

void init_render();
void random_platform();
void update_render(sf::RenderWindow &window);
void move_player(char c);

#endif
