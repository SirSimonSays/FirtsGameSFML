/** this file includes all the other files that will be used into the
  * ::game_render.cc file and declares the functions of this file like
  * ::init_render() and ::random_platform(), ::update_render() and ::move_player().
  */

#ifndef GAME_RENDER
#define GAME_RENDER

#include "debug.h"
#include "data_structure.h"
#include "game_manager.h"

const int PLATFORMS_NUMBER = 10;
const int PLATFORM_DIMENSION_X = 137;
const int PLATFORM_DIMENSION_Y = 30;
const float PLATFORMS_SPEED = 1.8;
const int PLAYER_DIMENSION = 40;

enum player_state {RUN, JUMP, FLY, DEATH};

extern bool resume_flag;

void init_render();
void random_platform();
void update_render(sf::RenderWindow &window);
void move_player(bool dir);
void glide_player();
void animation(player_state p, bool direction);
bool collision();
void scroll_platforms();

#endif
