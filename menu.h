/** in this files there are the functions of the ::menu that is the first
  * window of the game where the player have to choose from the items (play,
  * options and exit).
  */

#ifndef MENU_H
#define MENU_H

#include "debug.h"
#include "data_structure.h"

const int items_number = 3;

void init_menu();
void show_menu(sf::RenderWindow &window);
void move_up();
void move_down();
int getPressedItem();

#endif
