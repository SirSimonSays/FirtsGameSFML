/** in this files there are the functions of the ::menu that is the first
  * window of the game where the player have to choose from the items (play,
  * options and exit).
  */

#ifndef MENU_H
#define MENU_H

#include "debug.h"
#include "data_structure.h"
#include "game_render.h"

const int ITEMS_NUMBER = 3;
const int OPTION_ITEMS_NUMBER = 3;

void init_menu();
void update_menu(sf::RenderWindow &window);
void update_option_menu(sf::RenderWindow &window);
int get_pressed_item(enum gameState);
void move_down(enum gameState);
void move_up(enum gameState);

#endif
