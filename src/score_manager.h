/** @file
  * declarations of variables and functions of score_manager file.
  * this file includes all the other files that will be used into the
  * ::score_manager.cc file and declares the functions of this file like
  * ::init_score(), ::update_score(), ::view_score(), ::getBestScore() and
  * ::set_best_score().
  */

#ifndef SCORE_MANAGER
#define SCORE_MANAGER

#include "debug.h"
#include "data_structure.h"

/** the name of the file where the score is store.*/
const char FILE_NAME[] = "score.txt";
/** the start value of the score variables at the start of the game.*/
const int NO_SCORE = -1 ;

void init_score();
void update_score();
sf::Text view_score();
int getBestScore();
bool set_best_score();

#endif
