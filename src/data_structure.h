/** this file charges the SFML library and sets the variables shared from the
  * other files because some functions of different files use the same variables.
  * It also includes ::debug.h because it's used in all the other file for
  * tracing the error.
  */

#ifndef DATA_STR_H
#define DATA_STR_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

/**< default values of the dimension of the game screen.*/
extern const int DEFAULT_X;
extern const int DEFAULT_Y;

/**< possible state of the game.*/
enum gameState{PLAY, MENU, OPTION};

#endif
