/** in this files there are the implementation of the functions of the ::game_render.h
  * file like ::init_render(), ::random_platform(), ::update_render() and ::move_player().
  */

#include "game_render.h"

/** data structure for detect a coordinate on the screen.*/
struct point{
    int x,y;
};

/** ::resume_flag is used to checks if the game is already starts or not.
  * false = NOT START, true = ALREADY START.
  * ::game_over is used to checks if the user is playing or the he has lost.
  * false = PLAY, true = LOST.
  * ::pl_direction is used to stores the direction of the player.
  * false = RIGHT, true = LEFT.
  */
bool resume_flag, game_over, pl_direction;
player_state pl_state;

/** declaration of the three main image of the game.
  * ::random_arr stores random position to draw platforms with random position
  * on the screen.
  */
static sf::Texture tPlayer, tPlatform, tBackground;
static sf::Sprite sPlayer, sPlatform, sBackground;
static point random_arr[PLATFORMS_NUMBER];
static point player_position;
static float dx, dy;


void init_render(){

    /**< charge the player image and set the initial position.*/
    if(!tPlayer.loadFromFile("../media/sPlayer.png"))
        DEB("errore nel caricare l'immmagine del personaggio");

    dx = 0;
    dy = 0;
    player_position.x = DEFAULT_X / 2;
    player_position.y = 20;
    pl_state = FLY;
    pl_direction = false;
    sPlayer.setTexture(tPlayer);
    sPlayer.setPosition(player_position.x, player_position.y);
    animation(pl_state, pl_direction);


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

    resume_flag = false;
    game_over = false;
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
    resume_flag = true;
    window.clear();
    window.draw(sBackground);

    /** the gravity acceleration*/
    dy += 0.2;
    player_position.y += dy;
    if(player_position.y > DEFAULT_Y - PLAYER_DIMENSION){
        animation(DEATH, pl_direction);
        game_over = true;
        dy = 0;
    }
    collision();

    sPlayer.setPosition(player_position.x, player_position.y);
    window.draw(sPlayer);

    for(int i = 0; i < PLATFORMS_NUMBER; i++){
        sPlatform.setPosition(random_arr[i].x, random_arr[i].y);
        window.draw(sPlatform);
    }

    window.display();
}

/** function that allows to move the player left or right. It also checks if
  * the player goes out of the window.
  */
void move_player(bool b){
    if(b && player_position.x > 3){
        pl_direction = b;
        animation(pl_state, pl_direction);
        player_position.x -= 6;
    }else{
        if(player_position.x < DEFAULT_X - PLAYER_DIMENSION){
            pl_direction = false;
            animation(pl_state, pl_direction);
            player_position.x += 6;
        }
    }
}

void animation(player_state p, bool direction){
    if(!direction){
        switch(p){
          case RUN:
              sPlayer.setTextureRect(sf::IntRect(0, 0, PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          case JUMP:
              sPlayer.setTextureRect(sf::IntRect(0, 40, PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          case FLY:
              sPlayer.setTextureRect(sf::IntRect(0, 80, PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          case DEATH:
              sPlayer.setTextureRect(sf::IntRect(0, 120, PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          default:
              break;
        }
    }else{
          switch(p){
          case RUN:
              sPlayer.setTextureRect(sf::IntRect(PLAYER_DIMENSION, 0, -PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          case JUMP:
              sPlayer.setTextureRect(sf::IntRect(PLAYER_DIMENSION, 40, -PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          case FLY:
              sPlayer.setTextureRect(sf::IntRect(PLAYER_DIMENSION, 80, -PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          case DEATH:
              sPlayer.setTextureRect(sf::IntRect(0, 120, PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          default:
              break;
        }
    }

}

/** this function checks if the player collides with every platforms. The
  * position of the platforms are stored into the ::random_arr.
  */
void collision(){
    for(int i = 0; i < PLATFORMS_NUMBER; i++){
        if(sPlayer.getGlobalBounds().intersects(sf::FloatRect(random_arr[i].x, random_arr[i].y, PLATFORM_DIMENSION_X, PLATFORM_DIMENSION_Y))){
            animation(RUN, pl_direction);
            dy = -10;
        }
    }
}
