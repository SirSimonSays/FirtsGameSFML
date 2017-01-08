/** in this files there are the implementation of the functions of the ::menu.h
  * file like ::show_menu(), ::move_up(), ::move_down().
  */

#include "menu.h"

/** into the ::font variable is stored the font of the text that the user can sees
  * in the menu. The ::menu[] array holds the items of both main_menu and
  * options_menu. It's a sf::Text type and consist of an array of strings.
  * Indeed into the two variables ::selected_menu_item and ::selected_options_item
  * are stored the index of the array where the user is on.
  */

static sf::Text menu[ITEMS_NUMBER + OPTION_ITEMS_NUMBER];
static int selected_menu_item = 0;
static int selected_options_item = ITEMS_NUMBER;

static sf::Texture tMenu; /**< .*/
static sf::Sprite sMenu; /**< .*/

/** ::init_menu is uses to set the background image of the menu, the font of the
  * menu text and to charges the array ::menu[] of the necessary element.
  */
void init_menu(){

    if(!tMenu.loadFromFile("../media/sMenu.png"))
        DEB("errore nel caricare l'immmagine");
    sMenu.setTexture(tMenu);

    if(!font.loadFromFile("../media/AlexisGrunge.ttf"))
        DEB("Errore nel caricamento del font");

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f( DEFAULT_X / 2 - 40, (DEFAULT_Y / (ITEMS_NUMBER + 1)) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f( DEFAULT_X / 2 - 40, (DEFAULT_Y / (ITEMS_NUMBER + 1)) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f( DEFAULT_X / 2 - 40, (DEFAULT_Y / (ITEMS_NUMBER + 1)) * 3));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::Red);
    menu[3].setString("Volume: ON");
    menu[3].setPosition(sf::Vector2f( DEFAULT_X / 2 - 40, (DEFAULT_Y / (OPTION_ITEMS_NUMBER + 1)) * 1));

    menu[4].setFont(font);
    menu[4].setColor(sf::Color::White);
    menu[4].setString("Controls");
    menu[4].setPosition(sf::Vector2f( DEFAULT_X / 2 - 40, (DEFAULT_Y / (OPTION_ITEMS_NUMBER + 1)) * 2));

    menu[5].setFont(font);
    menu[5].setColor(sf::Color::White);
    menu[5].setString("Back to menu");
    menu[5].setPosition(sf::Vector2f( DEFAULT_X / 2 - 40, (DEFAULT_Y / (OPTION_ITEMS_NUMBER + 1)) * 3));
}

/** this functions allows to see the background image and the three items: play,
  * options and exit. This three elements are members of the main menu.
  */
void update_menu(sf::RenderWindow &window){

    /** condition to check if the game is already started and change the label of
      * the menu from play to resume.
      */
    if(resume_flag)
        menu[0].setString("Resume");
    else
        menu[0].setString("Play");

    window.clear();
    window.draw(sMenu);

    for(int i = 0; i < ITEMS_NUMBER; i++){
        window.draw(menu[i]);
    }

    window.display();
}

/** this functions allows to see the background image and the three items: volume,
  * controls and back to menu. This three elements are members of the options menu.
  */
void update_option_menu(sf::RenderWindow &window){

    /** condition to check if the volume is on or off and change the label of the
      * option menu from volume: on to volume: off
      */
    if(!music_flag)
        menu[3].setString("Volume: OFF");
    else
        menu[3].setString("Volume: ON");

    window.clear();
    window.draw(sMenu);

    for(int i = ITEMS_NUMBER; i < ITEMS_NUMBER + OPTION_ITEMS_NUMBER; i++){
        window.draw(menu[i]);
    }

    window.display();
}


/** this function return the current selected_item of the menu. The if condition
  * allows to split the menu_item from the options_item.
  */
int get_pressed_item(gameState s){
    if(s == MENU)
        return selected_menu_item;
    else
        return selected_options_item;
}

/** this function allows the user to move up on the three items, if the items
  * end then the cycle restarts from the last like a circle. This method is used
  * both from main_menu and options_menu, so it has the gameState parameter to
  * split the two menu.
  */
void move_up(gameState s){
    if(s == MENU){
        /**< portion of the main_menu*/
        if(selected_menu_item - 1 >= 0){
            menu[selected_menu_item].setColor(sf::Color::White);
            selected_menu_item--;
            menu[selected_menu_item].setColor(sf::Color::Red);
        }else{
            menu[selected_menu_item].setColor(sf::Color::White);
            selected_menu_item = ITEMS_NUMBER - 1;
            menu[selected_menu_item].setColor(sf::Color::Red);
        }
    }else{
        /**< portion of the options_menu*/
        if(selected_options_item - 1 >= ITEMS_NUMBER){
            menu[selected_options_item].setColor(sf::Color::White);
            selected_options_item--;
            menu[selected_options_item].setColor(sf::Color::Red);
        }else{
            menu[selected_options_item].setColor(sf::Color::White);
            selected_options_item = ITEMS_NUMBER + OPTION_ITEMS_NUMBER - 1;
            menu[selected_options_item].setColor(sf::Color::Red);
        }
    }
}

/** this function allows the user to move down on the three items, if the items
  * end then the cycle restarts from the first like a circle. This method is used
  * both from main_menu and options_menu, so it has the gameState parameter to
  * split the two menu.
  */
void move_down(gameState s){
    if(s == MENU){
        /**< portion of the main_menu*/
        if(selected_menu_item + 1 < ITEMS_NUMBER){
            menu[selected_menu_item].setColor(sf::Color::White);
            selected_menu_item++;
            menu[selected_menu_item].setColor(sf::Color::Red);
        }else{
            menu[selected_menu_item].setColor(sf::Color::White);
            selected_menu_item = 0;
            menu[selected_menu_item].setColor(sf::Color::Red);
        }
    }else{
        /**< portion of the options_menu*/
        if(selected_options_item + 1 < ITEMS_NUMBER + OPTION_ITEMS_NUMBER){
            menu[selected_options_item].setColor(sf::Color::White);
            selected_options_item++;
            menu[selected_options_item].setColor(sf::Color::Red);
        }else{
            menu[selected_options_item].setColor(sf::Color::White);
            selected_options_item = ITEMS_NUMBER;
            menu[selected_options_item].setColor(sf::Color::Red);
        }
    }
}
