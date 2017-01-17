# this file is used to compile the whole program from terminal and also for
# other additional features like make ::dependencies, ::clean and ::cleanall
# either from terminal. This particular ::Makefile uses some variable to make
# short the whole file and minimize the code lines.

OBJS = data_structure.o menu.o game_manager.o game_render.o game_over.o key_handler.o controls_and_sounds.o score_manager.o main.o
EXNAME = exe
CXXFLAGS = -c -Wall -std=c++0x 
LDFLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

compile: $(OBJS)
	g++ -o $(EXNAME) $(LDFLAGS) $(OBJS)

-include depend.txt

.PHONY: dependencies clean cleanall

dependencies:
	g++ -MM *.cc > depend.txt

clean:
	rm -f *.o *~

cleanall: clean
	rm -f $(EXNAME)
