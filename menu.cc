/** in this files there are the implementation of the functions of the ::menu.h
  * file like ::show_menu(), ::move_up(), ::move_down().
  */

#include "menu.h"

static sf::Font font;
static sf::Text menu[items_number];
static int selected_item = 0;

void init_menu(){

    if(!font.loadFromFile("AlexisGrunge.ttf"))
        DEB("Errore nel caricamento del font");

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f( default_x / 2 - 40, (default_y / (items_number + 1)) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f( default_x / 2 - 40, (default_y / (items_number + 1)) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f( default_x / 2 - 40, (default_y / (items_number + 1)) * 3));
}

/** this functions allows to show the main window, set his parameters and also
  * view the three items play, options and exit.
  */
void show_menu(sf::RenderWindow &window){

    for(int i = 0; i < items_number; i++){
        window.draw(menu[i]);
    }
}

/** this function allows the user to move up on the three items, if the items
  * end then the cycle restarts from the last like a circle.
  */
void move_up(){
    if(selected_item - 1 >= 0){
        menu[selected_item].setColor(sf::Color::White);
        selected_item--;
        menu[selected_item].setColor(sf::Color::Red);
    }else{
        menu[selected_item].setColor(sf::Color::White);
        selected_item = items_number - 1;
        menu[selected_item].setColor(sf::Color::Red);
    }
}

/** this function allows the user to move down on the three items, if the items
  * end then the cycle restarts from the first like a circle.
  */
void move_down(){
    if(selected_item + 1 < items_number){
        menu[selected_item].setColor(sf::Color::White);
        selected_item++;
        menu[selected_item].setColor(sf::Color::Red);
    }else{
        menu[selected_item].setColor(sf::Color::White);
        selected_item = 0;
        menu[selected_item].setColor(sf::Color::Red);
    }
}

int getPressedItem(){
    return selected_item;
}
