# this file is used to compile the whole program from terminal and also for
# other additional features like make ::dependencies, ::clean and ::cleanall
# either from terminal. This particular ::Makefile uses some variable to make
# short the whole file and minimize the code lines.

OBJS = data_structure.o menu.o main.o
EXNAME = exe
CXXFLAGS = -c -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

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
