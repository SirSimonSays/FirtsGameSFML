/** this file includes all the other files that will be used into the
  * ::game_manager.cc file and declares the functions of this file like
  * ::init_game() and ::get_state(), ::change_game_state() and ::update_game().
  */

#ifndef GAME_MANAGER
#define GAME_MANAGER

#include "debug.h"
#include "data_structure.h"
#include "menu.h"
#include "game_render.h"
#include "game_over.h"
#include "controls_and_sounds.h"

void init_game();
gameState get_state();
void change_game_state(gameState s);
void update_game(sf::RenderWindow &window);

#endif
