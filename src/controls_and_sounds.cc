/** in this files there are the implementation of the functions of the ::controls_and_sounds.h
  * file like ::init_music(), ::update_music(), ::switch_music(), ::init_controls()
  * and ::view_controls().
  */

#include "controls_and_sounds.h"

/** flag variable to store the state of the music, if it's turned on or off*/
bool music_flag;

/** the texture and the sprite for the controls image and also the music for the
  * menu the game and the game_over.
  */
static sf::Text flip_text;
static int i;
static sf::Texture tControls;
static sf::Sprite sControls;
static sf::Music musicMenu, musicGame, musicOver;

/** function that opens the three files for playing the music. It also sets the
  * ::music_flag to true and starts the music depending on the state of the game.
  */
void init_music(){

    if(!musicMenu.openFromFile("../media/musicMenu.ogg"))
        DEB("error loading menu music");

    if(!musicGame.openFromFile("../media/musicGame.ogg"))
        DEB("error loading game music");

    if(!musicOver.openFromFile("../media/musicOver.ogg"))
        DEB("error loading game music");

    music_flag = true;
    musicGame.setVolume(35);
    musicMenu.setLoop(true);
    musicGame.setLoop(true);

    update_music(get_state());
}

/** it changes the music depending on the ::gameState and the ::music_flag.
  * music.getStatus = Get the current status of the stream (stopped, paused, playing).
  * the playing of a music that is already playing will produce the restarting
  * of it and into the default case the if checks this problem.
  */
void update_music(gameState state){
    if(music_flag){
        switch(state){
          case PLAY:
              musicMenu.pause();
              musicGame.play();
              musicOver.stop();
              break;
          case OVER:
              musicMenu.pause();
              musicGame.stop();
              musicOver.play();
              break;
          default:
              if(musicMenu.getStatus() != 2){
                  musicMenu.play();
                  /** depending on the ::resume_flag it pauses or stops the ::musicGame*/
                  resume_flag ? musicGame.pause() : musicGame.stop();
                  musicOver.stop();
              }
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
    i = 0;
    flip_text.setFont(font);
    flip_text.setString("Press ESC to return to MENU");
    flip_text.setColor(sf::Color::White);
    flip_text.setCharacterSize(30);
    flip_text.setPosition(DEFAULT_X / 3, DEFAULT_Y - 150);


    if(!tControls.loadFromFile("../media/sControl.jpg"))
        DEB("error loading controls image");

    sControls.setTexture(tControls);
    sControls.setTextureRect(sf::IntRect(0, 0, DEFAULT_X, DEFAULT_Y));
    sControls.setPosition(DEFAULT_X / 3 - 100, DEFAULT_Y / 4);

}

/** it cleans the screen and draws the ::sControls sprite.*/
void view_controls(sf::RenderWindow &window){
    window.clear();
    window.draw(sControls);

    /** simple way to make the text flashing on the screen to capture the attention
      * of the user. i variable starts from 0 and increments by one every cycle,
      * so the if condition checks whether the number is odd or even.
      */
    if(i % 2)
        window.draw(flip_text);
    i++;

    window.display();
    sf::sleep(sf::seconds(0.6));
}
