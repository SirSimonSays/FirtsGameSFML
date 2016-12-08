/** in this files there are the implementation of the functions of the ::main.h
  * file like ::setup() and ::main().
  */

#include "main.h"

static sf::RenderWindow w1(sf::VideoMode(default_x, default_y), "Let's start");
static sf::Event event;

/**<function to setup all the variables to make the whole program works properly.*/
void setup(){
    init_menu();
    //w1.setFramerateLimit(23);
}

/** the main function is the first executed after the launch of the program.
  * It returns 0 to says the program works great or an integer different from 0
  * to report an error.
  */
int main(){
    setup();

    while(w1.isOpen()){
        while(w1.pollEvent(event)){

            switch (event.type){
                case sf::Event::KeyReleased:
                    switch (event.key.code){
                      case sf::Keyboard::Up:
                          move_up();
                          break;
                      case sf::Keyboard::Down:
                          move_down();
                          break;
                      case sf::Keyboard::Return:
                          if(getPressedItem() == 0){
                              DEB("play");
                          }else if(getPressedItem() == 1){
                              DEB("options");
                          }else if(getPressedItem() == 2)
                              w1.close();
                          break;
                      default:
                          break;
                    }
                    break;

                case sf::Event::Closed:
                    w1.close();
                    break;
                default:
                    break;
            }
        }

        w1.clear();
        show_menu(w1);
        w1.display();
    }

    return 0;
}
