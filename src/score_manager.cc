/** @file
  * file that handles the score of the game.
  * In this files there are the implementation of the functions of the ::score_manager.h
  * file like ::init_score(), ::update_score(), ::getBestScore() and ::set_best_score().
  */

#include "score_manager.h"

/** current score of the player.*/
static int score;
/** buffer to read the score from file.*/
static string buffer;
/** unformatted output to write into the file ::score.txt*/
static ofstream file_out;
/** unformatted input to read from file ::score.txt*/
static ifstream file_in;
/** text variable to view on the screen the current score.*/
static sf::Text score_text;

/** set the deafult value of score variable.*/
void init_score(){
    score = NO_SCORE;

    score_text.setFont(font);
    score_text.setColor(sf::Color::Red);
    score_text.setString("SCORE: 0");
    score_text.setPosition(sf::Vector2f(DEFAULT_X - 300, 20));
}

/** increment the value of score.*/
void update_score(){
    score ++;
}

/** it updates the text to print on the screen and it returns the score_text variable
  * that will be uses into the ::game_render file.
  */
sf::Text view_score(){
    score_text.setString("SCORE: " + to_string(score));
    return score_text;
}

/** it returns the value write on file score.txt */
int get_best_score(){
    file_in.open(FILE_NAME);
    if(!file_in){
        DEB("error while opening file_in");
        return -1;
    }

    /** read the whole character into the ::FILE_NAME*/
  	while(file_in>>buffer) ;

    file_in.close();

    /** stoi is the opposite of to_string() and it converts the strings into ints*/ 
    return stoi(buffer);
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
