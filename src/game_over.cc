/** in this files there are the implementation of the functions of the ::game_over.h
  * file like ::update_game_over() and ::().
  */

#include "game_over.h"

static sf::Text text1;

/** it implements the death's state of the game. the setActive function freeze
  * the game then it draws the "GAME OVER" string on the screen and it changes the
  * animation of the player.
  */
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
