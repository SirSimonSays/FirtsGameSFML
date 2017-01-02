/** in this files there are the implementation of the functions of the ::game_over.h
  * file like ::(), ::().
  */

#include "game_over.h"

static sf::Text text1;

void update_game_over(sf::RenderWindow &window){
    window.setActive(false);

    text1.setFont(font);
    text1.setColor(sf::Color::Red);
    text1.setString("GAME OVER!");
    text1.setPosition(sf::Vector2f((DEFAULT_X / 2) - 150, (DEFAULT_Y / 2) - DIM));
    text1.setCharacterSize(DIM);

    window.draw(text1);
    window.display();

}
