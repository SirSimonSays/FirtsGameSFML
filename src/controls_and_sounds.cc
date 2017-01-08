/** in this files there are the implementation of the functions of the ::controls_and_sounds.h
  * file like ::init_music(), ::update_music(), ::switch_music(), ::init_controls()
  * and ::view_controls().
  */

#include "controls_and_sounds.h"

/** flag variable to store the state of the music, if it's power on or off*/
bool music_flag;

/** */
static sf::Texture tControls;
static sf::Sprite sControls;
static sf::Music musicMenu, musicGame;

/** */
void init_music(){

    if(!musicMenu.openFromFile("../media/MartyGotsAPlan.ogg"))
        DEB("error loading menu music");

    if(!musicGame.openFromFile("../media/Reformat.ogg"))
        DEB("error loading game music");

    music_flag = true;
    update_music(get_state());
}

/***/
void update_music(gameState state){
    if(music_flag){
        switch(state){
            case PLAY:
                musicGame.play();
                musicMenu.pause();
                break;
            case MENU:
                musicGame.pause();
                musicMenu.play();
                break;
            case OPTION:
                musicGame.pause();
                musicMenu.play();
                break;
            default:
                break;
        }
    }
}

/***/
void switch_music(){
    if(music_flag){
        musicMenu.pause();
        music_flag = false;
    }else{
        musicMenu.play();
        music_flag = true;
    }
}

/***/
void init_controls(){
    if(!tControls.loadFromFile("../media/sControl.jpg"))
        DEB("error loading controls image");

    sControls.setTexture(tControls);
    sControls.setTextureRect(sf::IntRect(0, 0, DEFAULT_X, DEFAULT_Y));
    sControls.setPosition(DEFAULT_X / 3 - 100, DEFAULT_Y / 3);

}

/***/
void view_controls(sf::RenderWindow &window){
    window.clear();
    window.draw(sControls);
    window.display();
}
