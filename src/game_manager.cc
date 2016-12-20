/** in this files there are the implementation of the functions of the ::game_manager.h
  * file like ::init_game(), ::get_state(), ::change_state() and ::update_game().
  */

#include "game_manager.h"

static gameState state;

/** function to setup all the variables to make the whole program works properly.
  * It calls all the other init_* functions.
  */
void init_game(){
    srand(time(NULL));
    state = MENU;
    init_menu();
    init_render();
}

/**< it returns the value of the state variables.*/
gameState get_state(){
    return state;
}

/**< it changes the value of state with the parameter s.*/
void change_state(gameState s){
    state = s;
}

/** this function updates the whole game depending on the state of it. It uses a
  * switch element to select the different things to do according on the state.
  */
void update_game(sf::RenderWindow &window){
    switch (state){
      case PLAY:
          DEB("play");
          break;
      case MENU:
          update_menu(window);
          break;
      case OPTION:
          update_option_menu(window);
          break;
      default:
          break;
    }
}
