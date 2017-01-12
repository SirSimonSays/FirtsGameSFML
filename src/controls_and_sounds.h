/** @file
  * declarations of variables and functions of controls_and_sounds file.
  * this file includes all the other files that will be used into the
  * ::controls_and_sounds.cc file and declares the functions of this file like
  * ::init_music(), ::update_music(), ::init_controls() and ::view_controls().
  */

#ifndef CONTROLS_AND_SOUNDS
#define CONTROLS_AND_SOUNDS

#include "debug.h"
#include "data_structure.h"
#include "game_manager.h"

extern bool music_flag;

void init_music();
void update_music(gameState state);
void switch_music();
void init_controls();
void view_controls(sf::RenderWindow &window);

#endif
