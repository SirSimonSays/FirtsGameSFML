/** @file
  * this file charges the SFML library and sets the variables shared from the
  * other files because some functions of different files use the same variables.
  * It also includes ::debug.h because it's used in all the other file for
  * tracing the error.
  */

#ifndef DATA_STR_H
#define DATA_STR_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/** default values of the dimension of the game screen.*/
extern const int DEFAULT_X;
extern const int DEFAULT_Y;

/** font of the text of the game*/
extern sf::Font font;

/** possible state of the game.*/
enum gameState{PLAY, MENU, OPTION, CONTROL, OVER};

#endif
