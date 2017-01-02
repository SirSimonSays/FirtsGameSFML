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
  * ::pl_direction is used to stores the direction of the player.
  * false = RIGHT, true = LEFT.
  */
bool resume_flag, pl_direction;
player_state pl_state;

/** declaration of the three main image of the game.
  * ::random_arr stores random position to draw platforms with random position
  * on the screen. ::player position stores the position of the player to move
  * it. The two variables ::dx and ::dy are the changing time, like a little
  * lapse of time.
  */
static sf::Texture tPlayer, tPlatform, tBackground;
static sf::Sprite sPlayer, sPlatform, sBackground;
static point random_arr[PLATFORMS_NUMBER];
static point player_position;
static float dx, dy;

/***/
static sf::Clock clock1;

/** ::init_render is uses to set at his initial value all the variables of this
  * file to start to work properly. It also charges all the images and set the
  * sprites.
  */
void init_render(){

/** charge the player image and set the initial position.*/
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


/** charge the background image.*/
    if(!tBackground.loadFromFile("../media/sBackground.png"))
        DEB("errore nel caricare l'immmagine dello sfondo");

    sBackground.setTexture(tBackground);
    sBackground.setTextureRect(sf::IntRect(0, 0, DEFAULT_X, DEFAULT_Y));

/** charge the platform image.*/
    if(!tPlatform.loadFromFile("../media/sPlatform.png"))
        DEB("errore nel caricare l'immmagine delle piattaforme");

    sPlatform.setTexture(tPlatform);
    random_platform();

    resume_flag = false;
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

/** ::update_render is the main function of this file because it's called every
  * time that the player is moved and makes possible scrolling the backgorund.
  * It also implements the gravity.
  */
void update_render(sf::RenderWindow &window){
    if(!resume_flag)
        init_render();

    resume_flag = true;
    window.clear();
    window.draw(sBackground);

/** the gravity acceleration*/
    dy += 0.2;
    player_position.y += dy;
    collision();

/** let the background slide every 0.01 seconds*/
    if(clock1.getElapsedTime().asSeconds() > 0.01)
        scroll_platforms();

    sPlayer.setPosition(player_position.x, player_position.y);
    window.draw(sPlayer);

/** cycle to draw the ten platforms randomized in the ::random_platform function.*/
    for(int i = 0; i < PLATFORMS_NUMBER; i++){
        sPlatform.setPosition(random_arr[i].x, random_arr[i].y);
        window.draw(sPlatform);
    }

    window.display();
}

/** function that allows to move the player left or right. It also checks if
  * the player goes out of the window.
  */
void move_player(bool dir){
    if(dir && player_position.x > 3){
        pl_direction = dir;
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

/**
  *
  */
void animation(player_state p, bool direction){
/**check if the direction is right or left and switch on the state of the player.*/
    if(!direction){
        switch(p){
          case RUN:
              sPlayer.setTextureRect(sf::IntRect(0, 0, PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          case JUMP:
              sPlayer.setTextureRect(sf::IntRect(0, PLAYER_DIMENSION, PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          case FLY:
              sPlayer.setTextureRect(sf::IntRect(0, PLAYER_DIMENSION * 2, PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          case DEATH:
              sPlayer.setTextureRect(sf::IntRect(0, PLAYER_DIMENSION * 3, PLAYER_DIMENSION, PLAYER_DIMENSION));
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
              sPlayer.setTextureRect(sf::IntRect(PLAYER_DIMENSION, PLAYER_DIMENSION, -PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          case FLY:
              sPlayer.setTextureRect(sf::IntRect(PLAYER_DIMENSION, PLAYER_DIMENSION * 2, -PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          case DEATH:
              sPlayer.setTextureRect(sf::IntRect(PLAYER_DIMENSION, PLAYER_DIMENSION * 3, -PLAYER_DIMENSION, PLAYER_DIMENSION));
              break;
          default:
              break;
        }
    }

}

/** this function checks if the player collides with the top and the bottom of
  * screen and also checks if the player collides with every platforms. The
  * position of the platforms are stored into the ::random_arr.
  */
void collision(){
/**check if the player collides at the top or bottom.*/
    if(player_position.y > DEFAULT_Y - PLAYER_DIMENSION ||
       player_position.y < 0){
        animation(DEATH, pl_direction);
        dy = 0;
        resume_flag = false;
        change_state(OVER);
    }

/**check if the player collides with the platforms.*/
    for(int i = 0; i < PLATFORMS_NUMBER; i++){
        if(sPlayer.getGlobalBounds().intersects(sf::FloatRect(random_arr[i].x, random_arr[i].y, PLATFORM_DIMENSION_X, PLATFORM_DIMENSION_Y))){
            animation(RUN, pl_direction);
            dy = -PLATFORMS_SPEED;
        }
    }
}

/** this function allows to scroll the platforms up while the player falls and
  * to randomize new platforms on the x axes.
  */
void scroll_platforms(){

      clock1.restart();
      for(int i = 0; i < PLATFORMS_NUMBER; i++){
          random_arr[i].y = random_arr[i].y - PLATFORMS_SPEED;
          if(random_arr[i].y < 0){
                random_arr[i].y = DEFAULT_Y;
                random_arr[i].x = rand() % DEFAULT_X;
          }
      }
}
