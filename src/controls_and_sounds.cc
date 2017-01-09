/** in this files there are the implementation of the functions of the ::controls_and_sounds.h
  * file like ::init_music(), ::update_music(), ::switch_music(), ::init_controls()
  * and ::view_controls().
  */

#include "controls_and_sounds.h"

/** flag variable to store the state of the music, if it's turned on or off*/
bool music_flag;

/** the texture and the sprite for the controls image and also the music for the
  * menu and the game.
  */
static sf::Texture tControls;
static sf::Sprite sControls;
static sf::Music musicMenu, musicGame;

/** function that opens the two files for playing the music. It also sets the
  * ::music_flag to true and starts the music depending on the state of the game.
  */
void init_music(){

    if(!musicMenu.openFromFile("../media/MartyGotsAPlan.ogg"))
        DEB("error loading menu music");

    if(!musicGame.openFromFile("../media/Reformat.ogg"))
        DEB("error loading game music");

    music_flag = true;
    musicMenu.setLoop(true);
    musicGame.setLoop(true);
    update_music(get_state());
}

/** it changes the music depending on the ::gameState and the ::music_flag.
  * music.getStatus = Get the current status of the stream (stopped, paused, playing)
  */
void update_music(gameState state){
    if(music_flag){
        switch(state){
          case PLAY:
              musicGame.play();
              musicMenu.pause();
              break;
          //case OVER:
          default:
              musicGame.pause();
              musicMenu.play();
              break;
        }
    }
}

/** this function is used to switch on and off the music from the options_menu.
  * It controls if the ::music_flag is true and it stops the music otherwise it
  * turns it on and sets the ::music_flag to true.
  */
void switch_music(){
    if(music_flag){
        musicMenu.pause();
        music_flag = false;
    }else{
        musicMenu.play();
        music_flag = true;
    }
}

/** it loads the image, sets the parameters of the sprite like position and
  * selects the rectangle of the sprite.
  */
void init_controls(){
    if(!tControls.loadFromFile("../media/sControl.jpg"))
        DEB("error loading controls image");

    sControls.setTexture(tControls);
    sControls.setTextureRect(sf::IntRect(0, 0, DEFAULT_X, DEFAULT_Y));
    sControls.setPosition(DEFAULT_X / 3 - 100, DEFAULT_Y / 3);

}

/** it cleans the screen and draws the ::sControls sprite.*/
void view_controls(sf::RenderWindow &window){
    window.clear();
    window.draw(sControls);
    window.display();
}
