/** @file
  * file that includes the main code for the play of the game.
  * In this files there are the implementation of the functions of the ::game_render.h
  * file like ::init_render(), ::random_platform(), ::update_render() and ::move_player(),
  * ::animation(), ::glide_player(), ::collision(), ::scroll_platforms().
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
static float dy;

/** declaration of the glide sound.*/
static sf::SoundBuffer buffer_glide;
static sf::Sound sound_glide;

/** clock variable to scan time to update the position of the platforms.*/
static sf::Clock scrolling_clock;

/** ::init_render is uses to set at his initial value all the variables of this
  * file to start to work properly. It also charges all the images and set the
  * sprites.
  */
void init_render(){

    /** charge the player image and set the initial position.*/
    if(!tPlayer.loadFromFile("../media/sPlayer.png"))
        DEB("error loading player image");

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
        DEB("error loading background image");

    sBackground.setTexture(tBackground);
    sBackground.setTextureRect(sf::IntRect(0, 0, DEFAULT_X, DEFAULT_Y));

    /** charge the platform image.*/
    if(!tPlatform.loadFromFile("../media/sPlatform.png"))
        DEB("error loading platform image");

    sPlatform.setTexture(tPlatform);
    random_platform();

    if(!buffer_glide.loadFromFile("../media/sound_glide.ogg"))
        DEB("error loading glide sound");

    sound_glide.setBuffer(buffer_glide);

    resume_flag = false;
    init_score();
}

/** ::random_platform() makes random number for the position of the platform
  * using the rand() function modulated by the width and the height of the window.
  */
void random_platform(){
    for(int i = 0; i < PLATFORMS_NUMBER; i++){
        random_arr[i].x = rand() % DEFAULT_X;
        random_arr[i].y = rand() % DEFAULT_Y + 200;
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
    if(!collision())
        animation(FLY, pl_direction);

    /** let the background slide every 0.01 seconds*/
    if(scrolling_clock.getElapsedTime().asSeconds() > 0.01)
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
    if(get_state() == PLAY){
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
}

/** function that allows the player to plane/glide. It changes the animation and
  * it plays ::sound_glide. It works only if the ::pl_state is different from RUN.
  */
void glide_player(){
    if(get_state() == PLAY && pl_state != RUN){
        animation(JUMP, pl_direction);
        dy -= 2;
        sound_glide.play();
    }
}

/** checks if the direction is right or left and selects the right rectangle
  * multiplying the ::PLAYER_DIMENSION for the ::pl_state.
  */
void animation(player_state p, bool direction){
    pl_state = p;
    if(!direction)
          sPlayer.setTextureRect(sf::IntRect(0, PLAYER_DIMENSION * pl_state, PLAYER_DIMENSION, PLAYER_DIMENSION));
    else
          /** technic to flip the sprite*/
          sPlayer.setTextureRect(sf::IntRect(PLAYER_DIMENSION, PLAYER_DIMENSION * pl_state, -PLAYER_DIMENSION, PLAYER_DIMENSION));
}

/** this function checks if the player collides with the top and the bottom of
  * screen and also checks if the player collides with every platforms. The
  * position of the platforms are stored into the ::random_arr.
  */
bool collision(){
    /** checks if the player collides at the top or bottom.*/
    if(player_position.y > DEFAULT_Y - PLAYER_DIMENSION ||
       player_position.y < 0){
        animation(DEATH, pl_direction);
        dy = 0;
        resume_flag = false;
        change_game_state(OVER);
        return true;
    }

    /** checks if the player collides with the platforms.*/
    for(int i = 0; i < PLATFORMS_NUMBER; i++){
        if(sPlayer.getGlobalBounds().intersects(sf::FloatRect(random_arr[i].x, random_arr[i].y, PLATFORM_DIMENSION_X, PLATFORM_DIMENSION_Y))){
            animation(RUN, pl_direction);
            dy = -PLATFORMS_SPEED;
            update_score();
            return true;
        }
    }

    return false;
}

/** this function allows to scroll the platforms up while the player falls and
  * to randomize new platforms on the x axes.
  */
void scroll_platforms(){

      scrolling_clock.restart();
      for(int i = 0; i < PLATFORMS_NUMBER; i++){
          random_arr[i].y = random_arr[i].y - PLATFORMS_SPEED;
          if(random_arr[i].y < 0){
                random_arr[i].y = DEFAULT_Y;
                random_arr[i].x = rand() % DEFAULT_X;
          }
      }
}
