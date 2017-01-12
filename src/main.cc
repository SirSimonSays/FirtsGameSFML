/** @file
  * file that holds the main functions of the game.
  * In this files there are the implementation of the functions of the ::main.h
  * file like ::setup() and ::main().
  */

#include "main.h"

/** the main function is the first executed after the launch of the program.
  * It returns 0 to says the program works great or an integer different from 0
  * to report an error. It holds the main loop of the game.
  */
int main(){

    sf::RenderWindow window(sf::VideoMode(DEFAULT_X, DEFAULT_Y), "FF - FreeFall");
    window.setFramerateLimit(FPS);
    sf::Time t = sf::seconds(0.01);
    sf::Event event;

    init_game();

    while(window.isOpen()){
        while(window.pollEvent(event)){
            switch(event.type){
              case sf::Event::KeyPressed:
                  key_press(window, event);
                  break;
              case sf::Event::KeyReleased:
                  key_release(window, event);
                  break;
              case sf::Event::Closed:
                  window.close();
                  break;
              default:
                  break;
            }
        }
        update_game(window);
        sf::sleep(t);
    }

    return 0;
}
