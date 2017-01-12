Assumption:
    the documentation is in the doc folder and it is made by Doxygen therefore
    in the code there are all the comments. I usually write most of the comments
    in the *.cc files while in the *.h files there's only a shortly description
    of what they do.

Resources:
    Texture of the player:
        tsgk.captainn.net
        tsgk.captainn.net/?p=showsheets&t=cn&cn=18&sec=44 [Mario-Bros]
    Music for the menu and the game:
        incompetech.com/music/royalty-free/music.html
    Documentation of SFML: sfml-dev.org/tutorials/2.4/
        github.com/SFML/SFML/wiki
    Obviusly google for some sprite and all the question I had:
        google.com

How to play:
    First you have to install SFML libraries by "sudo apt-get install libsfml-dev" command.
    Then you can choose from one of this commands to write into the /src folder.
    Compile:
        make
    Clean:
        make clean
        make cleanall
    Dependencies:
        make dependencies
    Play:
        ./exe

Bug:
    the biggest bug is on the score's assignment because it counts the number of platforms
    with whom the player collides but a collision with a platform doesn't correspond to a single collision;
    it depend's on how many cycles there are while you are on the platform.
