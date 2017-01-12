/** this file includes all the other files that will be used into the
  * ::key_handler.cc file and declares the functions of this file like
  * ::key_press() and ::key_release().
  */

#ifndef KEY_HANDLER
#define KEY_HANDLER

#include "game_manager.h"

/**< max number of keys memorizable.*/
//static const int MAX_KEY = 3;

/**< number of keys pressed.*/
//static int numPress;

void key_press(sf::RenderWindow &window, sf::Event &event);
void key_release(sf::RenderWindow &window, sf::Event &event);

#endif
