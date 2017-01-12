/** @file
  * file that handles the score of the game.
  * In this files there are the implementation of the functions of the ::score_manager.h
  * file like ::init_score(), ::update_score(), ::getBestScore() and ::set_best_score().
  */

#include "score_manager.h"

/** current score of the player*/
static int score;
/** buffer to read the score from file*/
static char buffer;
/** unformatted output to write into the file ::score.txt*/
static ofstream file_out;
/** unformatted input to read from file ::score.txt*/
static ifstream file_in;

/** set the deafult value of score variable.*/
void init_score(){
    score = NO_SCORE;
}

/** inrement the value of score.*/
void update_score(){
    score ++;
}

/** it returns the value write on file score.txt */
int get_best_score(){
    file_in.open(FILE_NAME);
    if(!file_in){
        DEB("error while opening file_in");
        return -1;
    }
  	file_in>>buffer;
  	file_in.close();
    return (int)buffer;
}

/** it checks if the score write on the file is lower than the current score then
  * it overwrites the score on the file and sets it like the best.
  */
bool set_best_score(){
    if(get_best_score() < score){
        file_out.open(FILE_NAME);

        if(!file_out){
            DEB("error while opening file_out");
            return false;
        }

        file_out<<score;
        file_out.close();
        return true;
    }
    return false;
}
