/** in this files there are the implementation of the functions of the ::game_render.h
  * file like ::init_render(), ::random_platform(), ::update_render() and ::move_player().
  */

#include "game_render.h"

/** data structure for detect a coordinate on the screen.*/
struct point{
    int x,y;
};

/** declaration of the three main image of the game.
  * ::random_arr stores random position to draw platforms with rando position
  * on the screen.
  */
static sf::Texture tPlayer, tPlatform, tBackground;
static sf::Sprite sPlayer, sPlatform, sBackground;
static point random_arr[PLATFORMS_NUMBER];
static point player_position;

void init_render(){

    /**< charge the player image and set the initial position.*/
    if(!tPlayer.loadFromFile("../media/sPlayer.png"))
        DEB("errore nel caricare l'immmagine del personaggio");

    player_position.x = DEFAULT_X / 2;
    player_position.y = 20;
    sPlayer.setTexture(tPlayer);
    sPlayer.setPosition(player_position.x, player_position.y);
    sPlayer.setTextureRect(sf::IntRect(200, 160, PLAYER_DIMENSION, PLAYER_DIMENSION));

    /**< charge the background image.*/
    if(!tBackground.loadFromFile("../media/sBackground.png"))
        DEB("errore nel caricare l'immmagine dello sfondo");

    sBackground.setTexture(tBackground);
    sBackground.setTextureRect(sf::IntRect(0, 0, DEFAULT_X, DEFAULT_Y));

    /**< charge the platform image.*/
    if(!tPlatform.loadFromFile("../media/sPlatform.png"))
        DEB("errore nel caricare l'immmagine delle piattaforme");

    sPlatform.setTexture(tPlatform);
    random_platform();
}

/** ::random_platform() makes random number for the position of the platform
  * using the rand() function modulated by the width and the height of the window.
  */
void random_platform(){
    for(int i = 0; i < PLATFORMS_NUMBER; i++){
        random_arr[i].x = rand() % DEFAULT_X;
        random_arr[i].y = rand() % DEFAULT_Y;
    }
}

/**
  *
  */
void update_render(sf::RenderWindow &window){
    window.clear();
    window.draw(sBackground);
    window.draw(sPlayer);

    for(int i = 0; i < PLATFORMS_NUMBER; i++){
        sPlatform.setPosition(random_arr[i].x, random_arr[i].y);
        window.draw(sPlatform);
    }

    window.display();
}

/**
  *
  */
void move_player(char c){
    // if(c == 'l'){
    //     sPlayer.setPosition();
    // }else{
    //     sPlayer.setPosition();
    // }

}
