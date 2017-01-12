/** @file
  * declarations of variables and functions of game_over file.
  * this file includes all the other files that will be used into the
  * ::game_over.cc file and declares the functions of this file like
  * ::update_game_over() and ::().
  */

#ifndef GAME_OVER
#define GAME_OVER

#include "score_manager.h"

/** size for the "game over!" and "congratulations, new record" messages.*/
const int DIM = 50;

void update_game_over(sf::RenderWindow &window);

#endif
