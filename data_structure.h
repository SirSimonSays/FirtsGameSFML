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

extern const int default_x;
extern const int default_y;

#endif
