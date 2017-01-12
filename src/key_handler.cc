/** @file
  * file that manages the input from keyboard.
  * In this files there are the implementation of the functions of the ::key_handler.h
  * file like ::key_press(), ::key_release().
  */

#include "key_handler.h"

/** this function allows to recognize the key pressed by the user and do something
  * according to the pressed key.
  */
void key_press(sf::RenderWindow &window, sf::Event &event){

    switch(event.key.code){
      case sf::Keyboard::Up:
          move_up(get_state());
          break;
      case sf::Keyboard::Down:
          move_down(get_state());
          break;
      case sf::Keyboard::Left:
          move_player(true);
          break;
      case sf::Keyboard::Right:
          move_player(false);
          break;
      case sf::Keyboard::LShift:
          glide_player();
          break;
      case sf::Keyboard::Escape:
          if(get_state() == CONTROL)
              change_game_state(OPTION);
          else
              change_game_state(MENU);
          break;
      case sf::Keyboard::Return:
          switch(get_pressed_item(get_state())){
            /** value returned from the main_menu.*/
            case 0:
                change_game_state(PLAY);
                break;
            case 1:
                change_game_state(OPTION);
                break;
            case 2:
                window.close();
                break;
            /** value returned from the options_menu.*/
            case 3:
                switch_music();
                break;
            case 4:
                change_game_state(CONTROL);
                break;
            case 5:
                change_game_state(MENU);
                break;
            default:
                break;
          }
          break;
      default:
          break;
    }
}

/**
  *
  */
void key_release(sf::RenderWindow &window, sf::Event &event){


}
