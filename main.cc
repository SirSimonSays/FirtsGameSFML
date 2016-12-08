/** in this files there are the implementation of the functions of the ::main.h
  * file like ::setup() and ::main().
  */

#include "main.h"

/**<function to setup all the variables to make the whole program works properly.*/
void setup(){

}

/** the main function is the first executed after the launch of the program.
  * It returns 0 to says the program works great or an integer different from 0
  * to report an error.
  */
int main(){
    sf::RenderWindow window(sf::VideoMode(default_x, default_y), "Let's start");
    window.setFramerateLimit(23);
    sf::Event event;

    while(window.isOpen()){
        while(window.pollEvent(event)){

            switch (event.type){
                case sf::Event::KeyReleased:
                    switch (event.key.code){
                      case sf::Keyboard::Up:
                          move_up();
                          break;
                      case sf::Keyboard::Down:
                          move_down();
                          break;
                      default:
                          break;
                    }
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        window.clear();
        show_menu(window);
        window.display();
    }

    return 0;
}
